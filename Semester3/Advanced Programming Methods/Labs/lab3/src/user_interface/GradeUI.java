package user_interface;

import service.GradeService;
import service.HomeworkService;
import service.StudentService;
import user_interface.grade_cmds.AddGrCmd;
import user_interface.grade_cmds.PrintGrCmd;

public class GradeUI implements UI {


    private GradeService grSrv;
    private StudentService stSrv;
    private HomeworkService hwSrv;

    /**
     * Constructor for GradeUI class
     * @param gSrv - gradeService
     * @param sSrv - Student Service
     * @param hSrv - HomeWork Service
     */
    public GradeUI(StudentService sSrv, HomeworkService hSrv, GradeService gSrv){
        this.grSrv = gSrv;
        this.hwSrv = hSrv;
        this.stSrv = sSrv;
    }

    /**
     * Overriding printMenu method
     */
    @Override
    public void printMenu() {
        String str = "=== Grade Menu ===\n" +
                     "1. To add a grade\n" +
                     "2. To print all grades\n" +
                     "b. To go back\n" +
                     "==================\n" +
                     "Please give a command:";
        System.out.println(str);
    }

    /**
     * Overriding run method
     */
    @Override
    public void run() {
        boolean done = false;
        while(!done){
            printMenu();
            String cmd = UI.readCmd();

            if(moreThanOne.test(cmd)){
                System.out.println("Wrong command!");
                continue;
            }

            switch (cmd.charAt(0)){
                case '1':
                    new AddGrCmd(grSrv).execute();
                    break;
                case '2':
                    new PrintGrCmd(grSrv).execute();
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
