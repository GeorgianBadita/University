package service;

import domain.entities.Student;
import domain.validators.IllegalArgumentException;
import domain.validators.ValidatorException;
import repository.AbstractRepository;
import repository.StudentFileRepository;
import repository.StudentXMLRepository;

import java.util.Objects;
import java.util.function.Predicate;

public class StudentService {

    private AbstractRepository<Student, Integer> repo;


    /**
     * Constructor for StudentService Class
     * @param r - repository of students
     */
    public StudentService(AbstractRepository<Student, Integer> r){
        this.repo = (StudentXMLRepository) r;
    }

    /**
     * Function which adds a student to the repository
     * @param id: Integer - id of the student
     * @param name: String - Student's name
     * @param group: Integer - Student's group
     * @param email: String - Student's email
     * @throws ValidatorException - if the arguments are invalid
     * @throws IllegalArgumentException - if the arguments are null
     * @return null if the student was saved, the given Student otherwise
     */
    public Student addSudent(Integer id, String name, Integer group, String email) throws ValidatorException, IllegalArgumentException {
        Student st = new Student(id, name, group, email);
        return this.repo.save(st);
    }

    /**
     * Function to delete a student from the repository
     * @param id: Integer - id of the students we want to delete
     * @throws IllegalArgumentException - if the give id is null
     * @return the deleted student if it exists, null otherwise
     */
    public Student deleteStudent(Integer id) throws IllegalArgumentException {
        return repo.delete(id);
    }

    /**
     * @param id - id of the student to be searched
     * @throws IllegalArgumentException - if the give id is null
     * @return a student if it exists, null otherwise
     */
    public Student findStudent(Integer id) throws IllegalArgumentException {
        return this.repo.findOne(id);
    }

    /**
     * Function which returns an Iterable containing all the students from repository
     * @return Iterable containing all the students from the repository
     */
    public Iterable<Student> getAllSt(){
        return this.repo.findAll();
    }

    /**
     * Function to get the number of students from the repository
     * @return -number of students from the repository
     */
    public Integer getStudentDim(){
        return this.repo.size();
    }
}
