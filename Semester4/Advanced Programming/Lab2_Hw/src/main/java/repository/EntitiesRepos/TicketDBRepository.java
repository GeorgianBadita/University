package repository.EntitiesRepos;

import domain.entities.Ticket;
import domain.exceptions.IllegalArgumentException;
import domain.exceptions.ValidatorException;
import domain.validator.Validator;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import repository.CRUDRepository;
import repository.DataBaseUtils.DBUtils;

import java.sql.*;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;

public class TicketDBRepository implements CRUDRepository<Integer, Ticket> {
    private DBUtils dbUtils;
    private Validator<Ticket> ticketValidator;
    private static final Logger logger = LogManager.getLogger("Ticket Logger");

    /**
     * Constructor for Ticket DataBase Repository
     * @param props - properties file
     * @param ticketValidator - validator for Ticket class
     */
    public TicketDBRepository(Properties props, Validator<Ticket> ticketValidator){
        logger.info("Initializing TicketDBRepo.... {}", props);
        this.dbUtils = new DBUtils(props);
        this.ticketValidator = ticketValidator;
    }


    /**
     * Function to find an Ticket from the database
     * @param integer - id of the Ticket
     * @return - the entity with the given id if it exists, null otherwise
     * @throws IllegalArgumentException - if the id is null
     */
    @Override
    public Ticket findOne(Integer integer) throws IllegalArgumentException {
        logger.traceEntry("Entered FindOne : IdTicket {}", integer);
        if(integer == null){
            throw  new IllegalArgumentException("Ticket id can't be null");
        }
        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("select * from Ticket where ticketId= ?")){
            prSt.setInt(1, integer);
            try(ResultSet res = prSt.executeQuery()){
                if(res.next()){
                    Integer id = res.getInt("ticketId");
                    Integer concId = res.getInt("concertId");
                    String name = res.getString("clientName");
                    LocalDate date = res.getDate("buyDate").toLocalDate();
                    Integer seats = res.getInt("numOfSeats");
                    logger.traceExit("Exited findOne: Ticket");
                    return new Ticket(id, concId, name, date, seats);
                }
            }
        } catch (SQLException e) {
            logger.error("Error in Ticket find ... {}", e);
            System.out.println("Error in TicketDB " + e);
        }

        logger.traceExit("There is no Ticket with the id... {}", integer);
        return null;
    }

    /**
     * Function to save ane entity into the database
     * @param entity - entity to be saved
     * @return - null if the entity was saved, the given entity otherwise
     * @throws IllegalArgumentException - if entity is null
     * @throws ValidatorException - if the entity is not well formed
     */
    @Override
    public Ticket save(Ticket entity) throws IllegalArgumentException, ValidatorException {
        logger.traceEntry("Entered Save Ticket.... {}", entity);
        if(entity == null){
            throw new IllegalArgumentException("Ticket can't be null");
        }
        ticketValidator.validate(entity);

        if(this.findOne(entity.getId()) != null){
            logger.info("Ticket with given id already in repo... {}", entity.getId());
            return entity;
        }

        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("insert into Ticket values(?, ?, ?, ?, ?)")){
            prSt.setInt(1, entity.getId());
            prSt.setInt(2, entity.getConcertId());
            prSt.setString(3, entity.getClientName());
            prSt.setDate(4, Date.valueOf(entity.getBuyDate()));
            prSt.setInt(5, entity.getNumOfSeats());
            int ret = prSt.executeUpdate();
            if(ret == 0){
                return entity;
            }
        } catch (SQLException e) {
            logger.error("Error in Ticket save.... {}", e);
            System.out.println("Error in TicketDB "  + e);
            return entity;
        }

        logger.traceExit("Ticket successfully saved");
        return null;
    }

    /**
     * Function to delete an entity from the repository
     * @param integer - id of the entity to be deleted
     * @return - the deleted entity if it was deleted, null otherwise
     * @throws IllegalArgumentException -if the id is null
     */
    @Override
    public Ticket delete(Integer integer) throws IllegalArgumentException {
        logger.traceEntry("Entered Ticket delete... {}", integer);
        if(integer == null){
            throw new IllegalArgumentException("Ticket id can't be null");
        }

        Ticket Ticket = findOne(integer);
        if(Ticket == null){
            logger.info("There is no Ticket with id... {}", integer);
            return null;
        }

        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("delete from Ticket where ticketId = ?")){
            prSt.setInt(1, integer);
            prSt.executeUpdate();
            logger.traceExit("Exited Ticket delete.... {}", Ticket);
            return Ticket;
        } catch (SQLException e) {
            logger.error("Error in Ticket delete.... {}", e);
            e.printStackTrace();
        }

        logger.info("Couldn't delete the given Ticket ....{}", Ticket);
        return null;
    }

    /**
     * Function to update an entity from the repository
     * @param entity - the entity to be updated
     * @return - null if the entity was updated, the given entity otherwise
     * @throws IllegalArgumentException - if entity is null
     * @throws ValidatorException - if the given entity is not well formed
     */
    @Override
    public Ticket update(Ticket entity) throws IllegalArgumentException, ValidatorException {
        logger.traceEntry("Entered Update Ticket.... {}", entity);
        if(entity == null){
            throw new IllegalArgumentException("The updated Ticket can't be null");
        }
        ticketValidator.validate(entity);

        if(this.findOne(entity.getId()) == null){
            logger.info("Ticket with given id not in repo... {}", entity.getId());
            return entity;
        }

        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("update Ticket set concertId=?, clientName=?, buyDate=?, numOfSeats = ?" +
                " where TicketId = ?")){
            prSt.setInt(5, entity.getId());
            prSt.setInt(1, entity.getConcertId());
            prSt.setString(2, entity.getClientName());
            prSt.setDate(3, Date.valueOf(entity.getBuyDate()));
            prSt.setInt(4, entity.getNumOfSeats());

            int ret = prSt.executeUpdate();
            if(ret == 0){
                return entity;
            }
        } catch (SQLException e) {
            logger.error("Error in Ticket update.... {}", e);
            System.out.println("Error in TicketDB "  + e);
        }

        logger.traceExit("Ticket successfully updated");
        return null;
    }

    /**
     * Function to get all entities from the repository
     * @return - iterable containing all entities from the repository
     */
    @Override
    public Iterable<Ticket> findAll() {
        logger.entry("Entered in findAll Tickets");
        List<Ticket> TicketList = new ArrayList<>();
        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("select * from Ticket")){
            try(ResultSet res = prSt.executeQuery()){
                while(res.next()){
                    Integer id = res.getInt("ticketId");
                    Integer concId = res.getInt("concertId");
                    String name;
                    name = res.getString("clientName");
                    LocalDate date = res.getDate("buyDate").toLocalDate();
                    Integer seats = res.getInt("numOfSeats");

                    TicketList.add(new Ticket(id, concId, name, date, seats));
                }
            }
        } catch (SQLException e) {
            logger.error("Error in findAll Tickets... {}", e);
            System.out.println("Error in db Tickets... " + e);
        }

        logger.traceExit("Exited findAll Tickets");
        return TicketList;
    }

    /**
     * Function to retrieve the number of entities from the database
     * @return - number of entity in the database
     */
    @Override
    public Integer size() {
        logger.traceEntry("Entered Ticket size");
        Connection con = dbUtils.getConnection();

        try(PreparedStatement prSt = con.prepareStatement("select count(*) as size from Ticket")){
            try(ResultSet res = prSt.executeQuery()){
                if(res.next()){
                    logger.traceExit("Exited Ticket size");

                    return res.getInt("size");
                }
            }
        } catch (SQLException e) {
            logger.error("Error in Ticket size  ...{}", e);
            System.out.println("Error in Ticket DB " + e);
        }

        logger.info("No entries in db");
        return 0;
    }
}
