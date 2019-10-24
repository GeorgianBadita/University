package tests;

import domain.entities.Grade;
import javafx.util.Pair;
import org.junit.Test;

import static org.junit.Assert.*;

public class GradeTest {

    private Grade gr = new Grade(1, 2, 8.6, "Albert", "F bine!");

    @Test
    public void getStudId() {
        assert(gr.getStudId() == 1);
    }

    @Test
    public void getHwId() {
        assert(gr.getHwId() == 2);
    }

    @Test
    public void getID() {
        assert gr.getID().getKey() == 1;
        assert gr.getID().getValue() == 2;
    }

    @Test
    public void setID() {
        gr.setID(new Pair<>(3, 4));
        assert gr.getStudId() == 3;
        assert gr.getHwId() == 4;
    }

    @Test
    public void getGrade() {
        assert gr.getGrade() == 8.6;
    }

    @Test
    public void getProfName() {
        assert gr.getProfName().equals("Albert");
    }

    @Test
    public void getFeedback(){
        assert gr.getFeedback().equals("F bine!");
    }



    @Test
    public void setFeedback() {
        gr.setFeedback("Bine!");
        assert gr.getFeedback().equals("Bine!");
    }

    @Test
    public void setStudId() {
        gr.setStudId(4);
        assert gr.getStudId().equals(4);
    }

    @Test
    public void setHwId() {
        gr.setHwId(5);
        assert gr.getHwId().equals(5);
    }

    @Test
    public void setGrade() {
        gr.setGrade(9.1);
        assert gr.getGrade() == 9.1;
    }

    @Test
    public void setPorfName() {
        gr.setPorfName("Alin");
        assert gr.getProfName().equals("Alin");
    }

    @Test
    public void testToString(){
        String str = gr.toString();
        //System.out.println(str);
        assert str.equals("Stud: 1 Hw: 2 Gr: 8.6 Prof: Albert Feed: F bine!");
    }


}