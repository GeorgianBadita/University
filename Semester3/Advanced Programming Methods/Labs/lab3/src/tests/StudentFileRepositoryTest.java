package tests;

import domain.entities.Student;
import domain.validators.IllegalArgumentException;
import domain.validators.StudentValidator;
import domain.validators.ValidatorException;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import repository.AbstractRepository;
import repository.StudentFileRepository;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.Iterator;

public class StudentFileRepositoryTest {

    private String file = "/home/geo/Desktop/Metode avansate/lab3/src/tests/StudentTestFile.txt";
    private AbstractRepository<Student, Integer> repo = new StudentFileRepository(new StudentValidator(), file);
    private Student st1 = new Student(1, "Badita", 221, "bmir2236@scs.ubbcluj.ro");
    private Student st2 = new Student(2, "Bacotiu", 221, "boir1234@scs.ubbcluj.ro");
    private Student st3 = new Student(3, "Anton", 221, "amir3456@scs.ubbcluj.ro");

    @Before
    public void setUp() throws Exception {
        repo.save(st1);
        repo.save(st2);
        repo.save(st3);

    }

    @After
    public void tearDown() throws  Exception{
        PrintWriter pw = new PrintWriter(file);
        pw.write("");
        pw.close();
    }


    @Test
    public void findOne() throws IllegalArgumentException {
        assert repo.findOne(1).equals(st1);
        assert repo.findOne(5) == null;
        try{
            repo.findOne(null);
            assert false;
        }catch (IllegalArgumentException ex){
            assert true;
        }
    }

    @Test
    public void findAll() throws ValidatorException, IllegalArgumentException {
        Iterator<Student> it = repo.findAll().iterator();
        Integer num = 0;
        while(it.hasNext()){
            num ++;
            it.next();
        }
        assert num.equals(3);
    }

    @Test
    public void save() throws ValidatorException, IllegalArgumentException {
        assert repo.save(new Student(4, "Alistar", 221, "aair5121@scs.ubblcuj.ro")) == null;
        assert ((Collection<?>) repo.findAll()).size() == 4;
        assert repo.save(new Student(4, "Alistar", 221, "aair5121@scs.ubblcuj.ro")) != null;
        try{
            repo.save(new Student(-2, "", 21, ""));
            assert false;
        }catch (ValidatorException ex){
            assert true;
        }
        try {
            repo.save(null);
            assert false;
        }catch (IllegalArgumentException ex){
            assert true;
        }
    }

    @Test
    public void delete() throws ValidatorException, IllegalArgumentException {
        try{
            repo.delete(null);
            assert false;
        }catch (IllegalArgumentException ex){
            assert true;
        }
        repo.delete(2);
        assert ((Collection<?>)repo.findAll()).size() == 2;
    }

    @Test
    public void update() throws ValidatorException, IllegalArgumentException {
        assert repo.update(new Student(3, "Bot", 211, "brir2257@scs.ubbcluj.ro")) == null;
        assert ((Collection<?>)repo.findAll()).size() == 3;
        Student st = repo.findOne(3);
        assert st.getName().equals("Bot");
        try{
            repo.update(null);
            assert false;
        }catch (IllegalArgumentException ex){
            assert true;
        }
        try{
            repo.update(new Student(2, "", 12, ""));
            assert false;
        }catch (ValidatorException ex){
            assert true;
        }
    }

    @Test
    public void size() throws ValidatorException, IllegalArgumentException {
        assert repo.size() == 3;
        repo.delete(3);
        assert repo.size() == 2;
        try{
            repo.delete(null);
            assert false;
        }catch (IllegalArgumentException ex){
            assert true;
        }
    }
}