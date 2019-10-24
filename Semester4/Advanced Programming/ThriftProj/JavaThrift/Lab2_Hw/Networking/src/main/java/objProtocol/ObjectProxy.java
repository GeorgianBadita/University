package objProtocol;

import domain.entities.Concert;
import domain.entities.DTOConcert;
import domain.entities.Ticket;
import domain.entities.User;
import service.IObserver;
import service.IServer;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.rmi.RemoteException;
import java.time.LocalDate;
import java.util.List;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

public class ObjectProxy implements IServer {

    private String host;
    private int port;

    private IObserver client;

    private ObjectOutputStream output;
    private ObjectInputStream input;
    private Socket connection;

    private BlockingQueue<IResponse> qResponses;
    private volatile  boolean finished;

    public ObjectProxy(String host, int port){
        this.host = host;
        this.port = port;

        qResponses = new LinkedBlockingQueue<IResponse>();
    }





    @Override
    public boolean validateLogIn(String userName, String pass, IObserver client) throws RemoteException {
        initializeConnection();
        User usr = new User(userName, pass);
        sendRequest(new SimpleRequest(RequestType.LOGIN, usr));
        SimpleResponse response = (SimpleResponse)readResponse();
        if(response.getResponseType() == ResponseType.OK){
            this.client = client;
            return true;
        }
        if(response.getResponseType() == ResponseType.ERROR){
            closeConnection();
            return false;
        }

        return false;
    }

    @Override
    public Concert findConcert(Integer concert) throws RemoteException {

        sendRequest(new SimpleRequest(RequestType.FIND, concert));
        SimpleResponse response = (SimpleResponse) readResponse();
        if(response.getResponseType() == ResponseType.ERROR){
            return null;
        }
        return (Concert)response.getData();
    }

    @Override
    public Ticket sellTicket(Integer concert, String clientName, LocalDate now, Integer numSeats) throws RemoteException {

        Object[] lst = new Object[4];
        lst[0] = concert;
        lst[1] = clientName;
        lst[2] = now;
        lst[3] = numSeats;
        sendRequest(new ComplexRequest(RequestType.SELL, lst));
        SimpleResponse response = (SimpleResponse)readResponse();
        if(response.getResponseType() == ResponseType.OK){
            return (Ticket)response.getData();
        }
        return null;
    }

    @Override
    public boolean canSellTicket(Integer concId, Integer numTickets) throws RemoteException {
        Object[] lst = new Object[2];
        lst[0] = concId;
        lst[1] = numTickets;
        sendRequest(new ComplexRequest(RequestType.CAN_SELL, lst));
        SimpleResponse response = (SimpleResponse) readResponse();
        return response.getResponseType() == ResponseType.OK;
    }

    @Override
    public List<DTOConcert> getConcertDtosByDate(LocalDate dateFilter) throws RemoteException {

        sendRequest(new SimpleRequest(RequestType.FILTER, dateFilter));
        SimpleResponse response = (SimpleResponse) readResponse();

        if(response.getResponseType() == ResponseType.OK){
            return (List<DTOConcert>)response.getData();
        }
        return null;
    }

    @Override
    public List<DTOConcert> getConcertDtos() throws RemoteException {
        sendRequest(new SimpleRequest(RequestType.INIT));
        SimpleResponse response = (SimpleResponse) readResponse();
        if(response.getResponseType() == ResponseType.OK){
            return (List<DTOConcert>)response.getData();
        }
        return null;
    }

    @Override
    public Concert updateConcert(Concert conc) throws RemoteException {
        sendRequest(new SimpleRequest(RequestType.UPDATE_CONC, conc));
        SimpleResponse response = (SimpleResponse)readResponse();
        if(response.getResponseType() == ResponseType.OK){
            return (Concert)response.getData();
        }
        return null;

    }

    @Override
    public void notifyClients() throws RemoteException {
        sendRequest(new SimpleRequest(RequestType.UPDATE));
        SimpleResponse response = (SimpleResponse) readResponse();

    }


    public void sendRequest(IRequest request) throws RemoteException {
        try {
            output.writeObject(request);
            output.flush();
        } catch (IOException e) {
            throw new RemoteException("Error sending object " + e);
        }
    }

    private IResponse readResponse() throws RemoteException {
        IResponse response = null;
        try{
            response = qResponses.take();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        return response;
    }

    private void closeConnection(){
        finished = true;
        try{
            input.close();
            output.close();
            connection.close();
            client = null;
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void initializeConnection() throws RemoteException {
        try{
            connection = new Socket(this.host, this.port);
            output = new ObjectOutputStream(connection.getOutputStream());
            output.flush();
            input = new ObjectInputStream(connection.getInputStream());
            finished = false;
            startReader();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void startReader(){
        Thread th = new Thread(new ReaderThread());
        th.start();
    }

    private class ReaderThread implements Runnable {
        public void run(){
            while(!finished){
                try {
                    Object response = input.readObject();
                    System.out.println("Response received..." + response);
                    IResponse res = (SimpleResponse)response;
                    if(res.getResponseType() == ResponseType.UPDATE){
                        handleUpdate((SimpleResponse) response);
                    }else{
                        qResponses.put((SimpleResponse)response);
                    }
                } catch (IOException | ClassNotFoundException | InterruptedException e) {
                    System.out.println("Reading error " + e);
                    e.printStackTrace();
                }
            }
        }
    }

    private void handleUpdate(SimpleResponse response) throws RemoteException {
        client.updateSeats();
    }
}
