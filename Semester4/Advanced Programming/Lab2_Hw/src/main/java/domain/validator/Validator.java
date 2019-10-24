package domain.validator;

public interface Validator<E> {

    /**
     * Function to validate an entity
     * @param entity - entity to be verified
     * @throws - throws exceptions if the  entity is not well defined
     */
    void validate(E entity);
}
