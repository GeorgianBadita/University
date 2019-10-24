package tests;

import domain.entities.Grade;
import domain.entities.Homework;
import domain.validators.GradeValidator;
import domain.validators.HomeworkValidator;
import domain.validators.IllegalArgumentException;
import domain.validators.ValidatorException;
import javafx.util.Pair;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import repository.GradeFileRepository;
import repository.HomeworkFileRepository;

import java.io.PrintWriter;
import java.util.Iterator;

import static org.junit.Assert.*;

public class GradeFileRepositoryTest {

    private GradeFileRepository repo = new GradeFileRepository(new GradeValidator(), "/home/geo/Desktop/Metode avansate/lab3/src/tests/GradeTestFile.txt");
    private Grade g1 = new Grade(1, 2, 9.7, "Mircea", "Binisor");
    private Grade g2 = new Grade(2, 1, 4.5, "Camelia", "Aia da!");
    private Grade g3 = new Grade(3, 6, 5.6, "Vlad Ionescu", "Mai baga!");

    @Before
    public void setUp() throws Exception {
        repo.save(g1);
        repo.save(g2);
        repo.save(g3);

    }

    @After
    public void tearDown() throws  Exception{
        PrintWriter pw = new PrintWriter("/home/geo/Desktop/Metode avansate/lab3/src/tests/GradeTestFile.txt");
        pw.write("");
        pw.close();
    }

    @Test
    public void findOne() throws IllegalArgumentException {
        assert repo.findOne(new Pair<>(1, 2)).equals(g1);
        try{
            repo.findOne(null);
            assert false;
        }catch(IllegalArgumentException ex){
            assert true;
        }
    }

    @Test
    public void findAll() {
        Iterator<Grade> it = repo.findAll().iterator();
        Integer num = 0;
        while(it.hasNext()){
            num ++;
            it.next();
        }
        assert num.equals(3);
    }

    @Test
    public void save() throws ValidatorException, IllegalArgumentException {
        assert repo.save(new Grade(4, 5, 9.3,"Andreea", "Yeet!")) == null;
        assert repo.size() == 4;
        assert repo.save(new Grade(4, 5,8.8, "Ileana", "Yas")) != null;
        try{
            repo.save(new Grade(1, -2, -9.1, "", ""));
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
        repo.delete(new Pair<>(2, 1));
        assert repo.size() == 2;
    }

    @Test
    public void update() throws ValidatorException, IllegalArgumentException {
        assert repo.update(new Grade(3, 6,7.1,"Tema ASC", "Da, da")) == null;
        assert repo.size() == 3;
        Grade gr = repo.findOne(new Pair<>(3, 6));
        assert gr.getProfName().equals("Tema ASC");
        try{
            repo.update(null);
            assert false;
        }catch (IllegalArgumentException ex){
            assert true;
        }
        try{
            repo.update(new Grade(1,2, 12, "", ""));
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