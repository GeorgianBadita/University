package user_interface.grade_cmds;

import service.GradeService;
import user_interface.Command;

public class PrintGrCmd implements Command {

    private GradeService grService;

    /**
     * Constructor for PrintGrCmd class
     * @param grSrv - gradeService
     */
    public PrintGrCmd(GradeService grSrv) {
        this.grService = grSrv;
    }

    @Override
    public void execute() {
        this.grService.getAllGradesSrv().forEach(System.out::println);
    }
}
