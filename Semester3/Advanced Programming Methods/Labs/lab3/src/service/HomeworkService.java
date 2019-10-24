package service;

import domain.entities.Homework;
import domain.validators.IllegalArgumentException;
import domain.validators.ValidatorException;
import repository.AbstractRepository;
import repository.HomeworkFileRepository;
import repository.HomeworkXMLRepository;

import java.util.Objects;
import java.util.function.Predicate;

public class HomeworkService {


    private AbstractRepository<Homework, Integer> repo;
    private Predicate<Homework> nullHomework = Objects::isNull;


    /**
     * Constructor for HomeworkService Class
     * @param r - repository of homework
     */
    public HomeworkService(AbstractRepository<Homework, Integer> r){
        this.repo = (HomeworkXMLRepository) r;
    }

    /**
     * Function which adds a student to the repository
     * @param id: Integer - id of the Homework
     * @param description: String - Homework's description
     * @param recvWeek: Integer - Homework's receiving week
     * @param deadlineWeek: String - Homework's deadline week
     * @throws ValidatorException - if the arguments are invalid
     * @throws IllegalArgumentException - if the arguments are null
     * @return null if the homework was saved, the given HomeWork otherwise
     */
    public Homework addHomework(Integer id, String description, Integer recvWeek, Integer deadlineWeek) throws ValidatorException, IllegalArgumentException {
        Homework hw = new Homework(id, description, recvWeek, deadlineWeek);
        return this.repo.save(hw);
    }

    /**
     * Function to delete a homework from the repository
     * @param id : Integer - id of the homework we want to delete
     * @throws IllegalArgumentException - if the give id is null
     * @return the deleted homework if it exists, null otherwise
     */
    public Homework deleteHomework(Integer id) throws IllegalArgumentException {
        return repo.delete(id);
    }

    /**
     * @param id - id of the homework to be searched
     * @throws IllegalArgumentException - if the give id is null
     * @return a homework if it exists, null otherwise
     */
    public Homework findHomework(Integer id) throws IllegalArgumentException {
        return this.repo.findOne(id);
    }

    /**
     * Function which returns an Iterable containing all the homeworks from repository
     * @return Iterable containing all the homework from the repository
     */
    public Iterable<Homework> getAllHw(){
        return this.repo.findAll();
    }

    /**
     * Function to get the number of homework from the repository
     * @return -number of homework from the repository
     */
    public Integer getHomeworkDim(){
        return this.repo.size();
    }

    /**
     * Extends the deadline for a given homework
     * @param id - id of the homework
     * @return - 2 if the homework doesn not exists, 1 if the homework was updated,
     * 2 otherwise
     * @throws IllegalArgumentException - if id is null
     */
    public Integer extendHomeworkServ(Integer id) throws IllegalArgumentException {
        Homework hw = this.repo.findOne(id);
        if(nullHomework.test(hw)){
            return 2;
        }
        else if(hw.getDeadlineWeek()+1 < Homework.getCurrWeek()){
            return 0;
        }
        hw.extendHomework();
        return 1;
    }
}
