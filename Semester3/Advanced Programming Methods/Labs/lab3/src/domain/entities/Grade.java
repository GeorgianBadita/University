package domain.entities;

import javafx.util.Pair;

public class Grade implements HasID<Pair<Integer, Integer>> {

    private Pair<Integer, Integer> studHwId;
    private double grade;
    private String professor;
    private String feedback;

    /**
     * Constructor for Grade class
     * @param stId - id of the student
     * @param hwId - id of the homework
     * @param grade - grade
     * @param feedback - feedback for gthe given grade
     */
    public Grade(int stId, int hwId, double grade, String profName, String feedback){
        studHwId = new Pair<>(stId, hwId);
        this.grade = grade;
        this.professor = profName;
        this.feedback = feedback;
    }

    /**
     * Getter function for Student id
     * @return - id of the student
     */
    public Integer getStudId(){
        return this.studHwId.getKey();
    }

    /**
     * Getter function for Homework Id
     * @return - id of the homework
     */
    public Integer getHwId(){
        return this.studHwId.getValue();
    }

    /**
     * Getter function for grade
     * @return - Student's grade
     */
    public double getGrade() {
        return this.grade;
    }

    /**
     * Getter method for professor name
     * @return - name of the professor
     */
    public String getProfName(){
        return this.professor;
    }

    /**
     * Getter method for grade feedback
     * @return - feedback for the current grade
     */
    public String getFeedback(){
        return this.feedback;
    }

    /**
     * Setter function for Student id
     * @param newId - new id of the student
     */
    public void setStudId(Integer newId){
        this.setID(new Pair<>(newId, this.studHwId.getValue()));
    }

    /**
     * Setter method for Homework id
     * @param newId - new id for the homework
     */
    public void setHwId(Integer newId){
        this.setID(new Pair<>(this.studHwId.getKey(), newId));
    }

    /**
     * Setter method for Students' grade
     * @param newGrade - new Grade of the Student
     */
    public void setGrade(double newGrade){
        this.grade = newGrade;
    }

    /**
     * Setter method for professor name
     * @param newName - new name of the professor
     */
    public void setPorfName(String newName){
        this.professor = newName;
    }

    /**
     * Setter mehtod for grade feedback
     * @param newFeedback - new feedback for the current grade
     */
    public void setFeedback(String newFeedback){
        this.feedback = newFeedback;
    }

    /**
     * Overriding getId method
     * @return - id of the grade
     */
    @Override
    public Pair<Integer, Integer> getID() {
        return this.studHwId;
    }

    /**
     * Overriding setId method
     * @param integerIntegerPair - new id of the grade
     */
    @Override
    public void setID(Pair<Integer, Integer> integerIntegerPair) {
        this.studHwId = integerIntegerPair;
    }

    /**
     * Overriding toString method
     * @return String form of a grade
     */
    @Override
    public String toString(){
        return "Stud: " + this.getStudId() + " Hw: " + this.getHwId() + " Gr: " +
                this.getGrade() + " Prof: " + this.getProfName() + " Feed: " + this.getFeedback();
    }

    /**
     * Overriding equals method
     * @param ot - other Grade
     * @return - true if the grades are equals, false otherwise
     */
    @Override
    public boolean equals(Object ot){
        if(ot == null){
            return false;
        }

        if(this == ot){
            return true;
        }

        if(ot.getClass() != this.getClass()){
            return false;
        }

        Grade gr = (Grade)ot;

        return gr.getStudId().equals(this.getStudId()) &&
               gr.getHwId().equals(this.getHwId());
    }
}
