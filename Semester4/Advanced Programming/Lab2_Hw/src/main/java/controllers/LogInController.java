package controllers;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import javafx.stage.WindowEvent;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import service.FestivalService;
import service.UserService;

import java.io.IOException;

public class LogInController {
    private static Logger logger = LogManager.getLogger("LogInLogger");
    @FXML
    public TextField userText;
    @FXML
    public TextField passText;
    @FXML
    public Button logInBtn;

    private UserService usrServ;

    /**
     * Constructor with no parameters
     */
    public LogInController(){

    }

    @FXML
    public void initialize(){

    }

    /**
     * Function to set the service for logInController
     * @param srv - UserService object
     */
    public void setService(UserService srv){
        this.usrServ = srv;
    }


    /**
     * Function to handle logIn action
     * @param actionEvent - action Event object
     */
    public void handleLogIn(ActionEvent actionEvent) {
        String userName = userText.getText();
        String pass = passText.getText();

        boolean logInSuccess = validateLogInController(userName, pass);
        if(!logInSuccess){
            showInfoMessage("Incorrect credentials!","Incorrect username or password, please try again :)");
            return;
        }
        else{
            handleMainWindowStart();
        }
    }

    /**
     * Function to handle main window start
     */
    private void handleMainWindowStart() {
        logger.traceEntry("Entered handleMainWindowStart");
        FestivalService festivalService =
                new ClassPathXmlApplicationContext("FestivalSpringXML.xml")
                .getBean(FestivalService.class);

        Stage newStage = new Stage();
        newStage.setTitle("Festival");
        FXMLLoader loader = new FXMLLoader(getClass().getResource("../view/mainView.fxml"));
        AnchorPane mainPane = null;
        try {
            mainPane = (AnchorPane) loader.load();
            MainController controller = loader.getController();
            controller.setFestivalService(festivalService);
            Scene newScene = new Scene(mainPane);
            newStage.setScene(newScene);
            logInBtn.getScene().getWindow().hide();
            newStage.show();

        } catch (IOException e) {
            e.printStackTrace();
        }





        logger.traceExit("Exited handleMainWindowStart");

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
    private boolean validateLogInController(String userName, String pass) {
        return usrServ.validateLogIn(userName, pass);
    }


    /**
     * Function for closing the logIn windows
     */
    public void close() {
    }

}
