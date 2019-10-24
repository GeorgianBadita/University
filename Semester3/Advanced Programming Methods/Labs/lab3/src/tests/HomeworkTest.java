package tests;

import domain.entities.Homework;
import org.junit.Test;


public class HomeworkTest {

    private Homework h1 = new Homework(1, "Test Lab", 2, 5);

    @Test
    public void getDescription() {
        assert  h1.getDescription().equals("Test Lab");
    }

    @Test
    public void getCurrWeek() {
        assert Homework.getCurrWeek().equals(6);
    }

    @Test
    public void getRecvWeek() {
        assert h1.getRecvWeek().equals(2);
    }

    @Test
    public void getDeadlineWeek() {
        assert h1.getDeadlineWeek().equals(5);
    }

    @Test
    public void extendHomework() {
        h1.extendHomework();
        assert h1.getDeadlineWeek().equals(6);
    }

    @Test
    public void setDescription() {
        h1.setDescription("Another One!");
        assert h1.getDescription().equals("Another One!");
    }

    @Test
    public void setRecvWeek() {
        h1.setRecvWeek(10);
        assert h1.getRecvWeek().equals(10);
    }

    @Test
    public void setDeadlineWeek() {
        h1.setDeadlineWeek(14);
        assert h1.getDeadlineWeek().equals(14);
    }


    @Test
    public void getID() {
        assert h1.getID().equals(1);
    }

    @Test
    public void setID() {
        h1.setID(2);
        assert h1.getID().equals(2);
    }

    @Test
    public void equals(){
        assert(h1.equals(new Homework(1, "asda", 2, 3)));
    }

    @Test
    public void testToString(){
        //System.out.println(h1.toString());
        assert h1.toString().equals("H: 1 Desc: Test Lab RcW: 2 DlW: 5");
    }
}