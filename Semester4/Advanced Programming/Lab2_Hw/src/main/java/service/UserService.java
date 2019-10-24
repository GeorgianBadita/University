package service;

import domain.entities.User;
import repository.CRUDRepository;

public class UserService {

    private CRUDRepository<Integer, User> userRepo;

    /**
     * Constructor for UserService class
     * @param userRepo - user repository
     */
    public UserService(CRUDRepository<Integer, User> userRepo){
        this.userRepo = userRepo;
    }

    /**
     * Function to validate a login trial
     * @param userName - name of the user
     * @param pass - user password
     * @return - true if the user is in the database, false otherwise
     */
    public boolean validateLogIn(String userName, String pass){
        boolean correctLogin = false;

        for(User usr : userRepo.findAll()){
            System.out.println("================================== " + usr.getEmail());
            if(usr.getName().equals(userName) && usr.getPassword().equals(pass)){
                correctLogin = true;
            }
        }

        return correctLogin;
    }

}
