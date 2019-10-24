package user_interface;


import domain.validators.IllegalArgumentException;
import domain.validators.ValidatorException;
import org.jboss.arquillian.container.test.impl.client.deployment.ValidationException;
import service.GradeService;
import service.HomeworkService;
import service.StudentService;
import user_interface.grade_cmds.AddGrCmd;
import user_interface.grade_cmds.PrintGrCmd;
import user_interface.homework_cmds.AddHomework;
import user_interface.homework_cmds.ExtendHW;
import user_interface.homework_cmds.PrintHwCmd;
import user_interface.student_cmds.AddStudent;
import user_interface.student_cmds.PrintStudsCmd;

import java.util.Scanner;

public class UserInterface implements UI {

    private StudentUI stdUI;
    private HomeWorkUI hwUI;
    private GradeUI grUI;

    /**
     * Constructor for UserInterface class
     * @param sUI - StudentUI
     * @param hUI - HomeworkUI
     * @param gUI - GradeUI
     */
    public UserInterface(StudentUI sUI, HomeWorkUI hUI, GradeUI gUI){
        this.stdUI = sUI;
        this.hwUI = hUI;
        this.grUI = gUI;
    }


    /**
     * Overriding printMenu function
     */
    @Override
    public void printMenu() {
        String str = "====== Maine Menu ======\n" +
                     "1. For Students\n" +
                     "2. For Homework\n" +
                     "3. For Grades\n" +
                     "x. To exit application\n" +
                     "========================\n" +
                     "\nPlease give a command:";
        System.out.println(str);
    }

    /**
     * Overriding the run method
     */
    @Override
    public void run() {
        while(true){
            printMenu();
            String cmd = UI.readCmd();
            if (moreThanOne.test(cmd)){
                System.out.println("Wrong command!");
                continue;
            }

            switch (cmd.charAt(0)){
                case '1':
                    this.stdUI.run();
                    break;
                case '2':
                    this.hwUI.run();
                    break;
                case '3':
                    this.grUI.run();
                    break;
                case 'x':
                    System.exit(1);
                    break;
                default:
                    System.out.println("\nWrong command!");
            }
        }
    }
}
