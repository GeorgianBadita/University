package task_pck;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class MessageTask extends Task {
    private String mesaj;
    private String from;
    private String to;
    private LocalDateTime date;

    public MessageTask(String id, String descr, String msg, String f, String t, LocalDateTime dt){
        super(id, descr);
        this.mesaj = msg;
        this.from = f;
        this.to = t;
        DateTimeFormatter fmt = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm");
        this.date = LocalDateTime.parse(dt.format(fmt), fmt);
    }

    @Override
    public void execute() {
        System.out.println(this);
    }

    @Override
    public String toString(){
        return super.toString() + "message =  " + this.mesaj + "| from = " + this.from + "| to = " + this.to + "" +
                " date = " + this.date + " |";
    }

    @Override
    public boolean equals(Object o){
        if(this == o){
            return true;
        }
        if(o == null){
            return false;
        }

        if(this.getClass() != o.getClass()){
            return false;
        }

        MessageTask m = (MessageTask)o;
        return super.getTaskID().equals(m.getTaskID());
    }

    public String getMesaj(){
        return this.mesaj;
    }

    public String getFrom(){
        return this.from;
    }

    public String getTo(){
        return this.to;
    }

    public LocalDateTime getDate(){
        return this.date;
    }
}


