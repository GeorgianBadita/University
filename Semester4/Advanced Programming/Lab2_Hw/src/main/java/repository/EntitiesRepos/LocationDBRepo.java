package repository.EntitiesRepos;

import domain.entities.Location;
import domain.exceptions.IllegalArgumentException;
import domain.exceptions.ValidatorException;
import domain.validator.Validator;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import repository.CRUDRepository;
import repository.DataBaseUtils.DBUtils;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;

public class LocationDBRepo implements CRUDRepository<Integer, Location> {
    private DBUtils dbUtils;
    private Validator<Location> locValidator;
    private static final Logger logger = LogManager.getLogger("LocRepoLogger");

    /**
     * Constructor for Location repository
     * @param props
     */
    public LocationDBRepo(Properties props, Validator<Location> locationValidator){
        logger.info("Intializaing Location Repository: {}", props);
        this.dbUtils = new DBUtils(props);
        this.locValidator = locationValidator;
    }


    @Override
    public Location findOne(Integer integer) throws IllegalArgumentException {
        logger.traceEntry("Finding Location with id {}", integer);

        if(integer == null){
            throw new IllegalArgumentException("Location id can't be null!");
        }

        Connection con = dbUtils.getConnection();

        try(PreparedStatement preStm = con.prepareStatement("select * from Location where locationId=?")) {
            preStm.setInt(1,integer);
            try(ResultSet result = preStm.executeQuery()){
                if(result.next()){
                    int id = result.getInt("locationId");
                    String locName = result.getString("locationName");
                    int numOfSeats = result.getInt("totalSeats");
                    return new Location(id, locName, numOfSeats);
                }
            }
        } catch (SQLException e) {
            logger.error(e);
            System.out.println("Error DB " + e);
        }

        logger.traceExit("No Location found with id {} ", integer);
        return null;
    }

    @Override
    public Location save(Location entity) throws IllegalArgumentException, ValidatorException {

        logger.traceEntry("Entered save location... {}", entity);
        if(entity == null){
            throw new IllegalArgumentException("Location can't be null!");
        }
        locValidator.validate(entity);
        if(this.findOne(entity.getId()) != null){
            return entity;
        }
        Connection con = dbUtils.getConnection();
        try(PreparedStatement preparedStatement = con.prepareStatement("insert into Location values (?, ?, ?)")) {
            preparedStatement.setInt(1, entity.getId());
            preparedStatement.setString(2, entity.getLocName());
            preparedStatement.setInt(3, entity.getTotalSeats());
            int ret = preparedStatement.executeUpdate();
            if(ret == 0){
                return entity;
            }
        } catch (SQLException e) {
            logger.error(e);
            System.out.println("Error in save location " + e);
            return entity;
        }
        return null;
    }

    @Override
    public Location delete(Integer integer) throws IllegalArgumentException {
        logger.traceEntry("Entered location delete... {}", integer);
        Connection con = dbUtils.getConnection();
        if(integer == null){
            throw  new IllegalArgumentException("Location id can't be null!");
        }
        Location toDel = this.findOne(integer);
        if(toDel == null){
            return null;
        }

        try(PreparedStatement prSt = con.prepareStatement("delete from Location where locationId = ?")){
            prSt.setInt(1, integer);
            prSt.executeUpdate();
            return toDel;

        } catch (SQLException e) {
            logger.error("Error in delete... {}" + e);
            System.out.println("Error in LocDB delete " + e);
        }
        logger.traceExit("Couldn't delete location... {}", toDel);
        return null;
    }

    @Override
    public Location update(Location entity) throws IllegalArgumentException, ValidatorException {
        logger.traceEntry("Entered updated location... {}", entity);
        if(entity == null){
            throw new IllegalArgumentException("Location entity can't be null!");
        }
        locValidator.validate(entity);

        if(this.findOne(entity.getId()) == null){
            return entity;
        }
        Connection con = dbUtils.getConnection();
        try(PreparedStatement preparedStatement = con.prepareStatement("update Location set locationName = ?, totalSeats = ? where locationId = ?")) {
            preparedStatement.setInt(3, entity.getId());
            preparedStatement.setString(1, entity.getLocName());
            preparedStatement.setInt(2, entity.getTotalSeats());
            preparedStatement.executeUpdate();
        } catch (SQLException e) {
            logger.error(e);
            System.out.println("Error in update location " + e);
        }
        return null;
    }

    @Override
    public Iterable<Location> findAll() {
        logger.traceEntry();
        List<Location> locations = new ArrayList<>();
        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("select * from Location")){
            try(ResultSet result = prSt.executeQuery()){
                while(result.next()){
                    Integer locId = result.getInt("locationId");
                    String locName = result.getString("locationName");
                    Integer seats = result.getInt("totalSeats");
                    Location loc = new Location(locId, locName, seats);
                    locations.add(loc);
                }
            }
        } catch (SQLException e) {
            logger.error("Error in findAll locations ", e );
            System.out.println("Error in DB Locations " + e) ;
        }
        logger.traceExit(locations);
        return locations;
    }

    @Override
    public Integer size() {
        logger.traceEntry("Entered getSize Location Repo");
        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("select count(*) as SIZE from Location")){
            try(ResultSet res = prSt.executeQuery()){
                if(res.next()){
                    logger.traceExit(res.getInt("SIZE"));
                    return res.getInt("SIZE");
                }
            }
        } catch (SQLException e) {
            logger.error("Error in locationRepo size... {}", e);
            System.out.println("Error in LocationDB" + e);
        }
        return 0;
    }
}
