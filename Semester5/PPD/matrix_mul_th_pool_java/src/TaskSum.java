import java.util.ArrayList;

public class TaskSum implements Runnable {
    private Integer[][] A;
    private Integer[][] B;
    private Integer[][] C;
    private Integer ind;
    private Integer n;
    private Integer step;

    public TaskSum(Integer[][] a, Integer[][] b, Integer[][] c, Integer ind, Integer n, Integer step) {
        A = a;
        B = b;
        C = c;
        this.ind = ind;
        this.n = n;
        this.step = step;
    }

    @Override
    public void run() {
        int tNum = ind;

        int line = tNum / n;
        int col = tNum % n;

        while(line < n){
            C[line][col] = A[line][col] + B[line][col];
            tNum += step;
            line = tNum / n;
            col = tNum % n;
        }
    }
}
