package user_interface;

import service.StudentService;
import user_interface.student_cmds.AddStudent;
import user_interface.student_cmds.PrintStudsCmd;

public class StudentUI implements UI {

    private StudentService stService;

    /**
     * Constructor for StudentUI Class
     * @param stService - StudentService type
     */
    public StudentUI(StudentService stService){
        this.stService = stService;
    }

    /**
     * Overriding printMenu function
     */
    @Override
    public void printMenu() {
        String str = "== Student Menu ==\n" +
                     "1. To add a student\n" +
                     "2. To print all students\n" +
                     "b. To go back\n" +
                     "===================" +
                     "\nPlease give a command:";

        System.out.println(str);
    }

    @Override
    public void run() {
        boolean done = false;

        while(!done) {
            printMenu();
            String cmd = UI.readCmd();

            if(moreThanOne.test(cmd)){
                System.out.println("Wrong command!");
                continue;
            }

            switch (cmd.charAt(0)){
                case '1':
                    new AddStudent(stService).execute();
                    break;
                case '2':
                    new PrintStudsCmd(stService).execute();
                    break;
                case 'b':
                    done = true;
                    break;
                default:
                    System.out.println("Wrong command!");
                    break;
            }
        }
    }
}
