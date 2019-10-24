import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Utils {

    public static ArrayList<Integer> readNumFromFile(String path){
        ArrayList<Integer> rez = new ArrayList<>();
        File file = new File(path);

        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(file));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        String st;
        while (true) {
            try {
                if ((st = br.readLine()) == null) break;
                rez.add(Integer.parseInt(String.valueOf(st.charAt(0))));
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        Collections.reverse(rez);
        return rez;
    }
}

