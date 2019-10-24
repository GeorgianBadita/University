package user_interface.student_cmds;

import domain.entities.Student;
import domain.validators.IllegalArgumentException;
import domain.validators.ValidatorException;
import service.StudentService;
import user_interface.Command;

import java.util.Objects;
import java.util.Scanner;
import java.util.function.Predicate;

public class AddStudent implements Command {

    private StudentService stdSrv;
    private Predicate<Student> nullStudent = Objects::isNull;

    /**
     * AddStudent Command constructor
     * @param stdSrv - service for this command
     */
    public AddStudent(StudentService stdSrv){
        this.stdSrv = stdSrv;
    }

    /**
     * Function to add a student
     */
    @Override
    public void execute() {
        Scanner in = new Scanner(System.in);
        int id, gr;
        String name, email;

        System.out.println("Please give the student's Id: ");

        id = in.nextInt();
        System.out.println("Please give the student's name: ");
        in.nextLine();

        name = in.nextLine();
        System.out.println("Please give the student's group: ");
        gr = in.nextInt();

        System.out.println("Please give the student's email: ");
        in.nextLine();
        email = in.nextLine();

        try {
            Student rez = this.stdSrv.addSudent(id, name, gr, email);
            if(nullStudent.test(rez)) {
                System.out.println("\nStudentul " + name + " a fost adaugat cu succes!");
            } else{
                System.out.println("\nStudentul " + name + " deja exista!");
            }
        } catch (ValidatorException e) {
            System.out.println("\nDatele studentului sunt incorecte!");
        } catch (IllegalArgumentException e) {
            System.out.println("\nNu aveti voie sa introduceti date nule!");
        }
    }
}
