public class Student {
    private String name;
    private Address adr;


    public Student(String name, Address adr){
        this.name = name;
        this.adr = adr;

    }

    public String getName() {
        return name;
    }

    public Address getAdr() {
        return adr;
    }
}
