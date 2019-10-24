package domain.validators;

import domain.entities.Grade;

import java.util.function.Predicate;

public class GradeValidator implements Validator<Grade> {

    /**
     * Overriding validate function for grade entity
     * @param entity - grade to be validated
     * @throws ValidatorException - if the grade is incorrect
     * @throws IllegalArgumentException - if the arguments are invalid
     */
    @Override
    public void validate(Grade entity) throws ValidatorException, IllegalArgumentException {
        if(entity == null){
            throw new IllegalArgumentException("Grade can't be null!");
        }
        String errs = "";

        Predicate<Grade> emptyProfName = (x) -> x.getProfName().equals("");
        Predicate<Grade> negativeGrade = (x) -> x.getGrade() < 0;
        Predicate<Grade> tooHighGrade = (x) -> x.getGrade() > 10;
        Predicate<Grade> negativeStId = (x) -> x.getStudId() <= 0;
        Predicate<Grade> negativeHwId = (x) -> x.getHwId() <= 0;
        Predicate<Grade> emptyFeedBack = (x) -> x.getFeedback().equals("");
        Predicate<String> emptyErrs = x -> x.equals("");

        if(emptyProfName.test(entity)){
            errs += "Professor's name can't be empty!\n";
        }
        if(negativeGrade.test(entity)){
            errs += "Grade must be a positive integer!\n";
        }
        if(tooHighGrade.test(entity)){
            errs += "Grade must be <= 10!\n";
        }
        if(negativeStId.test(entity)){
            errs += "Student id must be a positive integer!\n";
        }
        if(negativeHwId.test(entity)){
            errs += "Homework id must be a positive integer!\n";
        }
        if(emptyFeedBack.test(entity)){
            errs += "Feedback can't be empty!";
        }
        if(!emptyErrs.test(errs)){
            throw new ValidatorException(errs);
        }
    }
}
