import java.util.ArrayList;
import java.util.List;

public class ParallelProd {

    private static class ThreadMul extends Thread{
        private ArrayList<Integer> a;
        private ArrayList<Integer> b;
        private ArrayList<Integer> result;
        private int start;
        private int stop;

        public ThreadMul(ArrayList<Integer> a, ArrayList<Integer> b, ArrayList<Integer> result, int start, int stop) {
            this.a = a;
            this.b = b;
            this.result = result;
            this.start = start;
            this.stop = stop;
        }

        @Override
        public void run(){
            for(int i = start; i<stop; i++){
                int carry = 0;
                for(int j = 0; j<a.size(); j++){
                    int prod = a.get(j) * b.get(i) + carry;
                    carry = prod / 10;
                    prod = prod % 10;

                    result.set(i + j, result.get(i + j) + prod);
                }
                if(carry != 0){
                    result.set(i + b.size(), carry);
                }
            }

            int carry = 0;
            for(int i = 0; i<result.size(); i++){
                result.set(i, result.get(i) + carry);
                carry = result.get(i) / 10;
                result.set(i, result.get(i) % 10);
            }

        }
    }

    private static void addBigNumsSequential(ArrayList<Integer> A, ArrayList<Integer> B, ArrayList<Integer> result){
        int c = 0, sum = 0;
        for(int i=0;i<A.size();i++){
            sum = A.get(i) + B.get(i) + c;
            result.set(i, sum % 10);
            c = sum/10;
        }
        if(c != 0){
            result.add(1);
        }
    }

    private static void multiplyBigNumParallel(ArrayList<Integer> a, ArrayList<Integer> b, ArrayList<Integer> result, int numThreads){
        int perThread = b.size() / numThreads;
        int rem = b.size() % numThreads;
        int start = 0, stop = 0;
        ArrayList<Thread> threads = new ArrayList<>();
        ArrayList<ArrayList<Integer>> threadResults = new ArrayList<>();
        for(int i = 0; i<numThreads; i++){
            ArrayList<Integer> arr = new ArrayList<>();
            for(int j = 0; j<2*a.size(); j++){
                arr.add(0);
            }
            threadResults.add(arr);
        }

        for(int th = 0; th < numThreads; th++){
            stop = start + perThread;
            if(rem > 0){
                rem --;
                stop ++;
            }

            threads.add(new ThreadMul(a, b, threadResults.get(th), start, stop));
            start = stop;
        }


        threads.forEach(Thread::start);

        for(int th = 0; th<numThreads; th ++){
            try {
                threads.get(th).join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        for(int  th = 0; th < numThreads; th++){
            addBigNumsSequential(result, threadResults.get(th), result);
        }

    }

    public static BigNum multiply(BigNum a, BigNum b, int numThreads, List<Double> execTime){
        ArrayList<Integer> A = a.getNum();
        ArrayList<Integer> B = b.getNum();
        ArrayList<Integer> rez = new ArrayList<>();
        for(int i = 0; i<2*A.size() - 1; i++){
            rez.add(0);
        }
        double tstart = System.currentTimeMillis();
        multiplyBigNumParallel(A, B, rez, numThreads);
        double tend = System.currentTimeMillis();
        execTime.add((tend - tstart)/(1000F));
        return new BigNum(rez);
    }
}
