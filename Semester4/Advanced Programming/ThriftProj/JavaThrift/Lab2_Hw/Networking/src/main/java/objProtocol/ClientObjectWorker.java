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

public class ClientObjectWorker implements Runnable, IObserver {
    private IServer server;
    private Socket connection;

    private ObjectOutputStream output;
    private ObjectInputStream input;
    private volatile boolean connected;

    public ClientObjectWorker(IServer server, Socket connection){
        this.server = server;
        this.connection = connection;
        try{
            output = new ObjectOutputStream(connection.getOutputStream());
            input = new ObjectInputStream(connection.getInputStream());
            connected = true;
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void run() {
        while(connected){
            try {
                Object req = input.readObject();
                Object response = handleRequest((IRequest)req);
                if(response != null){
                    sendResponse((IResponse)response);
                }
            } catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }
        }

        try{
            input.close();
            output.close();
            connection.close();
        } catch (IOException e) {
            System.out.println("Error " + e);
        }
    }

    private void sendResponse(IResponse response) throws IOException {
        System.out.println("Sending response... " + response);
        output.writeObject(response);
        output.flush();
    }

    private IResponse handleRequest(IRequest req) throws RemoteException {
        IResponse response = null;
        IRequest request = req;
        if(request.getRequestType() == RequestType.LOGIN){
            System.out.println("Log In Request... ");
            User usrt = (User) request.getData();
            try{
                boolean ok = server.validateLogIn(usrt.getName(), usrt.getPassword(), this);
                if(ok){
                    return new SimpleResponse(ResponseType.OK);
                }
            } catch (RemoteException e) {
                connected = false;
                return new SimpleResponse(ResponseType.ERROR);
            }
        }else if(request.getRequestType() == RequestType.INIT){
            System.out.println("Init Request....");
            List<DTOConcert> concerts = server.getConcertDtos();
            if(concerts == null){
                return new SimpleResponse(ResponseType.ERROR);
            }
            return new SimpleResponse(ResponseType.OK, concerts);
        }else if(request.getRequestType() == RequestType.FILTER){
            System.out.println("Filter Request....");
            LocalDate date = (LocalDate)request.getData();
            List<DTOConcert> concerts = server.getConcertDtosByDate(date);
            if(concerts == null){
                return new SimpleResponse(ResponseType.ERROR);
            }
            return new SimpleResponse(ResponseType.OK, concerts);
        }else if(request.getRequestType() == RequestType.CAN_SELL){
            System.out.println("Can Sell Request....");
            List<Object> params = (List<Object>)request.getData();
            Integer concId = (Integer) params.get(0);
            Integer numSeats = (Integer) params.get(1);
            boolean canSell = server.canSellTicket(concId, numSeats);
            if(canSell){
                return new SimpleResponse(ResponseType.OK);
            }else{
                return new SimpleResponse(ResponseType.ERROR);
            }
        }else if(request.getRequestType() == RequestType.FIND){
            System.out.println("Find Request...");
            Integer concId = (Integer) request.getData();
            Concert concert = server.findConcert(concId);
            if(concert == null){
                return new SimpleResponse(ResponseType.ERROR);
            }else{
                return new SimpleResponse(ResponseType.OK, concert);
            }
        }else if(request.getRequestType() == RequestType.SELL){
            System.out.println("Selling ticket");
            List<Object> params = (List<Object>)request.getData();
            Integer concert = (Integer)params.get(0);
            String clname = (String)params.get(1);
            LocalDate now = (LocalDate)params.get(2);
            Integer numSeats = (Integer)params.get(3);
            Ticket soldTick = server.sellTicket(concert, clname, now, numSeats);
            if(soldTick == null){
                return new SimpleResponse(ResponseType.ERROR);
            }else{
                return new SimpleResponse(ResponseType.OK, soldTick);
            }

        }else if(request.getRequestType() == RequestType.UPDATE_CONC){
            System.out.println("Updating concert after selling....");
            Concert conc = (Concert)request.getData();
            Concert updated = server.updateConcert(conc);
            if(updated == null){
                return new SimpleResponse(ResponseType.ERROR);
            }
            else{
                return new SimpleResponse(ResponseType.OK, conc);
            }
        }else if(request.getRequestType() == RequestType.UPDATE){
            //System.out.println("Updating user..");
            server.notifyClients();
            return new SimpleResponse(ResponseType.OK);
        }

        return response;
    }


    @Override
    public void updateSeats() {
        try {
            sendResponse(new SimpleResponse(ResponseType.UPDATE));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
