package user_interface.grade_cmds;

import domain.entities.Grade;
import domain.validators.IllegalArgumentException;
import domain.validators.NoStudHwException;
import domain.validators.ValidatorException;
import service.GradeService;
import user_interface.Command;

import java.util.Objects;
import java.util.Scanner;
import java.util.function.Predicate;

public class AddGrCmd implements Command {

    private GradeService gradeService;
    private Predicate<Grade> nullGrade = Objects::isNull;

    /**
     * Constructor for AddGrCmd class
     * @param grSrv - GradeService
     */
    public AddGrCmd(GradeService grSrv) {
        this.gradeService = grSrv;
    }

    @Override
    public void execute() {
        Integer stId, hwId;
        double grade;
        String profName, feedback;

        Scanner sc = new Scanner(System.in);
        System.out.println("Student Id: ");
        stId = sc.nextInt();

        System.out.println("HomeWork Id: ");
        hwId = sc.nextInt();

        System.out.println("Student's grade: ");
        grade = sc.nextDouble();

        System.out.println("Professor's name: ");
        sc.nextLine();

        profName = sc.nextLine();

        System.out.println("Feedback: ");

        feedback = sc.nextLine();

        try {
            Grade gr = this.gradeService.addGrade(stId, hwId, grade, profName, feedback);
            if(nullGrade.test(gr)){
                System.out.println("The grade was added successfully!");
            }
            else{
                System.out.println("The grade already exists!");
            }
        } catch (IllegalArgumentException | ValidatorException | NoStudHwException e) {
            System.out.println(e.getMessage());
        }
    }
}
