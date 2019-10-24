package controllers;

import domain.entities.DTOConcert;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import service.FestivalService;

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

    private FestivalService festivalService;

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
     * @param festivalService - festival service object
     */
    public void setFestivalService(FestivalService festivalService){
        this.festivalService = festivalService;
        initModel();
    }

    /**
     * Function to initialize the model
     */
    private void initModel() {
        List<DTOConcert> list = festivalService.getConcertDtosByDate(dateFilter);
        list.forEach(x -> System.out.println(x));
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
