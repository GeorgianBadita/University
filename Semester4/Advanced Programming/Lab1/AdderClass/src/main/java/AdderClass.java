public class AdderClass {
    public int a;

    public AdderClass(int a){
        this.a = a;
    }

    public AdderClass add(AdderClass b1){
        this.a += b1.a;
        return this;
    }

    public AdderClass subtract(AdderClass b1){
        this.a -= b1.a;
        return this;
    }
}
