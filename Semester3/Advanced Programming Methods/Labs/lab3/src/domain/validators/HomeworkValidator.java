package domain.validators;

import domain.entities.Homework;
import user_interface.HomeWorkUI;

import java.util.function.Predicate;


public class HomeworkValidator implements Validator<Homework> {
    /**
     *
     * @param entity - homework to pe validated
     * @throws ValidatorException - if the homework is in invalid format
     * @throws IllegalArgumentException - if homework is null
     */
    @Override
    public void validate(Homework entity) throws ValidatorException, IllegalArgumentException {
        if(entity == null){
            throw new IllegalArgumentException("Tema nu poate sa fie null!");
        }

        String err = "";

        Predicate<Homework> negativeId = x -> x.getID() < 0;
        Predicate<Homework> emptyDesc = x -> x.getDescription().equals("");
        Predicate<Homework> wrongRecvWeek = x -> x.getRecvWeek() < 1 || x.getRecvWeek() > 14;
        Predicate<Homework> wrongDeadlineWeek = x -> x.getDeadlineWeek() < 1 || x.getDeadlineWeek() > 14;
        Predicate<String> emptyErrs = x -> x.equals("");

        if(negativeId.test(entity)) {
            err += "Id must be a positive integer!\n";
        }
        if(emptyDesc.test(entity)) {
            err += "Homework Description can't be empty!! \n";
        }
        if(wrongRecvWeek.test(entity)) {
            err += "Receiving week must be an integer between  [1, 14]! \n";
        }
        if(wrongDeadlineWeek.test(entity)) {
            err += "Deadline week must be an integer between [1, 14]! \n";
        }

        if(!emptyErrs.test(err)){
            throw new ValidatorException(err);
        }
    }
}
