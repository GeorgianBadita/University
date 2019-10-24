package domain.exceptions;

public class ValidatorException extends RuntimeException {

    /**
     * Constructor for ValidatorException class
     * @param err - error to be thrown
     */
    public ValidatorException(String err){
        super(err);
    }

    /**
     * Constructor with no parameters
     */
    public ValidatorException() {}
}
