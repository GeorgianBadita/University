package domain.validators;

import domain.entities.Student;

import java.util.function.Predicate;

public class StudentValidator implements Validator<Student> {
    /**
     * Overriding validate method for student entites
     * @param entity - Student to be validated
     * @throws ValidatorException - if the student is invalid
     */
    @Override
    public void validate(Student entity) throws ValidatorException, IllegalArgumentException {
        if(entity == null){
            throw new IllegalArgumentException("Studentul nu poate fi null!");
        }
        String err = "";

        Predicate<Student> negativeId = x -> x.getID() < 0;
        Predicate<Student> emptyEmail = x -> x.getEmail().equals("");
        Predicate<Student> negativeGroup = x -> x.getGroup() <= 0;
        Predicate<Student> emptyName = x -> x.getName().equals("");
        Predicate<String> emptyErrs = x -> x.equals("");

        if(negativeGroup.test(entity)){
            err += "Id must be a positive integer!\n";
        }
        if(emptyEmail.test(entity)) {
            err += "Email can't be empty!\n";
        }
        if(negativeGroup.test(entity)){
            err += "Group must be a positive integer!";
        }
        if(emptyName.test(entity)){
            err += "Name can't be empty!\n";
        }

        if(!emptyErrs.test(err)){
            throw new ValidatorException(err);
        }
    }
}
