import java.util.ArrayList;
import java.util.List;

public class MainProd {
    public static void main(String[] args) {
        String pathToNum1 = "C:\\Users\\georg\\Desktop\\University\\Semester5\\PPD\\big_num_add_mul_java\\src\\num_file_a.txt";
        String pathToNum2 = "C:\\Users\\georg\\Desktop\\University\\Semester5\\PPD\\big_num_add_mul_java\\src\\num_file_b.txt";
        BigNum num = new BigNum(Utils.readNumFromFile(pathToNum1));
        BigNum num1 = new BigNum(Utils.readNumFromFile(pathToNum2));
        List<Double> time = new ArrayList<>();
        num.mul(num1, time);
        System.out.println("Sequential prod time: " + time.get(0));
        ParallelProd.multiply(num, num1, 2, time);
        System.out.println("Parallel prod  time: " + time.get(1));
    }

}
