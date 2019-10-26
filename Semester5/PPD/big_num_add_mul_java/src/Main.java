import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        String pathToNum1 = "C:\\Users\\georg\\Desktop\\An3_sem1\\PPD\\Lab1_java\\src\\num_file_a.txt";
        String pathToNum2 = "C:\\Users\\georg\\Desktop\\An3_sem1\\PPD\\Lab1_java\\src\\num_file_b.txt";
        BigNum num = new BigNum(Utils.readNumFromFile(pathToNum1));
        BigNum num1 = new BigNum(Utils.readNumFromFile(pathToNum2));
        List<Double> time = new ArrayList<>();
        num.add(num1, time);
        System.out.println("Sequential add time: " + time.get(0));
        ParallelSum.parallelSumGood(num, num1, 100, time);
        System.out.println("Parallel Good add time: " + time.get(1));
        ParallelSum.parallelSumBad(num, num1, 100, time);
        System.out.println("Parallel Bad add time: " + time.get(2));
    }
}
