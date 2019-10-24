import domain.entities.*;
import domain.validator.*;

import repository.EntitiesRepos.*;
import utils.DateUtils;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.time.LocalDate;
import java.util.Properties;

public class Main {
    public static void main(String[] args) {
        Properties props = new Properties();

    /*
        try {
            props.load(new FileInputStream("bd.config"));
            LocationDBRepo locRepo = new LocationDBRepo(props, new LocationValidator());
            Location res = locRepo.save(new Location(6, "yey", 120));
            //System.out.println("========================" +locRepo.size());
            //locRepo.update(new Location(6, "A", 100));
            for(Location loc : locRepo.findAll()){
                System.out.println("==============================" + loc.getId());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    */
    /*
       try{

           props.load(new FileInputStream("bd.config"));

           ArtistDBRepo artistDBRepo = new ArtistDBRepo(props, new ArtistValidator());
           System.out.println("=================================== " + artistDBRepo.save(new Artist(1, "Mihai")));
           System.out.println("=================================== " + artistDBRepo.update(new Artist(1, "Mihai")));
           System.out.println("=================================== " + artistDBRepo.size() );
           System.out.println("==================================== " + artistDBRepo.delete(1));
           artistDBRepo.findAll().forEach(x -> System.out.println("================================== " + x));

       } catch (IOException e) {
           e.printStackTrace();
       }
       */

    /*
        try{
            props.load(new FileInputStream("bd.config"));
            ConcertDBRepository concertDBRepository = new ConcertDBRepository(props, new ConcertValidator());
            System.out.println("======================================== " + concertDBRepository.save(new Concert(1, 3, 1, DateUtils.getDateFromString("2000-06-12 12:53"), ConcertType.HOUSE, 120)));
            System.out.println("======================================== " + concertDBRepository.update(new Concert(21, 3, 1, DateUtils.getDateFromString("2002-06-12 12:53"), ConcertType.HOUSE, 120)));
            System.out.println("===================================== " + concertDBRepository.size());
            System.out.println("========================================" + concertDBRepository.findOne(1));
        } catch (IOException e) {
            e.printStackTrace();
        }

       */
        /*
        try{
            props.load(new FileInputStream("bd.config"));
            UserDBRepository userDBRepository = new UserDBRepository(props, new UserValidator());
            System.out.println("============================= " + userDBRepository.save(new User(4, "geo@gmail.conmm", "Geo", "win123")));
            System.out.println("============================= " + userDBRepository.update(new User(1, "a@gmail.com", "Alinasdasda", "asd")));
           // System.out.println("============================= " + userDBRepository.delete(1));
            System.out.println("============================= " + userDBRepository.size());
        } catch (IOException e) {
            e.printStackTrace();
        }
        */

    /*
        try {
            props.load(new FileInputStream("bd.config"));
            TicketDBRepository ticketDBRepository = new TicketDBRepository(props, new TicketValidator());
            System.out.println("============================" + ticketDBRepository.save(new Ticket(1, 1, "Andrei Mihai", LocalDate.now(), 5)));
            //System.out.println(ticketDBRepository.delete(1));
            //System.out.println(ticketDBRepository.findOne(1));
            ticketDBRepository.findAll().forEach(System.out::println);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        */
    }
}
