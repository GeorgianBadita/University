package user_interface;

import service.HomeworkService;
import user_interface.homework_cmds.AddHomework;
import user_interface.homework_cmds.ExtendHW;
import user_interface.homework_cmds.PrintHwCmd;

public class HomeWorkUI implements UI {

    private HomeworkService hwSrv;


    /**
     * Constructor for HomeWorkUI class
     * @param hSrv - HomeWorkService
     */
    public HomeWorkUI(HomeworkService hSrv){
        this.hwSrv = hSrv;
    }

    /**
     * Overriding printMenu method
     */
    @Override
    public void printMenu() {
        String str = "=== HomeWorkMenu ===\n" +
                     "1. To add a homework\n" +
                     "2. To extend a deadline\n" +
                     "3. To print all homework\n" +
                     "b. To go back\n" +
                     "====================\n" +
                     "Please give a command: ";

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
                    new AddHomework(hwSrv).execute();
                    break;
                case '2':
                    new ExtendHW(hwSrv).execute();
                    break;
                case '3':
                    new PrintHwCmd(hwSrv).execute();
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
