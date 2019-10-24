package domain.entities;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.concurrent.TimeUnit;

public class Homework implements HasID<Integer> {

    private Integer id;
    private String description;
    private Integer recvWeek;
    private Integer deadlineWeek;

    /**
     *
     * @param id - homework Id
     * @param description - homework description
     * @param recvWeek - current receiving week
     * @param deadlineWeek - deadline week
     */
    public Homework(Integer id, String description, Integer recvWeek, Integer deadlineWeek){
        this.id = id;
        this.description = description;
        this.recvWeek = recvWeek;
        this.deadlineWeek = deadlineWeek;
    }

    /**
     * Description getter
     * @return - description of the homework
     */
    public String getDescription(){
        return this.description;
    }

    /**
     * Current Week gtter static method
     * @return - the current week
     */
    public static Integer getCurrWeek(){
        SimpleDateFormat myFormat = new SimpleDateFormat("dd MM yyyy");
        String yearStartStr = "01 10 2018";
        String nowStr = myFormat.format(new Date());

       // System.out.println(yearStartStr);
       // System.out.println(nowStr);

        Integer days = 0;
        try {

            Date yearStart =  myFormat.parse(yearStartStr);
            Date now = myFormat.parse(nowStr);
            long diff = now.getTime() - yearStart.getTime();
            days = Math.toIntExact(TimeUnit.DAYS.convert(diff, TimeUnit.MILLISECONDS));

        } catch (ParseException e) {
            e.printStackTrace();
        }

        return days/7 + 1;
    }

    /**
     * RecvWeek getter
     * @return - Receiving week
     */
    public Integer getRecvWeek(){
        return this.recvWeek;
    }

    /**
     * DeadLine Week getter
     * @return - The deadline week
     */
    public Integer getDeadlineWeek() {return this.deadlineWeek;}


    /**
       Function which extends a homework by one week
     */
    public void extendHomework() {
        if(this.deadlineWeek < 14){
            this.deadlineWeek ++;
        }
    }

    /**
     * Function to set the description
     * @param newDescription - the new Description
     */
    public void setDescription(String newDescription){
        this.description = newDescription;
    }


    /**
     * Function to set the description
     * @param newWeek - the new receiving week
     */
    public void setRecvWeek(Integer newWeek){
        this.recvWeek = newWeek;
    }

    /**
     * Function to set the deadline
     * @param newDeadline - the new Deadline Week
     */
    public void setDeadlineWeek(Integer newDeadline){
        this.deadlineWeek = newDeadline;
    }

    /**
     * Overriding Hash method
     * @return - id of the homework
     */
    @Override
    public Integer getID() {
        return this.id;
    }

    /**
     * Overriding setID method
     * @param integer - integer number, represents the new id
     */
    @Override
    public void setID(Integer integer) {
        this.id = integer;
    }


    /**
     * Overiding equals function
     * @param ot - other object
     * @return - true if ot == hw, false otherwise
     */
    @Override
    public boolean equals(Object ot){
        if(this == ot){
            return true;
        }

        if(ot == null){
            return false;
        }
        if(ot.getClass() != this.getClass()){
            return false;
        }
        Homework hw = (Homework)ot;
        return this.id.equals(hw.getID());
    }


    /**
     * Overriding toString() method
     */
    @Override
    public String toString(){
        return "H: "+this.getID() + " Desc: " + this.getDescription() + " RcW: " + this.getRecvWeek() + " DlW: " + this.getDeadlineWeek();
    }
}
