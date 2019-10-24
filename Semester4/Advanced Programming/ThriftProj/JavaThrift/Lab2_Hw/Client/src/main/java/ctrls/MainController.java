package ctrls;



import javafx.application.Platform;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;

import org.apache.thrift.TException;
import org.geo.festival.Concert;
import org.geo.festival.DTOConcert;
import org.geo.festival.THRIFTService;
import org.geo.festival.Ticket;
import service.IObserver;
import service.IServer;


import java.io.IOException;
import java.rmi.RemoteException;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.List;


public class MainController implements IObserver {
    @FXML
    public DatePicker concertDatesPicker;
    @FXML
    public TextField clientNameTxt;
    @FXML
    public TextField numSeatsTxt;
    @FXML
    public Button ticketSellBtn;
    @FXML
    private TableView<DTOConcert> mainTable;
    @FXML
    private TableColumn<DTOConcert, String> artistCol;
    @FXML
    private TableColumn<DTOConcert, LocalDateTime> dateCol;
    @FXML
    private TableColumn<DTOConcert, String> locCol;
    @FXML
    private TableColumn<DTOConcert, Integer> numSeatsCol;
    @FXML
    private TableColumn<DTOConcert, Integer> soldSeatsCol;
    @FXML
    private Button checkConcertsBtn;

    private THRIFTService.Client server;

    private ObservableList<DTOConcert> concertModel = FXCollections.observableArrayList();

    public boolean updateBlock = false;


    /**
     * MainController constructor with no parameters
     */
    public MainController(){

    }

    @FXML
    public void initialize(){
        artistCol.setCellValueFactory(new PropertyValueFactory<DTOConcert, String>("artistName")); //
        dateCol.setCellValueFactory(new PropertyValueFactory<DTOConcert, LocalDateTime>("date")); //
        locCol.setCellValueFactory(new PropertyValueFactory<DTOConcert, String>("locationName")); //
        numSeatsCol.setCellValueFactory(new PropertyValueFactory<DTOConcert, Integer>("numOfSeats")); //
        soldSeatsCol.setCellValueFactory(new PropertyValueFactory<DTOConcert, Integer>("soldSeats")); //

        mainTable.setItems(concertModel);
        setTableColorChangeListener();
    }

    /**
     * Function to set a change row color listener on the table
     */
    private void setTableColorChangeListener() {
        soldSeatsCol.setCellFactory(column -> {
            return new TableCell<DTOConcert, Integer>() {
                @Override
                protected void updateItem(Integer item, boolean empty) {
                    super.updateItem(item, empty);

                    setText(empty ? "" : getItem().toString());
                    setGraphic(null);

                    TableRow<DTOConcert> currentRow = getTableRow();
                    DTOConcert concert = currentRow.getItem();
                    if (!isEmpty()) {

                        if(item != null && concert != null && item.equals(concert.getNumOfSeats())){
                            currentRow.setStyle("-fx-background-color:lightgreen");
                        }
                    }
                }
            };
        });
    }

    /**
     * Function to set the festival Service for the MinController
     * @param server - server object
     */
    public void setServer(THRIFTService.Client server) throws RemoteException {
        this.server = server;
        initModel();
    }

    /**
     * Function to initialize the model
     */
    private void initModel() {
        List<DTOConcert> dtoConcerts = null;
        try {
            dtoConcerts = server.getConcertDtos();
            for (DTOConcert dto:
                 dtoConcerts) {
                System.out.println("========================================== " + dto);
            }
        } catch (TException e) {
            e.printStackTrace();
        }
        concertModel.setAll(dtoConcerts);
    }


    /**
     * Function to handle ConcertCheckBy date button
     * @param ae - Action Event object
     */
    @FXML
    public void handleCheckConcerts(ActionEvent ae){



        Stage newStage = new Stage();
        newStage.setTitle("Concerts");
        FXMLLoader loader = new FXMLLoader(getClass().getResource("../view/dateFilte.fxml"));
        AnchorPane mainPane;
        try {
            mainPane = loader.load();
            DateFilterController controller = loader.getController();
            LocalDate filterDate = getFilterDate();
            if(filterDate == null){
                showInfoMessage("Date not selected!", "Please select ad ate before filtering concerts!");
                return;
            }
            controller.initData(filterDate);
            controller.setServer(server);
            Scene newScene = new Scene(mainPane);
            newStage.setScene(newScene);
            newStage.show();

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    /**
     * Function to handle ticket buy
     * @param ae - action event
     */
    @FXML
    private void handleTicketBuy(ActionEvent ae){
        int index = mainTable.getSelectionModel().getSelectedIndex();
        if(index < 0){
            showInfoMessage("Concert not selected!", "Please select a concert before buying a ticket");
            return;
        }

        try {
            String clientName = clientNameTxt.getText();
            if(clientName.equals("")){
                showInfoMessage("Incorrect client name!", "Client name can't be empty!");
                return;
            }
            Integer numSeats = Integer.parseInt(numSeatsTxt.getText());
            DTOConcert dtoConcert = mainTable.getSelectionModel().getSelectedItem();
            buyTickets(dtoConcert.getConcertId(), clientName, numSeats);
        }catch (NumberFormatException e){
            showInfoMessage("Incorrect number of seats!", "The number of seats must be a natural number");
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }

    /**
     * Function for buying a ticket
     * @param concert - concert
     * @param clientName - name of the client
     * @param numSeats - number of seats
     */
    private void buyTickets(Integer concert, String clientName, Integer numSeats) throws RemoteException {
        this.updateBlock = true;

        boolean canSell = false;
        try {
            canSell = server.canSellTicket(concert, numSeats);
        } catch (TException e) {

        }
        if(!canSell){
            showInfoMessage("Not enough seats!", "Sorry, there are not enough seats for this concert!");
            return;
        }

        Ticket ticket = null;
        try {
            ticket = server.sellTicket(concert, clientName, LocalDate.now().toString(), numSeats);
        } catch (TException e) {

        }
        if(ticket != null){
            return;
        }

        Concert oldConcert = null;
        try {
            oldConcert = server.findConcert(concert);
        } catch (TException e) {

        }

        try {
            server.updateConcert(oldConcert);
        } catch (TException e) {

        }
        try {
            server.notifyClients();
        } catch (TException e) {

        }

        initModel();
        this.updateBlock = false;
    }


    /**
     * Function to get and convert data from DatePicker
     * @return - DateValue from the datePicker
     */
    private LocalDate getFilterDate() {
        return concertDatesPicker.getValue();
    }

    /**
     * Function to handle window close
     */
    public void close(){

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

    @Override
    public void updateSeats() throws RemoteException {
        Platform.runLater(this::initModel);
    }

    public void handleRefresh() {
        initModel();
    }
}
