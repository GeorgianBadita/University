package service;

import domain.entities.*;
import repository.CRUDRepository;
import repository.EntitiesRepos.ConcertDBRepository;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class FestivalService {

    private CRUDRepository<Integer, Artist> artistRepo;
    private CRUDRepository<Integer, Concert> concertRepo;
    private CRUDRepository<Integer, Location> locationRepo;
    private CRUDRepository<Integer, Ticket> ticketRepo;

    /**
     * Constructor for festival Service
     * @param artistRepo - repository for artists
     * @param concertRepo - repository for concerts
     * @param locRepo - repository for locations
     * @param ticketRepo - repository for tickets
     */
    public FestivalService(CRUDRepository<Integer, Artist> artistRepo,
                           CRUDRepository<Integer, Concert> concertRepo,
                           CRUDRepository<Integer, Location> locRepo,
                           CRUDRepository<Integer, Ticket> ticketRepo){
        this.artistRepo = artistRepo;
        this.concertRepo = concertRepo;
        this.locationRepo = locRepo;
        this.ticketRepo = ticketRepo;
    }

    /**
     * Function to get all artists from the repository
     * @return - An iterable containing all artists from the database
     */
    public Iterable<Artist> getAllArtists(){
        return artistRepo.findAll();
    }

    /**
     * Function to get all locations from the repository
     * @return - An iterable containing all locations from the database
     */
    public Iterable<Location> getAllLocations(){
        return locationRepo.findAll();
    }

    /**
     * Function to get all concerts from the repository
     * @return - An iterable containing all concerts from the database
     */
    public Iterable<Concert> getAllConcerts(){
        return concertRepo.findAll();
    }


    /**
     * Function to check if a given number of seats can be sold
     * @param concertId - ticket's concert
     * @param numOfSeats - number of seats to buy
     * @return - true if there are enough seats for the concert, false otherwise
     */
    public boolean canSellTicket(Integer concertId, Integer numOfSeats){
        Location location = null;
        Concert concert = null;
        for(Concert conc : concertRepo.findAll()){
            if(conc.getId().equals(concertId)){
                concert = conc;
                break;
            }
        }

        assert concert != null;

        for(Location loc : getAllLocations()){
            if(loc.getId().equals(concert.getLocationId())){
                location = loc;
                break;
            }
        }
        if(location == null){
            return false;
        }

        return numOfSeats <= location.getTotalSeats() - concert.getSeatsSold();
    }


    /**
     * Function to get all ConcertDTOs for main table
     * @return - a list containing all concertDTOS
     */
    public List<DTOConcert> getConcertDtos(){

        List<DTOConcert> dtoList = new ArrayList<>();
        List<Concert> concerts = new ArrayList<>();
        concertRepo.findAll().forEach(concerts::add);

        Map<Integer, List<Concert>> concertMap = concerts
                .stream()
                .collect(Collectors.groupingBy(Concert::getArtistId));

        for(Map.Entry<Integer, List<Concert>> entrySet : concertMap.entrySet()){
            Integer artistId = entrySet.getKey();
            Artist art = null;
            Location loc = null;
            for(Artist artist : artistRepo.findAll()){
                if(artistId.equals(artist.getId())){
                    art = artist;
                    break;
                }
            }
            assert art != null;
            String artistName = art.getArtistName();
            for(Concert concert : entrySet.getValue()){
                Integer locId = concert.getLocationId();
                for(Location location : locationRepo.findAll()){
                    if(locId.equals(location.getId())){
                        loc = location;
                        break;
                    }
                }

                assert  loc != null;

                String locName = loc.getLocName();
                LocalDateTime date = concert.getDate();
                Integer totalSeats = loc.getTotalSeats();
                Integer soldSeats = concert.getSeatsSold();
                DTOConcert dtoConcert = new DTOConcert(concert.getId() ,artistName, date, locName, totalSeats, soldSeats);
                dtoList.add(dtoConcert);
            }
        }
     //   dtoList.forEach(System.out::println);
        return dtoList;
    }

    /**
     * Function to filter all concerts by a given date
     * @param dateFilter - date to filter concerts by
     * @return - list containing all concerts taking place in the given date
     */
    public List<DTOConcert> getConcertDtosByDate(LocalDate dateFilter) {
        List<DTOConcert> concerts = new ArrayList<>();

        for(DTOConcert concert : this.getConcertDtos()){
            LocalDateTime concDate = concert.getDate();
            if(concDate.getDayOfMonth() == dateFilter.getDayOfMonth() &&
               concDate.getMonthValue() == dateFilter.getMonthValue()){
                concerts.add(concert);
            }
        }
        return concerts;
    }

    /**
     * Function to add a ticket into the dataBase
     * @param ticket - ticket to add
     * @return - null if the ticket was added, the given ticket otherwise
     */
    public Ticket addConcert(Ticket ticket){
        return ticketRepo.save(ticket);
    }

    /**
     * Function to add a new ticket to the data base
     * @param concert - ticket's concert
     * @param clientName - client name
     * @param now - date
     * @param numSeats - number of seats
     */
    public Ticket sellTicket(Integer concert, String clientName, LocalDate now, Integer numSeats) {
        Integer id = ticketRepo.size() + 1;
        return ticketRepo.save(new Ticket(id, concert, clientName, now, numSeats));
    }

    /**
     * Function to find a  concert by id
     * @param concert - id of the concert to be found
     * @return - the concert if it exists, null otherwise
     */
    public Concert findConcert(Integer concert) {
        return concertRepo.findOne(concert);
    }

    /**
     * Function to update a concert
     * @param newConcert - the new concert
     */
    public Concert updateConcert(Concert newConcert) {
        return concertRepo.update(newConcert);
    }
}
