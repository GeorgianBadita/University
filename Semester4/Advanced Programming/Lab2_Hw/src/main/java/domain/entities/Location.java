package domain.entities;

import domain.IHasId;

public class Location implements IHasId<Integer> {
    private Integer locationId;
    private String locName;
    private Integer totalSeats;


    /**
     *
     * @param locId - id of the location
     * @param locName - name of the location
     * @param totalSeats - number of seats in location
     */
    public Location(Integer locId, String locName, Integer totalSeats){
       this.locationId = locId;
       this.locName = locName;
       this.totalSeats = totalSeats;
    }


    /**
     * Getters and setters
     */
    @Override
    public Integer getId() {
        return locationId;
    }

    @Override
    public void setId(Integer integer) {
        this.locationId = integer;
    }

    public Integer getTotalSeats() {
        return totalSeats;
    }

    public String getLocName() {
        return locName;
    }

    public void setLocName(String locName) {
        this.locName = locName;
    }

    public void setTotalSeats(Integer totalSeats) {
        this.totalSeats = totalSeats;
    }

    /**
     * Function to check if two locations are equal
     * @param ot - object to be compared with
     * @return - true fi the objects are equal, false otherwise
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

        Location loc = (Location)ot;

        return loc.getId().equals(this.getId()) &&
               loc.getLocName().equals(this.getLocName()) &&
               loc.getTotalSeats().equals(this.getTotalSeats());
    }
}
