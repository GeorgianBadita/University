package domain.entities;

import domain.IHasId;

public class Artist implements IHasId<Integer> {
    private Integer artistId;
    private String artistName;


    /**
     * Constructor for Artist class
     * @param artistId - id of the artist
     * @param artistName - name of the artist
     */
    public Artist(Integer artistId, String artistName){
        this.artistId = artistId;
        this.artistName = artistName;
    }

    /**
     * Getters and setters
     */
    @Override
    public Integer getId() {
        return artistId;
    }

    @Override
    public void setId(Integer integer) {
        this.artistId = integer;
    }

    public String getArtistName() {
        return artistName;
    }

    public void setArtistName(String artistName) {
        this.artistName = artistName;
    }

    /**
     * Overriding equals method
     * @param ot - object to be compared
     * @return - true if the objects are equal, false otherwise
     */
    @Override
    public boolean equals(Object ot){
        if(ot == null){
            return false;
        }

        if(this == ot){
            return false;
        }

        if(this.getClass() != ot.getClass()){
            return false;
        }

        Artist art = (Artist)ot;
        return art.getId().equals(this.getId()) &&
               art.getArtistName().equals(this.getArtistName());
    }
}
