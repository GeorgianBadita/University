package repository.EntitiesRepos;

import domain.entities.User;
import domain.entities.User;
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

public class UserDBRepository implements CRUDRepository<Integer, User> {
    private DBUtils dbUtils;
    private Validator<User> userValidator;
    private static final Logger logger = LogManager.getLogger("User Logger");

    /**
     * Constructor for User DataBase Repository
     * @param props - properties file
     * @param userValidator - validator for User class
     */
    public UserDBRepository(Properties props, Validator<User> userValidator){
        logger.info("Initializing UserDBRepo.... {}", props);
        this.dbUtils = new DBUtils(props);
        this.userValidator = userValidator;
    }


    /**
     * Function to find an User from the database
     * @param integer - id of the User
     * @return - the entity with the given id if it exists, null otherwise
     * @throws IllegalArgumentException - if the id is null
     */
    @Override
    public User findOne(Integer integer) throws IllegalArgumentException {
        logger.traceEntry("Entered FindOne : IdUser {}", integer);
        if(integer == null){
            throw  new IllegalArgumentException("User id can't be null");
        }
        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("select * from User where userId= ?")){
            prSt.setInt(1, integer);
            try(ResultSet res = prSt.executeQuery()){
                if(res.next()){
                    Integer id = res.getInt("userId");
                    String name = res.getString("name");
                    String email = res.getString("email");
                    String pass = res.getString("password");
                    logger.traceExit("Exited findOne: User");
                    return new User(id, email, name, pass);
                }
            }
        } catch (SQLException e) {
            logger.error("Error in user find ... {}", e);
            System.out.println("Error in UserDB " + e);
        }

        logger.traceExit("There is no User with the id... {}", integer);
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
    public User save(User entity) throws IllegalArgumentException, ValidatorException {
        logger.traceEntry("Entered Save User.... {}", entity);
        if(entity == null){
            throw new IllegalArgumentException("User can't be null");
        }
        userValidator.validate(entity);

        if(this.findOne(entity.getId()) != null){
            logger.info("User with given id already in repo... {}", entity.getId());
            return entity;
        }

        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("insert into User values(?, ?, ?, ?)")){
            prSt.setInt(1, entity.getId());
            prSt.setString(2, entity.getEmail());
            prSt.setString(3, entity.getName());
            prSt.setString(4, entity.getPassword());
            int ret = prSt.executeUpdate();
            if(ret == 0){
                return entity;
            }
        } catch (SQLException e) {
            logger.error("Error in User save.... {}", e);
            System.out.println("Error in UserDB "  + e);
            return entity;
        }

        logger.traceExit("User successfully saved");
        return null;
    }

    /**
     * Function to delete an entity from the repository
     * @param integer - id of the entity to be deleted
     * @return - the deleted entity if it was deleted, null otherwise
     * @throws IllegalArgumentException -if the id is null
     */
    @Override
    public User delete(Integer integer) throws IllegalArgumentException {
        logger.traceEntry("Entered User delete... {}", integer);
        if(integer == null){
            throw new IllegalArgumentException("User id can't be null");
        }

        User User = findOne(integer);
        if(User == null){
            logger.info("There is no User with id... {}", integer);
            return null;
        }

        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("delete from User where userId = ?")){
            prSt.setInt(1, integer);
            prSt.executeUpdate();
            logger.traceExit("Exited User delete.... {}", User);
            return User;
        } catch (SQLException e) {
            logger.error("Error in User delete.... {}", e);
            e.printStackTrace();
        }

        logger.info("Couldn't delete the given User ....{}", User);
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
    public User update(User entity) throws IllegalArgumentException, ValidatorException {
        logger.traceEntry("Entered Update User.... {}", entity);
        if(entity == null){
            throw new IllegalArgumentException("The updated User can't be null");
        }
        userValidator.validate(entity);

        if(this.findOne(entity.getId()) == null){
            logger.info("User with given id not in repo... {}", entity.getId());
            return entity;
        }

        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("update User set email=?, name=?, password=?" +
                " where userId = ?")){
            prSt.setInt(4, entity.getId());
            prSt.setString(1, entity.getEmail());
            prSt.setString(2, entity.getName());
            prSt.setString(3, entity.getPassword());
            int ret = prSt.executeUpdate();
            if(ret == 0){
                return entity;
            }
        } catch (SQLException e) {
            logger.error("Error in User update.... {}", e);
            System.out.println("Error in UserDB "  + e);
        }

        logger.traceExit("User successfully updated");
        return null;
    }

    /**
     * Function to get all entities from the repository
     * @return - iterable containing all entities from the repository
     */
    @Override
    public Iterable<User> findAll() {
        logger.entry("Entered in findAll Users");
        List<User> UserList = new ArrayList<>();
        Connection con = dbUtils.getConnection();
        try(PreparedStatement prSt = con.prepareStatement("select * from User")){
            try(ResultSet res = prSt.executeQuery()){
                while(res.next()){
                    Integer id = res.getInt("userId");
                    String name = res.getString("name");
                    String email = res.getString("email");
                    String pass;
                    pass = res.getString("password");

                    UserList.add(new User(id, email, name, pass));
                }
            }
        } catch (SQLException e) {
            logger.error("Error in findAll Users... {}", e);
            System.out.println("Error in db Users... " + e);
        }

        logger.traceExit("Exited findAll Users");
        return UserList;
    }

    /**
     * Function to retrieve the number of entities from the database
     * @return - number of entity in the database
     */
    @Override
    public Integer size() {
        logger.traceEntry("Entered User size");
        Connection con = dbUtils.getConnection();

        try(PreparedStatement prSt = con.prepareStatement("select count(*) as size from User")){
            try(ResultSet res = prSt.executeQuery()){
                if(res.next()){
                    logger.traceExit("Exited User size");

                    return res.getInt("size");
                }
            }
        } catch (SQLException e) {
            logger.error("Error in User size  ...{}", e);
            System.out.println("Error in User DB " + e);
        }

        logger.info("No entries in db");
        return 0;
    }
}
