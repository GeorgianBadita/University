import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Random;

public class Utils {
    public static Integer[][] createMatrix(int dim, boolean empty, int max_num){
        Integer[][] matrix = new Integer[dim][dim];
        for(int i = 0; i<dim; i++){
            for(int j = 0; j<dim; j++){
                if(empty){
                    matrix[i][j] = 0;
                }else {
                    matrix[i][j] = new Random().nextInt(max_num) + 1;
                }
            }
        }
        return matrix;
    }

    public static void printMatrix(Integer[][] matrix, int dim){
        for(int i = 0; i<dim; i++){
            for(int j = 0; j<dim; j++){
                System.out.print(matrix[i][j] + " ");
            }
            System.out.print("\n");
        }
    }

    public static void matrixMulSequential(Integer[][] A, Integer[][] B, Integer[][] C, int n){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                int sum = 0;
                for(int k = 0; k<n; k++){
                    sum += A[i][k] * B[k][j];
                }
                C[i][j] = sum;
            }
        }
    }

    static void matrixSumSquential(Integer[][] A, Integer[][] B, Integer[][] C, int n){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                C[i][j] = A[i][j] + B[i][j];
            }
        }
    }
}
