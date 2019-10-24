public class Address {
   private String street;
   private Integer number;

   public Address(String str, Integer num){
       this.street = str;
       this.number = num;
   }

    public Integer getNumber() {
        return number;
    }

    public String getStreet() {
        return street;
    }
}
