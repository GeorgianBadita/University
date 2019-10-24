package user_interface;

import domain.validators.IllegalArgumentException;
import domain.validators.ValidatorException;

public interface Command{

    /**
     *  Function for executing a command, every command must implement this interface
     */
    void execute();
}
