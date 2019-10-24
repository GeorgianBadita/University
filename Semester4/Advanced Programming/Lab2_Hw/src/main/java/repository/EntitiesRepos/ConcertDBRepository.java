package repository.EntitiesRepos;

import domain.entities.Concert;
import domain.entities.ConcertType;
import domain.exceptions.IllegalArgumentException;
import domain.exceptions.ValidatorException;
import domain.validator.Validator;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import repository.CRUDRepository;
import repository.DataBaseUtils.DBUtils;

import java.sql.*;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;

public class ConcertDBRepository implements CRUDRepository<Integer, Concert> {
    private DBUtils dbUtils;
    private Validator<Concert> concertValidator;
    private static final Logger logger = LogManager.getLogger("Concert Logger");

    /**
     * Constructor for Concert DataBase Repository
     * @param props - properties file
     * @param concertValidator - validator for concert class
     */
    public ConcertDBRepository(Properties props, Validator<Concert> concertValidator){
        logger.info("Initializing concertDBRepo.... {}", props);
        this.dbUtils = new DBUtils(props);
        this.concertValidator = concertValidator;
    }


    /**
     * Function to find an concert from the database
     * @param integer - id of the concert
     * @return - the entity with the given id if it exists, null otherwise
     * @throws IllegalArgumentException - if the id is null
     */
    @Override
    public Concert findOne(Integer integer) throws IllegalArgumentException {
        logger.traceEntry("Entered FindOne : IdConcert {}", integer);
        if(integer == null){
            throw  new IllegalArgumentException("Concert id can't be null");
        }
        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("select * from Concert where concertId= ?")){
            prSt.setInt(1, integer);
            try(ResultSet res = prSt.executeQuery()){
                if(res.next()){
                    Integer id = res.getInt("concertId");
                    Integer locId = res.getInt("locationId");
                    Integer artistId = res.getInt("artistId");
                    ConcertType type = ConcertType.valueOf(res.getString("type"));
                    Integer seatsS = res.getInt("seatsSold");
                    LocalDateTime date = res.getTimestamp("date").toLocalDateTime();
                    logger.traceExit("Exited findOne: concert");
                    return new Concert(id, locId, artistId, date, type, seatsS);
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        logger.traceExit("There is no concert with the id... {}", integer);
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
    public Concert save(Concert entity) throws IllegalArgumentException, ValidatorException {
        logger.traceEntry("Entered Save concert.... {}", entity);
        if(entity == null){
            throw new IllegalArgumentException("Concert can't be null");
        }
        concertValidator.validate(entity);

        if(this.findOne(entity.getId()) != null){
            logger.info("Concert with given id already in repo... {}", entity.getId());
            return entity;
        }

        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("insert into Concert values(?, ?, ?, ?, ?, ?)")){
            prSt.setInt(1, entity.getId());
            prSt.setInt(2, entity.getLocationId());
            prSt.setInt(3, entity.getArtistId());
            prSt.setTimestamp(4, Timestamp.valueOf(entity.getDate()));
            prSt.setString(5, entity.getType().name());
            prSt.setInt(6, entity.getSeatsSold());
            int ret = prSt.executeUpdate();
            if(ret == 0){
                return entity;
            }
        } catch (SQLException e) {
            logger.error("Error in concert save.... {}", e);
            System.out.println("Error in concertDB "  + e);
            return entity;
        }

        logger.traceExit("concert successfully saved");
        return null;
    }

    /**
     * Function to delete an entity from the repository
     * @param integer - id of the entity to be deleted
     * @return - the deleted entity if it was deleted, null otherwise
     * @throws IllegalArgumentException -if the id is null
     */
    @Override
    public Concert delete(Integer integer) throws IllegalArgumentException {
        logger.traceEntry("Entered concert delete... {}", integer);
        if(integer == null){
            throw new IllegalArgumentException("concert id can't be null");
        }

        Concert concert = findOne(integer);
        if(concert == null){
            logger.info("There is no concert with id... {}", integer);
            return null;
        }

        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("delete from Concert where concertId = ?")){
            prSt.setInt(1, integer);
            prSt.executeUpdate();
            logger.traceExit("Exited concert delete.... {}", concert);
            return concert;
        } catch (SQLException e) {
            logger.error("Error in concert delete.... {}", e);
            e.printStackTrace();
        }

        logger.info("Couldn't delete the given concert ....{}", integer);
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
    public Concert update(Concert entity) throws IllegalArgumentException, ValidatorException {
        logger.traceEntry("Entered Update concert.... {}", entity);
        if(entity == null){
            throw new IllegalArgumentException("The updated concert can't be null");
        }
        concertValidator.validate(entity);

        if(this.findOne(entity.getId()) == null){
            logger.info("Concert with given id not in repo... {}", entity.getId());
            return entity;
        }

        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("update Concert set locationId = ?, artistId =?, date=?, type=?, seatsSold = ?" +
                " where concertId = ?")){
            prSt.setInt(6, entity.getId());
            prSt.setInt(1, entity.getLocationId());
            prSt.setInt(2, entity.getArtistId());
            prSt.setTimestamp(3, Timestamp.valueOf(entity.getDate()));
            prSt.setString(4, entity.getType().name());
            prSt.setInt(5, entity.getSeatsSold());
            int ret = prSt.executeUpdate();
            if(ret == 0){
                return entity;
            }
        } catch (SQLException e) {
            logger.error("Error in concert update.... {}", e);
            System.out.println("Error in concertDB "  + e);
        }

        logger.traceExit("concert successfully updated");
        return null;
    }

    /**
     * Function to get all entities from the repository
     * @return - iterable containing all entities from the repository
     */
    @Override
    public Iterable<Concert> findAll() {
        logger.entry("Entered in findAll concerts");
        List<Concert> concertList = new ArrayList<>();
        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("select * from Concert")){
            try(ResultSet res = prSt.executeQuery()){
                while(res.next()){
                    Integer id = res.getInt("concertId");
                    Integer locationId = res.getInt("locationId");
                    Integer artistId = res.getInt("artistId");
                    LocalDateTime date;
                    date = res.getTimestamp("date").toLocalDateTime();
                    ConcertType concertType = ConcertType.valueOf(res.getString("type"));
                    Integer seats = res.getInt("seatsSold");
                    concertList.add(new Concert(id, locationId, artistId, date, concertType, seats));
                }
            }
        } catch (SQLException e) {
            logger.error("Error in findAll concerts... {}", e);
            System.out.println("Error in db concerts... " + e);
        }

        logger.traceExit("Exited findAll concerts");
        return concertList;
    }

    /**
     * Function to retrieve the number of entities from the database
     * @return - number of entity in the database
     */
    @Override
    public Integer size() {
        logger.traceEntry("Entered Concert size");
        Connection con = dbUtils.getConnection();

        try(PreparedStatement prSt = con.prepareStatement("select count(*) as size from Concert")){
            try(ResultSet res = prSt.executeQuery()){
                if(res.next()){
                    logger.traceExit("Exited Concert size");

                    return res.getInt("size");
                }
            }
        } catch (SQLException e) {
            logger.error("Error in concert size  ...{}", e);
            System.out.println("Error in concert DB " + e);
        }

        logger.info("No entries in db");
        return 0;
    }
}
