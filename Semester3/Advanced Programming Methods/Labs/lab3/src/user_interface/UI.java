package user_interface;

import java.util.Scanner;
import java.util.function.Predicate;

public interface UI {

    Predicate<String> moreThanOne = x -> x.length() > 1;

    /**
     * Function to print a menu
     */
    void printMenu();

    /**
     * Function to run the UI
     */
    void run();


    /**
     * Function to read a command
     * @return - the read command
     */
    static String readCmd(){
        String str;
        Scanner sc = new Scanner(System.in);
        str = sc.nextLine();
        return str;
    }
}
