package domain.validators;

public class ValidatorException extends Exception {

    /**
     * Constructor for StudentException class
     * @param err-string for output errors
     */
    public ValidatorException(String err){
        super(err);
    }

    /**
     * Default constructor
     */
    public ValidatorException() {}
}
