import java.util.ArrayList;
import java.util.List;

public class BigNum {
    private ArrayList<Integer> num;

    /**
     * Function to convert a string into a list
     * @param strNum - string
     * @return - array lsit containing digits of the number
     */
    private ArrayList<Integer> stringToNum(String strNum){
        ArrayList<Integer> num = new ArrayList<>();
        for(int i = strNum.length() - 1; i>=0; i--){
            num.add(strNum.charAt(i) - '0');
        }
        return num;
    }

    /**
     * Constructor for BigNum class
     * @param strNum- string form of the number
     */
    public BigNum(String strNum){
        this.num = stringToNum(strNum);
    }

    /**
     * Constructor for BigNum
     * @param lst - digit list
     */
    public BigNum(ArrayList<Integer> lst){
        this.num = lst;
    }

    /**
     * Getter for num attribute
     * @return: list of digits
     */
    public ArrayList<Integer> getNum(){
        return this.num;
    }

    public void setNum(ArrayList<Integer> newNum){
        this.num = newNum;
    }

    /**
     * Overriding toString method
     * @return - string form of the number
     */
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for(int i = this.num.size() - 1; i>=0; i--){
            sb.append(num.get(i));
        }

        return sb.toString();
    }


    /**
     * Function to add two big numbers
     * @param other - other number to add to the current number
     * @param execTime
     * @return: a new Number containing the sum
     */
    public BigNum add(BigNum other, List<Double> execTime){
        int T = 0;
        ArrayList<Integer> result = new ArrayList<>();
        ArrayList<Integer> A = this.getNum();
        ArrayList<Integer> B = other.getNum();
        int max = -1, len1 = A.size(), len2 = B.size();
        if(len1 > len2){
            max = len1;
            for(int i = 0; i<len1 - len2; i++){
                B.add(0);
            }
        }else{
            max = len2;
            for(int i = 0; i<len2 - len1; i++){
                A.add(0);
            }
        }
        long startTime = System.currentTimeMillis();
        for(int i = 0; i<max; i++){
            int val = A.get(i) + B.get(i) + T;
            if(val > 9){
                T = 1;
            }else{
                T = 0;
            }
            result.add(val % 10);
        }
        long endTime = System.currentTimeMillis();
        execTime.add((double)((endTime - startTime)/(1000F)));
        BigNum resNum = new BigNum("");
        resNum.setNum(result);
        return resNum;
    }


    public BigNum mul(BigNum other, List<Double> execTime){
        int resDim = this.getNum().size() + other.getNum().size() - 1;
        ArrayList<Integer> result = new ArrayList<>();
        for(int i = 0; i<resDim; i++){
            result.add(0);
        }

        ArrayList<Integer> A = this.getNum();
        ArrayList<Integer> B = other.getNum();
        double start = System.currentTimeMillis();
        for(int i = 0; i<A.size(); i++){
            for(int j = 0; j<B.size(); j++){
                result.set(i + j, result.get(i + j) + A.get(i) * B.get(j));
            }
        }
        int T = 0;
        for(int i = 0; i<result.size(); i++){
            result.set(i, result.get(i) + T);
            T = result.get(i) / 10;
            result.set(i, result.get(i) % 10);
        }

        if(T != 0) {result.add(T);}
        double end = System.currentTimeMillis();
        execTime.add((double)(end - start)/(1000F));
        return new BigNum(result);
    }
}
