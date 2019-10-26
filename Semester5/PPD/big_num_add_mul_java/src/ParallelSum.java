import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ThreadLocalRandom;

public class ParallelSum {

    public static class ParallelSumGood extends Thread{
        public boolean extra;
        private List<Integer> a;
        private List<Integer> b;
        private List<Integer> result;
        private int start;
        private int stop;


        public ParallelSumGood(List<Integer> a, List<Integer> b, List<Integer> result, int start, int stop) {
            this.a = a;
            this.b = b;
            this.result = result;
            this.start = start;
            this.stop = stop;
        }

        public void run(){

            while(start < stop){
                if(a.get(start) + b.get(start) > 9){
                    if (setValue()) return;
                    while(a.get(start) + b.get(start) == 9){
                        if (setValue()) return;
                    }
                }else{
                    if(start + 1 < result.size() && result.get(start + 1) == -1){
                        result.set(start + 1, (a.get(start + 1) + b.get(start + 1))%10);
                    }
                    start += 1;
                }
            }
        }

        private boolean setValue() {
            if(start + 1 < result.size()){
                result.set(start + 1, (a.get(start + 1) + b.get(start + 1) + 1) % 10);
            }else if(start + 1 == result.size()){
                this.extra = true;
                return true;
            }
            start += 1;
            return false;
        }

    }

    public static class ThrStep1 extends Thread {
        private List<Integer> a;
        private List<Integer> b;
        private List<Integer> result;
        private int start;
        private int step;

        public ThrStep1(List<Integer> a, List<Integer> b, List<Integer> result, int start, int step) {
            this.a = a;
            this.b = b;
            this.result = result;
            this.start = start;
            this.step = step;
        }

        public List<Integer> getResult(){
            return result;
        }

        public void run(){
            int sum;
            while (start < a.size()) {
                sum = a.get(start) + b.get(start);
                if(sum > 9){
                    result.set(start, 2);
                }else if(sum == 9){
                    result.set(start, 1);
                }else{
                    result.set(start, 0);
                }
                start += step;
            }
        }
    }

    public static class ThrStep2 extends Thread{
        private List<Integer> result;
        private int start;
        private int step;

        public ThrStep2(List<Integer> result, int start, int step) {
            this.result = result;
            this.start = start;
            this.step = step;
        }

        public List<Integer> getResult(){
            return result;
        }

        public void run(){
            while(start < result.size()){
                if(start != 0){
                    if(result.get(start) == 1){
                        result.set(start, result.get(start - 1));
                    }
                }

                start += step;
            }
        }
    }

    public static class ThrStep3 extends Thread{
        private List<Integer> result;
        private List<Integer> aux;
        private int start;
        private int step;

        public ThrStep3(List<Integer> result, List<Integer> aux, int start, int step) {
            this.result = result;
            this.aux = aux;
            this.start = start;
            this.step = step;
        }

        public List<Integer> getResult(){
            return result;
        }

        public List<Integer> getAux(){
            return aux;
        }

        public void run(){
            while(start < result.size() - 1){
                if(result.get(start) == 2){
                    aux.set(start + 1, 1);
                    int startCopy = start + 1;

                    while(startCopy < result.size() - 1 && result.get(startCopy) == 1){
                        result.set(startCopy, -5);
                        aux.set(startCopy + 1, 1);
                        startCopy += 1;
                    }
                }else if(result.get(start) != -5){
                    aux.set(start + 1, 0);
                }
                aux.set(0, 0);

                start += step;
            }
        }
    }

    public static class ThrStep4 extends Thread{
        private List<Integer> a;
        private List<Integer> b;
        private List<Integer> result;
        private List<Integer> aux;
        private int start;
        private int step;
        private boolean extra;


        public List<Integer> getA() {
            return a;
        }

        public List<Integer> getB() {
            return b;
        }

        public List<Integer> getResult() {
            return result;
        }

        public List<Integer> getAux() {
            return aux;
        }

        public int getStart() {
            return start;
        }

        public int getStep() {
            return step;
        }

        public boolean isExtra() {
            return extra;
        }

        public ThrStep4(List<Integer> a, List<Integer> b, List<Integer> result, List<Integer> aux, int start, int step) {
            this.a = a;
            this.b = b;
            this.result = result;
            this.aux = aux;
            this.start = start;
            this.step = step;
        }

        public void run(){
            while(start < a.size()){
                int sum = a.get(start) + b.get(start) + aux.get(start);
                if(start == a.size() - 1 && sum > 9){
                    extra = true;
                }
                if(sum > 9){
                    sum %= 10;
                }

                result.set(start, sum);
                start += step;
            }
        }
    }

    public static BigNum parallelSumGood(BigNum a, BigNum b, int numThreads, List<Double>execTime){
        ArrayList<Integer> A = a.getNum();
        ArrayList<Integer> B = b.getNum();
        int len1 = A.size();
        int len2 = B.size();
        if(len1 > len2){
            for(int i = 0; i<len1 - len2; i++){
                B.add(0);
            }
        }else {
            for (int i = 0; i < len2 - len1; i++) {
                A.add(0);
            }
        }
        ArrayList<Integer> result = new ArrayList<>();
        A.forEach(t -> result.add(-1));

        ArrayList<ParallelSumGood> threads = new ArrayList<>(numThreads);
        Boolean extra = Boolean.FALSE;

        int perThread = (result.size()) / numThreads;
        int diff = result.size() % numThreads;
        int start = 0;
        int stop = 0;
        long startTime = System.currentTimeMillis();
        for(int i = 0; i<numThreads; i++){
            stop = start + perThread;
            if(diff > 0){
                stop += 1;
                diff -= 1;
            }
            ParallelSumGood th = new ParallelSumGood(A, B, result, start, stop);
            threads.add(th);
            th.run();
            start = stop;
        }

        for(int i = 0; i<numThreads; i++){
            try {
                threads.get(i).join();
                extra = extra | threads.get(i).extra;
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        result.set(0, (A.get(0) + B.get(0)) % 10);
        if(extra){
            result.add(1);
        }
        long endTime = System.currentTimeMillis();
        execTime.add((double) ((endTime - startTime) / (1000F)));
        return new BigNum(result);
    }

    public static BigNum parallelSumBad(BigNum a, BigNum b, int numThreads, List<Double>execTime){
        ArrayList<Integer> A = a.getNum();
        ArrayList<Integer> B = b.getNum();
        int len1 = A.size();
        int len2 = B.size();
        if(len1 > len2){
            for(int i = 0; i<len1 - len2; i++){
                B.add(0);
            }
        }else {
            for (int i = 0; i < len2 - len1; i++) {
                A.add(0);
            }
        }
        List<Integer> result = new ArrayList<>();
        List<Integer> aux = new ArrayList<>();
        A.forEach(t->{
            result.add(-1);
            aux.add(-1);
        });

        ArrayList<ThrStep1> threads1 = new ArrayList<>(numThreads);
        ArrayList<ThrStep2> threads2 = new ArrayList<>(numThreads);
        ArrayList<ThrStep3> threads3 = new ArrayList<>(numThreads);
        ArrayList<ThrStep4> threads4 = new ArrayList<>(numThreads);
        long startTime = System.currentTimeMillis();
        boolean extra = false;
        for(int i = 0; i<numThreads; i++){
            ThrStep1 tr = new ThrStep1(A, B, result, i, numThreads);
            threads1.add(tr);
            tr.run();
        }

        for(int i = 0; i<numThreads; i++){
            try {
                threads1.get(i).join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        threads1.clear();
        for(int i = 0; i<numThreads; i++){
            ThrStep2 tr = new ThrStep2(result, i, numThreads);
            threads2.add(tr);
            tr.run();
        }

        for(int i = 0; i<numThreads; i++){
            try {
                threads2.get(i).join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        threads2.clear();

        for(int i= 0; i<numThreads; i++){
            ThrStep3 th = new ThrStep3(result, aux, i, numThreads);
            threads3.add(th);
            th.run();
        }

        for(int i = 0; i<numThreads; i++){
            try {
                threads3.get(i).join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        threads3.clear();

        for(int i = 0; i<numThreads; i++){
            ThrStep4 th = new ThrStep4(A, B, result, aux, i, numThreads);
            threads4.add(th);
            th.run();
        }

        for(int i = 0; i<numThreads; i++){
            try {
                threads4.get(i).join();
                extra = extra | threads4.get(i).isExtra();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        long endTime = System.currentTimeMillis();
        execTime.add((double)((endTime - startTime)/1000F));
        threads4.clear();
        if(extra){
            result.add(1);
        }

        return new BigNum((ArrayList<Integer>) result);
    }
}
