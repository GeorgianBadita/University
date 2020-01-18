package shows.server.repository;

import shows.model.*;
import java.io.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentSkipListMap;

public class Repository {
    private static final SimpleDateFormat textFormat = new SimpleDateFormat("dd.MM.yy");
    private final String file = "history.txt";

    private Map<Integer, Map<Integer, Ticket>> tickets;
    private Map<Integer, List<Ticket>> soldTickets;
    private Double sold = 0d;

    private List<Show> shows;
    private Category firstCategory;
    private Category secondCategory;
    private Category thirdCategory;

    public Repository() {
        this.firstCategory = new Category(CategoryType.BASIC, 0, 33, 15d);
        this.secondCategory = new Category(CategoryType.STANDARD, 34, 66, 50d);
        this.thirdCategory = new Category(CategoryType.VIP, 67, 99, 75d);
        soldTickets = new ConcurrentHashMap<>();
        init(3);
    }

    private void init(int noShows) {
        shows = generateShows(noShows);
        tickets = generateTickets();
        try (PrintWriter ignored = new PrintWriter(file)) {
            System.out.println("Clear log file");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private Map<Integer, Map<Integer, Ticket>> generateTickets() {
        Map<Integer, Map<Integer, Ticket>> tickets = new ConcurrentSkipListMap<>();
        shows.forEach(show -> {
            Map<Integer, Ticket> ticketsForShow = generateTicketsForShow(show);
            tickets.put(show.getId(), ticketsForShow);
        });
        return tickets;
    }

    private Map<Integer, Ticket> generateTicketsForShow(Show show) {
        Map<Integer, Ticket> ticketsForShow = new ConcurrentHashMap<>();
        for (int i = firstCategory.getStart(); i < firstCategory.getEnd(); ++i) {
            ticketsForShow.put(i, new Ticket(firstCategory, i, show.getId()));
        }for (int i = secondCategory.getStart(); i < secondCategory.getEnd(); ++i) {
            ticketsForShow.put(i, new Ticket(secondCategory, i, show.getId()));
        }for (int i = thirdCategory.getStart(); i < thirdCategory.getEnd(); ++i) {
            ticketsForShow.put(i, new Ticket(thirdCategory, i, show.getId()));
        }
        return ticketsForShow;
    }

    private List<Show> generateShows(int noShows) {
        List<Show> shows = new ArrayList<>();
        try {
            for (int i = 0; i < noShows; ++i) {
                shows.add(new Show(i, "Title " + i, textFormat.parse("01.01.20").getTime(), "Description " + 1));
                soldTickets.put(i, new ArrayList<>());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        finally {
            return shows;
        }
    }

    public synchronized void logActions() {
        try (PrintWriter printWriter = new PrintWriter(new BufferedWriter(new FileWriter(file, true)))) {
            logMessage(printWriter, "\ntickets:\n");
            logTickets(printWriter);
            logSoldTickets(printWriter);
            logMessage(printWriter, "sold: " + sold);
        } catch (IOException e1) {
            e1.printStackTrace();
        }
    }

    private synchronized void logTickets(PrintWriter printWriter) {
        logMessage(printWriter, "\navailable tickets:\n");
        tickets.forEach((key, value) -> {
            logMessage(printWriter, "\ntickets by show: " + key + "\n");
            logTicketsForShow(value, printWriter);
        });
    }

    private void logMessage(PrintWriter printWriter, String message) {
        printWriter.println(message);
        printWriter.flush();
    }

    private synchronized void logSoldTickets(PrintWriter printWriter) {
        logMessage(printWriter, "\nsold tickets:\n");
        soldTickets.forEach((key, value) -> {
            logMessage(printWriter, "\ntickets sold by show: " + key + "\n");
            logTicketsForShow(value, printWriter);
        });
    }

    private void logTicketsForShow(Map<Integer, Ticket> showTickets, PrintWriter printWriter) {
        showTickets.forEach((key, value) -> logMessage(printWriter, value.toString()));
    }

    private void logTicketsForShow(List<Ticket> showTickets, PrintWriter printWriter) {
        showTickets.forEach(ticket -> logMessage(printWriter, ticket.toString()));
    }

    public synchronized Ticket buyTicket(Sale sale) {
        Map<Integer, Ticket> ticketsAvailableForShow = tickets.get(sale.getShowId());
        Ticket ticket = ticketsAvailableForShow.get(sale.getNumber());
        if (ticket == null)
            return null;
        soldTickets.get(sale.getShowId()).add(ticket);
        ticketsAvailableForShow.remove(sale.getShowId());
        ticket.setDate(textFormat.format(new Date(System.currentTimeMillis())));
        sold += ticket.getCategory().getPrice();
        return ticket;
    }
}
