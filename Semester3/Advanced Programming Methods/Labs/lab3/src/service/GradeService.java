package service;

import domain.entities.Grade;
import domain.entities.Homework;
import domain.entities.Student;
import domain.validators.IllegalArgumentException;
import domain.validators.NoStudHwException;
import domain.validators.ValidatorException;
import javafx.util.Pair;
import repository.*;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Objects;
import java.util.function.Predicate;

public class GradeService {

    private AbstractRepository<Homework, Integer> hwRepo;
    private AbstractRepository<Student, Integer> studRepo;
    private AbstractRepository<Grade, Pair<Integer, Integer>> grRepo;
    private Predicate<Homework> nullHomework = Objects::isNull;
    private Predicate<Student> nullStudent = Objects::isNull;
    private Predicate<Grade> nullGrade = Objects::isNull;


    /**
     * GradeService constructor
     * @param sRepo - Student repository
     * @param hRepo - Homework repository
     * @param gRepo - Grade repository
     */
    public GradeService(AbstractRepository<Student, Integer> sRepo,
                        AbstractRepository<Homework, Integer> hRepo,
                        AbstractRepository<Grade, Pair<Integer, Integer>> gRepo){
        this.hwRepo = (HomeworkXMLRepository)hRepo;
        this.grRepo = (GradeXMLRepository)gRepo;
        this.studRepo = (StudentXMLRepository)sRepo;
    }

    /**
     * Function to add a Student into the file
     * @param stId - student id
     * @param hwId - homework id
     * @param grade - grade
     * @param profName - professor name
     * @return null if the grade was added, the grade otherwise
     * @throws IllegalArgumentException if id's are null
     * @throws ValidatorException if Grade arguments are incorrect
     */
    public Grade addGrade(Integer stId, Integer hwId, double grade, String profName, String feedback) throws IllegalArgumentException, ValidatorException {


        Grade gr = new Grade(stId, hwId, grade, profName, feedback);
        Grade cmp = this.grRepo.findOne(new Pair<>(stId, hwId));
        if(nullGrade.negate().test(cmp)){
            return gr;
        }

        Student stFound = this.studRepo.findOne(stId);
        Homework hwFound = this.hwRepo.findOne(hwId);

        if(nullStudent.test(stFound) || nullHomework.test(hwFound)){
            throw new NoStudHwException("There is no Student or no Homework with given ids!");
        }

        int diff = hwFound.getDeadlineWeek() - Homework.getCurrWeek();
        if(diff == -1 || diff == -2){
            System.out.println(diff);
            grade += (2.5d*diff);
        } else if(diff < -2){
            grade = 1.0d;
        }

        gr.setGrade(grade);

        String studFilesPath = "/home/geo/Desktop/Metode avansate/lab3/src/student_files";
        String toWrite = "Tema: " + hwId;
        toWrite += "\nNota: " + grade;
        toWrite += "\nPredata in saptamana: " + Homework.getCurrWeek();
        toWrite += "\nDeadline: " + hwFound.getDeadlineWeek();
        toWrite += "\nFeedback: " + feedback;

        try(PrintWriter pw = new PrintWriter(new FileWriter(studFilesPath + "/"+stFound.getID() + ".txt", true))) {
            pw.append(toWrite).append("\n");
        } catch (IOException e) {
            e.printStackTrace();
        }
        return this.grRepo.save(gr);
    }

    /**
     * Function to get all grades from file
     */
    public Iterable<Grade> getAllGradesSrv(){
        return this.grRepo.findAll();
    }

}
