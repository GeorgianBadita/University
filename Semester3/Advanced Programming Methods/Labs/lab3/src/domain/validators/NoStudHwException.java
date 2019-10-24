package domain.validators;

public class NoStudHwException extends RuntimeException {
    /**
     * Constructor for NoStudHwException class
     * @param err - error to output
     */
    public NoStudHwException(String err){
        super(err);
    }

    /**
     * Default Constructor for class
     */
    public NoStudHwException() {};
}
