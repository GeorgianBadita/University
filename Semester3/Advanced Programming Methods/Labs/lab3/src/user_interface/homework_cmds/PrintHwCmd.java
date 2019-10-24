package user_interface.homework_cmds;

import domain.entities.Homework;
import service.HomeworkService;
import user_interface.Command;

public class PrintHwCmd implements Command {


    private HomeworkService hwSrv;


    /**
     * Constructor for PrintHwCmd class
     * @param hwSrv - homeworkService
     */
    public PrintHwCmd(HomeworkService hwSrv){
        this.hwSrv = hwSrv;
    }

    /**
     * Overriding command
     * -Function which prints the list of homework
     */
    @Override
    public void execute() {
        hwSrv.getAllHw().forEach(System.out::println);
    }
}
