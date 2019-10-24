package domain.entities;

public class Student implements HasID<Integer> {
    private Integer id;
    private String name;
    private Integer group;
    private String email;

    /**
     * Student constructor
     * @param id: Integer - id of the student
     * @param name: String - Student's name
     * @param group: Integer - Student's group
     * @param email: String - Student's email
     */
    public Student(Integer id, String name, Integer group, String email){
        this.id = id;
        this.name = name;
        this.group = group;
        this.email = email;
    }


    /***
     * Function to get the name
     * @return - name of the student
     */
    public String getName(){
        return this.name;
    }

    /***
     * Function to get the grouo
     * @return - group of the student
     */
    public Integer getGroup(){
        return this.group;
    }


    /***
     * Function to get the emial of the student
     * @return - email of the student
     */
    public String getEmail(){
        return this.email;
    }


    /**
     * Overriding methods from HasID Interface
     */
    @Override
    public Integer getID() {
        return id;
    }

    @Override
    public void setID(Integer newId) {
        this.id = newId;
    }

    /**
     * Function to set the name
     * @param newName - new name of the student
     */
    public void setName(String newName){
        this.name = newName;
    }


    /**
     * Function to set student's group
     * @param newGroup - new group for the student
     */
    public void setGroup(Integer newGroup){
        this.group = newGroup;
    }


    /**
     * Function to set the email of the student
     * @param newEmail - new email for student
     */
    public void setEmail(String newEmail){
        this.email = newEmail;
    }


    /**
     * Overriding equals method
     */
    @Override
    public boolean equals(Object ot){
        if(ot == this){
            return true;
        }
        if(ot == null){
            return false;
        }
        if(!(ot instanceof Student)){
            return false;
        }

        Student st = (Student)ot;
        return this.id.equals(st.getID());
    }

    /**
     * Overriding toString method
     */
    @Override
    public String toString(){
        return "" + this.id + " " + this.getName() + " " + this.getGroup() + " " + this.getEmail();
    }
}
