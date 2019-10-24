import ctrls.LogInController;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import javafx.stage.WindowEvent;
import objProtocol.ObjectProxy;
import org.apache.thrift.protocol.TBinaryProtocol;
import org.apache.thrift.protocol.TProtocol;
import org.apache.thrift.transport.TSocket;
import org.apache.thrift.transport.TTransport;
import org.geo.festival.THRIFTService;
import service.IServer;
import java.io.IOException;
import java.util.Properties;

public class AppStart2 extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {


        TTransport transport = new TSocket("localhost", 9095);
        transport.open();
        TProtocol protocol = new TBinaryProtocol(transport);

        THRIFTService.Client server = new THRIFTService.Client(protocol);



        primaryStage.setTitle("Festival Log In");
        FXMLLoader loader = new FXMLLoader(getClass().getResource("view/logInView.fxml"));
        Pane logInPane = (Pane) loader.load();

        LogInController ctrl = loader.getController();

        ctrl.setServer(server);
        Scene newScene = new Scene(logInPane);

        primaryStage.setScene(newScene);

        primaryStage.setOnCloseRequest(new EventHandler<WindowEvent>() {
            @Override
            public void handle(WindowEvent event) {
                ctrl.close();
            }
        });


        primaryStage.show();

    }
}
