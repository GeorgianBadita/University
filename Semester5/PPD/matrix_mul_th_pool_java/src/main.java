import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;


public class main {
    public static void main(String[] args) {
        Integer MAX_DIM = 10;

        Scanner sc = new Scanner(System.in);
        System.out.println("Give matrix dimension: ");
        int n = sc.nextInt();
        System.out.println("Give the number of threads: ");
        int numThreads = sc.nextInt();

        ExecutorService pool = Executors.newFixedThreadPool(numThreads);
        ExecutorService pool1 = Executors.newFixedThreadPool(numThreads);
        ArrayList<Runnable> tasks = new ArrayList<>();

        Integer[][] A = Utils.createMatrix(n, false, MAX_DIM);
        Integer[][] B = Utils.createMatrix(n, false, MAX_DIM);
        Integer[][] C = Utils.createMatrix(n, true, MAX_DIM);

        long start1 = System.currentTimeMillis();
        for(int i = 0; i<numThreads; i++){
            Runnable task = new TaskMul(A, B, C, i, n, numThreads);
            tasks.add(task);
        }
        tasks.forEach(pool::execute);
        pool.shutdown();
        long end1 = System.currentTimeMillis();

        double time1 = (double)((end1 - start1)/(1000F));
        System.out.println("Parallel multiplication time: " + time1 + " s");

        C = Utils.createMatrix(n, true, MAX_DIM);

        long start2 = System.currentTimeMillis();

        Utils.matrixMulSequential(A, B, C, n);
        long end2 = System.currentTimeMillis();


        double time2 = (double)((end2 - start2)/(1000F));
        System.out.println("Sequential multiplication time: " + time2 + " s");
        ArrayList<Runnable> tasks1 = new ArrayList<>();

        long start3 = System.currentTimeMillis();

        for(int i = 0; i<numThreads; i++){
            Runnable task = new TaskSum(A, B, C, i, n, numThreads);
            tasks1.add(task);
        }
        tasks1.forEach(pool1::execute);
        pool1.shutdown();
        long end3 = System.currentTimeMillis();
        double time3 = (double)((end3 - start3)/(1000F));
        System.out.println("Parallel sum time: " + time3 + " s");

        long start4 = System.currentTimeMillis();
        Utils.matrixSumSquential(A, B, C, n);
        long end4 = System.currentTimeMillis();
        double time4 = (double)((end4 - start4)/(1000F));
        System.out.println("Sequential sum time: " + time4 + " s");


    }
}
