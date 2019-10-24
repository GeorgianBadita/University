package utils;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class DateUtils {

    /**
     * Function to get a localdateTime from a string
     * @param date - string of form "1986-04-08 12:30" YYYY-MM-DD HH:MM
     * @return
     */
    public static LocalDateTime getDateFromString(String date){
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm");
        return LocalDateTime.parse(date, formatter);
    }
}
