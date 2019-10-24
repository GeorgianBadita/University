import domain.entities.Student;
import domain.validators.*;
import domain.validators.IllegalArgumentException;
import repository.*;
import service.GradeService;
import service.HomeworkService;
import service.StudentService;
import user_interface.GradeUI;
import user_interface.HomeWorkUI;
import user_interface.StudentUI;
import user_interface.UserInterface;

public class Main {

    public static void main(String[] args) {

        //StudentFileRepository stdRepo = new StudentFileRepository(new StudentValidator(), "/home/geo/Desktop/Metode avansate/lab3/src/repository/RepoTextFiles/Students.txt");
        //HomeworkFileRepository hwRepo = new HomeworkFileRepository(new HomeworkValidator(), "/home/geo/Desktop/Metode avansate/lab3/src/repository/RepoTextFiles/Homework.txt");
        //GradeFileRepository grRepo = new GradeFileRepository(new GradeValidator(), "/home/geo/Desktop/Metode avansate/lab3/src/repository/RepoTextFiles/Grades.txt");

        StudentXMLRepository stdRepo = new StudentXMLRepository(new StudentValidator(), "/home/geo/Desktop/Metode avansate/lab3/src/repository/RepoXMLFiles/Students.xml");
        HomeworkXMLRepository hwRepo = new HomeworkXMLRepository(new HomeworkValidator(), "/home/geo/Desktop/Metode avansate/lab3/src/repository/RepoXMLFiles/Homework.xml");
        GradeXMLRepository grRepo = new GradeXMLRepository(new GradeValidator(), "/home/geo/Desktop/Metode avansate/lab3/src/repository/RepoXMLFiles/Grades.xml");


        StudentService studService = new StudentService(stdRepo);
        HomeworkService hwService = new HomeworkService(hwRepo);
        GradeService grService = new GradeService(stdRepo, hwRepo, grRepo);

        StudentUI stUI = new StudentUI(studService);
        HomeWorkUI hwUI = new HomeWorkUI(hwService);
        GradeUI grUI = new GradeUI(studService, hwService, grService);

        UserInterface ui = new UserInterface(stUI, hwUI, grUI);
        ui.run();
    }
}
