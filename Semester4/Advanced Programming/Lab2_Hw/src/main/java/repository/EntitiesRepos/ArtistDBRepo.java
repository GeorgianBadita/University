package repository.EntitiesRepos;

import domain.entities.Artist;
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

public class ArtistDBRepo implements CRUDRepository<Integer, Artist> {
    private DBUtils dbUtils;
    private Validator<Artist> artistValidator;
    private static final Logger logger = LogManager.getLogger("Artist Logger");

    /**
     * Constructor for Artist DataBase Repository
     * @param props - properties file
     * @param artistValidator - validator for artist class
     */
    public ArtistDBRepo(Properties props, Validator<Artist> artistValidator){
        logger.info("Initializing ArtistDBRepo.... {}", props);
        this.dbUtils = new DBUtils(props);
        this.artistValidator = artistValidator;
    }


    /**
     * Function to find an artist from the database
     * @param integer - id of the artist
     * @return - the entity with the given id if it exists, null otherwise
     * @throws IllegalArgumentException - if the id is null
     */
    @Override
    public Artist findOne(Integer integer) throws IllegalArgumentException {
        logger.traceEntry("Entered FindOne : IdArtist {}", integer);
        if(integer == null){
            throw  new IllegalArgumentException("Artist id can't be null");
        }
        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("select * from Artist where artistId= ?")){
            prSt.setInt(1, integer);
            try(ResultSet res = prSt.executeQuery()){
               if(res.next()){
                    Integer id = res.getInt("artistId");
                    String name = res.getString("artistName");
                    logger.traceExit("Exited findOne: Artist");
                    return new Artist(id, name);
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        logger.traceExit("There is no artist with the id... {}", integer);
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
    public Artist save(Artist entity) throws IllegalArgumentException, ValidatorException {
        logger.traceEntry("Entered Save artist.... {}", entity);
        if(entity == null){
            throw new IllegalArgumentException("Artist can't be null");
        }
        artistValidator.validate(entity);

        if(this.findOne(entity.getId()) != null){
            logger.info("Entity with given id already in repo... {}", entity.getId());
            return entity;
        }

        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("insert into Artist values(?, ?)")){
            prSt.setInt(1, entity.getId());
            prSt.setString(2, entity.getArtistName());
            int ret = prSt.executeUpdate();
            if(ret == 0){
                return entity;
            }
        } catch (SQLException e) {
            logger.error("Error in artist save.... {}", e);
            System.out.println("Error in ArtistDB "  + e);
            return entity;
        }

        logger.traceExit("Artist successfully saved");
        return null;
    }

    /**
     * Function to delete an entity from the repository
     * @param integer - id of the entity to be deleted
     * @return - the deleted entity if it was deleted, null otherwise
     * @throws IllegalArgumentException -if the id is null
     */
    @Override
    public Artist delete(Integer integer) throws IllegalArgumentException {
        logger.traceEntry("Entered Artist delete... {}", integer);
        if(integer == null){
            throw new IllegalArgumentException("Artist id can't be null");
        }

        Artist artist = findOne(integer);
        if(artist == null){
            logger.info("There is no artist with id... {}", integer);
            return null;
        }

        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("delete from Artist where artistId = ?")){
            prSt.setInt(1, integer);
            prSt.executeUpdate();
            logger.traceExit("Exited artist delete.... {}", artist);
            return artist;
        } catch (SQLException e) {
            logger.error("Error in artist delete.... {}", e);
            e.printStackTrace();
        }

        logger.info("Couldn't delete the given artist ....{}", artist);
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
    public Artist update(Artist entity) throws IllegalArgumentException, ValidatorException {
        logger.traceEntry("Entered Update artist.... {}", entity);
        if(entity == null){
            throw new IllegalArgumentException("The updated artist can't be null");
        }
        artistValidator.validate(entity);

        if(this.findOne(entity.getId()) == null){
            logger.info("Entity with given id not in repo... {}", entity.getId());
            return entity;
        }

        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("update Artist set artistName = ?" +
                                                             "where artistId = ?")){
            prSt.setInt(2, entity.getId());
            prSt.setString(1, entity.getArtistName());
            int ret = prSt.executeUpdate();
            if(ret == 0){
                return entity;
            }
        } catch (SQLException e) {
            logger.error("Error in artist update.... {}", e);
            System.out.println("Error in ArtistDB "  + e);
        }

        logger.traceExit("Artist successfully updated");
        return null;
    }

    /**
     * Function to get all entities from the repository
     * @return - iterable containing all entities from the repository
     */
    @Override
    public Iterable<Artist> findAll() {
        logger.entry("Entered in findAll artists");
        List<Artist> artistList = new ArrayList<>();
        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("select * from Artist")){
            try(ResultSet res = prSt.executeQuery()){
                while(res.next()){
                    Integer id = res.getInt("artistId");
                    String name = res.getString("artistName");
                    artistList.add(new Artist(id, name));
                }
            }
        } catch (SQLException e) {
            logger.error("Error in findAll artists... {}", e);
            System.out.println("Error in db Artists... " + e);
        }

        logger.traceExit("Exited findAll artists");
        return artistList;
    }

    /**
     * Function to retrieve the number of entities from the database
     * @return - number of entity in the database
     */
    @Override
    public Integer size() {
        logger.traceEntry("Entered Artist size");
        Connection con = dbUtils.getConnection();

        try(PreparedStatement prSt = con.prepareStatement("select count(*) as size from Artist")){
            try(ResultSet res = prSt.executeQuery()){
                if(res.next()){
                    logger.traceExit("Exited Artist size");

                    return res.getInt("size");
                }
            }
        } catch (SQLException e) {
            logger.error("Error in artist size  ...{}", e);
            System.out.println("Error in artist DB " + e);
        }

        logger.info("No entries in db");
        return 0;
    }
}
