package utils;

import java.util.Random;

public class Utils {
    public static int generateInInterval(int min, int max){
        return (int) ((Math.random() * ((max - min) + 1)) + min);
    }

    public static String generateRandomString() {
        int leftLimit = 97; // letter 'a'
        int rightLimit = 122; // letter 'z'
        int targetStringLength = 10;
        Random random = new Random();

        final String s = random.ints(leftLimit, rightLimit + 1)
                .limit(targetStringLength)
                .collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append)
                .toString();
        return s;
    }
}
