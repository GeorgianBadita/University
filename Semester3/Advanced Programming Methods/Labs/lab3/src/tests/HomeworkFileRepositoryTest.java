package tests;

import domain.entities.Homework;
import domain.validators.HomeworkValidator;
import domain.validators.IllegalArgumentException;
import domain.validators.ValidatorException;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import repository.HomeworkFileRepository;

import java.io.PrintWriter;
import java.util.Iterator;



public class HomeworkFileRepositoryTest {

    private HomeworkFileRepository repo = new HomeworkFileRepository(new HomeworkValidator(), "/home/geo/Desktop/Metode avansate/lab3/src/tests/HomeworkTestFile.txt");
    private Homework h1 = new Homework(1, "Test Lab", 2, 5);
    private Homework h2 = new Homework(2, "Lab 3 Fp", 3, 7);
    private Homework h3 = new Homework(3, "Lab 5 MAP", 4, 5);

    @Before
    public void setUp() throws Exception {
        repo.save(h1);
        repo.save(h2);
        repo.save(h3);

    }

    @After
    public void tearDown() throws  Exception{
        PrintWriter pw = new PrintWriter("/home/geo/Desktop/Metode avansate/lab3/src/tests/HomeworkTestFile.txt");
        pw.write("");
        pw.close();
    }

    @Test
    public void findOne() throws IllegalArgumentException {
        assert repo.findOne(1).equals(h1);
        try{
            repo.findOne(null);
            assert false;
        }catch(IllegalArgumentException ex){
            assert true;
        }
    }

    @Test
    public void findAll() {
        Iterator<Homework> it = repo.findAll().iterator();
        Integer num = 0;
        while(it.hasNext()){
            num ++;
            it.next();
        }
        assert num.equals(3);
    }

    @Test
    public void save() throws ValidatorException, IllegalArgumentException {
        assert repo.save(new Homework(4, "Tema ASC", 2, 6)) == null;
        assert repo.size() == 4;
        assert repo.save(new Homework(4, "Tema ASC", 2, 6)) != null;
        try{
            repo.save(new Homework(1, "", -1, -2));
            repo.save(null);
            assert false;
        }catch (ValidatorException | IllegalArgumentException ex){
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
       assert repo.size() == 2;
    }

    @Test
    public void update() throws ValidatorException, IllegalArgumentException {
        assert repo.update(new Homework(3, "Tema ASC", 2, 6)) == null;
        assert repo.size() == 3;
        Homework hw = repo.findOne(3);
        assert hw.getDescription().equals("Tema ASC");
        try{
            repo.update(null);
            assert false;
        }catch (IllegalArgumentException ex){
            assert true;
        }
        try{
            repo.update(new Homework(1, "", -1, -2));
            assert false;
        }catch (ValidatorException ex){
            assert true;
        }
    }

    @Test
    public void size() {
        assert repo.size() == 3;
    }
}