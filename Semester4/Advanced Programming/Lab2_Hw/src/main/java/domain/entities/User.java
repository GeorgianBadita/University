package domain.entities;

import domain.IHasId;

public class User implements IHasId<Integer> {
    private Integer useId;
    private String email;
    private String name;
    private String password;


    /**
     * Constructor for User class
     * @param useId - id of the user
     * @param email - email of the user
     * @param name - name of the user
     * @param password - password of the user
     */
    public User(Integer useId, String email, String name, String password){
        this.useId = useId;
        this.name = name;
        this.email = email;
        this.password = password;
    }

    /**
     * Getters and setters
     */
    @Override
    public Integer getId() {
        return this.useId;
    }

    @Override
    public void setId(Integer integer) {
        this.useId = integer;
    }

    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }

    public String getPassword() {
        return password;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    /**
     * Overriding equals method
     * @param ot - other object to compare
     * @return - true if the objects are equal, false otherwise
     */
    @Override
    public boolean equals(Object ot){
        if(ot == null){
            return false;
        }

        if(this == ot){
            return true;
        }

        if(this.getClass() != ot.getClass()){
            return false;
        }

        return this.getId().equals(((User)ot).getId());
    }
}
