package task_pck;

public abstract class Task {
    private String taskID;
    private String descriere;

    public Task(String tID, String descr){
        this.taskID = tID;
        this.descriere = descr;
    }

    public String getTaskID() {
        return this.taskID;
    }

    public String getDescriere(){
        return this.descriere;
    }

    public void setTaskID(String newID){
        this.taskID = newID;
    }

    public void setDescriere(String newDesc){
        this.descriere = newDesc;
    }

    public abstract void execute();

    @Override
    public String toString(){
        return "id = " + this.taskID + "| description= " + this.descriere + "|";
    }
}
