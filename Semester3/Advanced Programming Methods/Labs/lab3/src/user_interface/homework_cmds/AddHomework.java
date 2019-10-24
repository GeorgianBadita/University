package user_interface.homework_cmds;

import domain.entities.Homework;
import domain.validators.IllegalArgumentException;
import domain.validators.ValidatorException;
import service.HomeworkService;
import user_interface.Command;

import java.util.Objects;
import java.util.Scanner;
import java.util.function.Predicate;

public class AddHomework implements Command {

    private HomeworkService hwSrv;
    private Predicate<Homework> nullHomework = Objects::isNull;

    public AddHomework(HomeworkService hwSrv){
        this.hwSrv = hwSrv;
    }

    @Override
    public void execute() {
        Scanner in = new Scanner(System.in);
        int id, rw, dw, cw;
        String descr;

        System.out.println("Please give Homework's ID: ");
        id = in.nextInt();
        System.out.println("Please give Homework's Description: ");

        in.nextLine();
        descr = in.nextLine();
        System.out.println("Please give receiving week: ");
        rw = in.nextInt();

        System.out.println("Please give deadline week: ");
        dw = in.nextInt();


        try {
            Homework hw = this.hwSrv.addHomework(id, descr, rw, dw);
            if(nullHomework.test(hw)){
                System.out.println("\nTema " + descr + " a fost adaugata!");
            } else{
                System.out.println("\nTema " + descr + " este deja existenta!");
            }
        } catch (ValidatorException e) {
            System.out.println("Parametrii temei nu sunt corecti!");
        } catch (IllegalArgumentException e) {
            System.out.println("Argumentele nu pot fi nule!");
        }
    }
}
