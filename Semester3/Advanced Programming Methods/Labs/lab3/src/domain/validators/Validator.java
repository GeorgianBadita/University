package domain.validators;

/**
 * Validator Interface
 * @param <E> - Generic parameter to validate
 */
public interface Validator<E> {
    void validate(E entity) throws ValidatorException, IllegalArgumentException;
}