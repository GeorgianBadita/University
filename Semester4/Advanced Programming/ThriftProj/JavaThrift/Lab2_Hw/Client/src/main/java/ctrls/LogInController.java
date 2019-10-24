package ctrls;

import Observer.Observer;
import Observer.UpdateServer;
import Observer.UpdateService;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;

import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import org.apache.thrift.TException;
import org.apache.thrift.server.TServer;
import org.apache.thrift.server.TSimpleServer;
import org.apache.thrift.transport.TServerSocket;
import org.apache.thrift.transport.TServerTransport;
import org.apache.thrift.transport.TTransportException;
import org.geo.festival.THRIFTService;
import service.IObserver;
import service.IServer;


import java.io.IOException;
import java.rmi.RemoteException;

public class LogInController{
    private static Logger logger = LogManager.getLogger("LogInLogger");
    @FXML
    public TextField userText;
    @FXML
    public TextField passText;
    @FXML
    public Button logInBtn;
    private int updatePort;

    private THRIFTService.Client server;
    public UpdateServer updateServer;

    /**
     * Constructor with no parameters
     */
    public LogInController(){

    }

    /**
     * Constructor with no parameters
     */
    public LogInController(THRIFTService.Client server){
        this.server = server;
    }

    @FXML
    public void initialize(){

    }

    /**
     * Function to set the service for logInController
     * @param srv - UserService object
     */
    public void setService(THRIFTService.Client srv){
        this.server = srv;
    }


    public void setServer(THRIFTService.Client server){
        this.updateServer = new UpdateServer();
        this.server = server;
    }



    /**
     * Function to handle logIn action
     * @param actionEvent - action Event object
     */
    public void handleLogIn(ActionEvent actionEvent) throws RemoteException {
        String userName = userText.getText();
        String pass = passText.getText();

        Stage newStage = new Stage();
        newStage.setTitle("Festival");
        FXMLLoader loader = new FXMLLoader(getClass().getResource("../view/mainView.fxml"));
        AnchorPane mainPane = null;
        try {
            mainPane = (AnchorPane) loader.load();
            MainController controller;
            controller = loader.getController();
            TServerTransport serverTransport = getServerSocket();
            boolean logInSuccess = validateLogInController(userName, pass);
            if(!logInSuccess){
                showInfoMessage("Incorrect credentials!","Incorrect username or password, please try again :)");
                return;
            }
            //starting the update server
            UpdateServer updateServer = this.updateServer;
            UpdateService.Processor processor = new UpdateService.Processor<>(updateServer);
            TServer server = new TSimpleServer(new TServer.Args(serverTransport).processor(processor));

            Observer observer = new Observer(server);
            Thread thread = new Thread(observer);
            thread.start();
            System.out.println("Started update server on port " + this.updatePort);
            controller.setServer(this.server);
            updateServer.setController(controller);
            Scene newScene = new Scene(mainPane);
            newStage.setScene(newScene);
            logInBtn.getScene().getWindow().hide();
            newStage.show();

        } catch (IOException e) {
            e.printStackTrace();
        }


        //TODO artificial IOBSERVER

    }


    /**
     * Function to show info prompts to the user
     * @param text - string to show
     * @param title - title string
     */
    private void showInfoMessage(String title, String text) {
        Alert msg = new Alert(Alert.AlertType.INFORMATION);
        msg.setTitle(title);
        msg.setContentText(text);
        msg.showAndWait();
    }

    /**
     * Function to check if the user is in the database
     * @param userName - username
     * @param pass - password
     */
    private boolean validateLogInController(String userName, String pass) throws RemoteException {
        try {

            return server.validateLogIn(userName, pass, this.updatePort);
        } catch (TException e) {
            e.printStackTrace();
        }
        return false;
    }

    private TServerTransport getServerSocket() {
        TServerTransport serverTransport;
        for(int i=1000;i<=55555;i++){
            try {
                serverTransport =  new TServerSocket(i);
                if(serverTransport != null){
                    this.updatePort = i;
                    return serverTransport;
                }

            } catch (TTransportException e) {
                e.printStackTrace();
            }
            catch (Exception e){
                e.printStackTrace();
            }
        }
        return null;
    }

    /**
     * Function for closing the logIn windows
     */
    public void close() {
    }

}
