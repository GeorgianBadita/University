package controllers;

import domain.entities.Concert;
import domain.entities.DTOConcert;
import domain.entities.Ticket;
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
import org.springframework.context.support.ClassPathXmlApplicationContext;
import service.FestivalService;

import java.io.IOException;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.List;


public class MainController {
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

    private FestivalService festivalService;

    private ObservableList<DTOConcert> concertModel = FXCollections.observableArrayList();



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
     * @param festivalService - festivalService object
     */
    public void setFestivalService(FestivalService festivalService){
        this.festivalService = festivalService;
        initModel();
    }

    /**
     * Function to initialize the model
     */
    private void initModel() {
        List<DTOConcert> dtoConcerts = festivalService.getConcertDtos();
        concertModel.setAll(dtoConcerts);
    }


    /**
     * Function to handle ConcertCheckBy date button
     * @param ae - Action Event object
     */
    @FXML
    public void handleCheckConcerts(ActionEvent ae){

        FestivalService festivalService =
                new ClassPathXmlApplicationContext("FestivalSpringXML.xml")
                        .getBean(FestivalService.class);

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
            controller.setFestivalService(festivalService);
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
        }
    }

    /**
     * Function for buying a ticket
     * @param concert - concert
     * @param clientName - name of the client
     * @param numSeats - number of seats
     */
    private void buyTickets(Integer concert, String clientName, Integer numSeats) {
        boolean canSell = festivalService.canSellTicket(concert, numSeats);
        if(!canSell){
            showInfoMessage("Not enough seats!", "Sorry, there are not enough seats for this concert!");
            return;
        }

        Ticket ticket = festivalService.sellTicket(concert, clientName, LocalDate.now(), numSeats);
        if(ticket != null){
            return;
        }

        Concert oldConcert = festivalService.findConcert(concert);
        oldConcert.setSeatsSold(oldConcert.getSeatsSold() + numSeats);
        festivalService.updateConcert(oldConcert);

        initModel(); //TODO change this shit
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

}
