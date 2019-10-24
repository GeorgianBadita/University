package domain.exceptions;

public class IllegalArgumentException extends RuntimeException {

    /**
     * Function to throw IllegalArgumentException
     * @param str - string to be thrown
     */
    public IllegalArgumentException(String str){
        super(str);
    }
}
