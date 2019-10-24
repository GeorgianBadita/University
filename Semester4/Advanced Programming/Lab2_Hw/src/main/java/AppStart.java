import controllers.LogInController;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import javafx.stage.WindowEvent;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import service.UserService;

public class AppStart extends Application{
    private static final Logger logger = LogManager.getLogger("AppStartLogger");

    @Override
    public void start(Stage primaryStage) throws Exception {
        logger.traceEntry("Entered start function");
        primaryStage.setTitle("Festival Log In");
        FXMLLoader loader = new FXMLLoader(getClass().getResource("view/logInView.fxml"));
        Pane logInPane = (Pane) loader.load();

        LogInController ctrl = loader.getController();

        ctrl.setService(getUserService());
        Scene newScene = new Scene(logInPane);

        primaryStage.setScene(newScene);

        primaryStage.setOnCloseRequest(new EventHandler<WindowEvent>() {
            @Override
            public void handle(WindowEvent event) {
                ctrl.close();
            }
        });

        logger.info("ready for stage show");
        primaryStage.show();
    }

    /**
     * Function to get the UserService from the Spring config file
     * @return - an UserService object
     */
    private UserService getUserService() {
        ApplicationContext context = new ClassPathXmlApplicationContext("FestivalSpringXML.xml");
        return context.getBean(UserService.class);
    }
}
