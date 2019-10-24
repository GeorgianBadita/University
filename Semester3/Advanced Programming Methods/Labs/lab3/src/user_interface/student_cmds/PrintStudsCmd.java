package user_interface.student_cmds;

import domain.entities.Student;
import service.StudentService;
import user_interface.Command;

public class PrintStudsCmd implements Command {


    private StudentService stdSrv;

    /**
     * PrintStudsCmd constructor class
     * @param stdSrv - Student Service
     */
    public PrintStudsCmd(StudentService stdSrv){
        this.stdSrv = stdSrv;
    }

    /**
     * Overriding command
     * -Function which prints the list of students
     */
    @Override
    public void execute() {
        stdSrv.getAllSt().forEach(System.out::println);
    }
}
