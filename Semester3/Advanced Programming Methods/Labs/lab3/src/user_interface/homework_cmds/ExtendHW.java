package user_interface.homework_cmds;

import domain.entities.Homework;
import domain.validators.IllegalArgumentException;
import service.HomeworkService;
import user_interface.Command;

import java.util.Scanner;

public class ExtendHW implements Command {
    private HomeworkService hwSrv;


    /**
     * Constructor for ExtendHw class
     * @param hwSrv - homeworkService
     */
    public ExtendHW(HomeworkService hwSrv){
        this.hwSrv = hwSrv;
    }

    /**
     * Overriding command
     * -Function which extends a homework
     */
    @Override
    public void execute() {
       Scanner sc = new Scanner(System.in);
       int id;
       System.out.println("Please give the id of the homework to extend: ");
       id = sc.nextInt();
        try {
            int rez = this.hwSrv.extendHomeworkServ(id);
            switch (rez){
                case 2:
                    System.out.println("There is no homework with the given id!");
                    break;
                case 1:
                    System.out.println("The homework was successfully updated!");
                    break;
                case 0:
                    System.out.println("The homework couldn't be updated!");
                    break;
            }
        } catch (IllegalArgumentException e) {
            System.out.println("Id can't be null!");
        }

    }
}
