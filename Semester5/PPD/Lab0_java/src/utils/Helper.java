package utils;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.concurrent.ThreadLocalRandom;

public class Helper {
    public Helper(){}

    /**
     * Function to create a file containing random integers
     * @param path - path to the file
     * @param size - number of integers to be generated
     * @param min - min number
     * @param max - max number
     */
    public void createRandomFile(String path, int size, int min, int max){
        try(Writer writer = new BufferedWriter(new OutputStreamWriter(
                new FileOutputStream(path), StandardCharsets.US_ASCII))) {
            for(int i = 0; i<size; i++){
                int randint = ThreadLocalRandom.current().nextInt(min, max + 1);
                writer.write(randint + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Function to compare two files
     * @param path1 - path to file1
     * @param path2 - path to file2
     * @param dtype - type of fiels
     * @return - true fi the files are the same, false otherwise
     */
    public boolean compareFiles(String path1, String path2, String dtype){
        try {
            BufferedReader file1 = new BufferedReader(new FileReader(path1));
            BufferedReader file2 = new BufferedReader(new FileReader(path2));

            while(true){
                if(dtype.equals("real")){
                    String partOne = file1.readLine();
                    String partTwo = file2.readLine();
                    if(partOne == null && partTwo != null){
                        return false;
                    }
                    if(partOne != null && partTwo == null){
                        return false;
                    }
                    if(partOne == null && partTwo == null){

                        return true;
                    }
                    Double first = Double.parseDouble(partOne);
                    Double second = Double.parseDouble(partTwo);
                    if(Math.abs(first - second) > 1e-8){
                        return false;
                    }
                }
                else{
                    String partOne = file1.readLine();
                    String partTwo = file2.readLine();
                    if(partOne == null && partTwo != null){
                        return false;
                    }
                    if(partOne != null && partTwo == null){
                        return false;
                    }
                    if(partOne == null && partTwo == null){
                        return true;
                    }
                    Integer first = Integer.parseInt(partOne);
                    Integer second = Integer.parseInt(partTwo);
                    if(!first.equals(second)){
                        return false;
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return false;
    }

    /**
     * Function to write a new line to an Excel file
     * @param path - path to excel
     * @param line - line to be added
     */
    public void addLineToExcel(String path, String line){
        try {
            File file = new File(path);
            FileWriter fr = new FileWriter(file, true);
            fr.write("\n" + line);
            fr.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
