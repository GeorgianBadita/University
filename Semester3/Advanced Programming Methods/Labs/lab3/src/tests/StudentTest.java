package tests;

import domain.entities.Student;
import org.junit.Test;

import static org.junit.Assert.*;

public class StudentTest {

    private Student st1 = new Student(1, "Badita", 221, "bmir2236@scs.ubbcluj.ro");

    @Test
    public void getName() {
        assert st1.getName().equals("Badita");
    }

    @Test
    public void getGroup() {
        assert st1.getGroup().equals(221);
    }

    @Test
    public void getEmail() {
        assert st1.getEmail().equals("bmir2236@scs.ubbcluj.ro");
    }

    @Test
    public void getID() {
        assert st1.getID().equals(1);
    }

    @Test
    public void setID() {
        st1.setID(2);
        assert st1.getID().equals(2);
    }

    @Test
    public void setName(){
        st1.setName("Balau");
        assert st1.getName().equals("Balau");
    }

    @Test
    public void setGroup(){
        st1.setGroup(222);
        assert st1.getGroup().equals(222);
    }

    @Test
    public void setEmail(){
        st1.setEmail("alabala@yahoo.com");
        assert st1.getEmail().equals("alabala@yahoo.com");
    }

    @Test
    public void equals() {
        Student st2 = new Student(1, "Badita", 221, "bmir2236@scs.ubbcluj.ro");
        assert st1.equals(st2);
    }

    @Test
    public void testToString(){
        Student st2 = new Student(1, "Badita", 221, "bmir2236@scs.ubbcluj.ro");
        assert(st2.toString().equals("1 Badita 221 bmir2236@scs.ubbcluj.ro"));
    }

}