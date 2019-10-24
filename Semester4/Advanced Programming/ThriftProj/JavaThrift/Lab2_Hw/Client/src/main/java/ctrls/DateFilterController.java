package ctrls;


import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import org.apache.thrift.TException;
import org.geo.festival.DTOConcert;
import org.geo.festival.THRIFTService;
import service.IServer;


import java.rmi.RemoteException;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.List;

public class DateFilterController {
    @FXML
    private TableView<DTOConcert> filterTable;
    @FXML
    private TableColumn<DTOConcert, String> artistCol;
    @FXML
    private TableColumn<DTOConcert, LocalDateTime> dateCol;
    @FXML
    private TableColumn<DTOConcert, String> locCol;
    @FXML
    private TableColumn<DTOConcert, Integer> freeSeatsCol;

    private THRIFTService.Client server;

    private LocalDate dateFilter;
    private ObservableList<DTOConcert> model = FXCollections.observableArrayList();

    /**
     * No parameter constructor
     */
    public DateFilterController(){


    }


    /**
     * Initialize function
     */
    @FXML
    public void initialize(){
        artistCol.setCellValueFactory(new PropertyValueFactory<DTOConcert, String>("artistName")); //
        dateCol.setCellValueFactory(new PropertyValueFactory<DTOConcert, LocalDateTime>("date")); //
        locCol.setCellValueFactory(new PropertyValueFactory<DTOConcert, String>("locationName")); //
        freeSeatsCol.setCellValueFactory(new PropertyValueFactory<DTOConcert, Integer>("freeSeats")); //

        filterTable.setItems(model);
    }

    /**
     * Function to set the festival service
     * @param server - festival service object
     */
    public void setServer(THRIFTService.Client server) throws RemoteException {
        this.server = server;
        initModel();
    }

    /**
     * Function to initialize the model
     */
    private void initModel() throws RemoteException {
        List<DTOConcert> list = null;
        try {
            list = server.getConcertDtosByDate(dateFilter.toString());
        } catch (TException e) {
            e.printStackTrace();
        }
        model.setAll(list);
    }

    /**
     * Function to set the date to filter concerts
     * @param date - LocalDateTime object
     */
    public void initData(LocalDate date){
        this.dateFilter = date;
    }
}
