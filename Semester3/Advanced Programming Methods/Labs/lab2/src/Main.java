import task_pck.SortingTask;
import task_pck.StrategyTask;
import task_pck.Test;

import java.util.ArrayList;


public class Main {
    public static void main(String[] args) {
        StrategyTask s = StrategyTask.valueOf(args[0]);
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(1);
        arr.add(-1);
        arr.add(25);
        arr.add(2);
        SortingTask st = new SortingTask("asd", "asdsa", s, arr);
        st.execute();

        Test.testMessageTask();


        //Test for Queue and Stack container_pck.Container calsses
        container_pck.QueueContainer q = new container_pck.QueueContainer();
        q.add(new SortingTask("1", "asd", s, arr));
        q.add(new SortingTask("2", "asd", s, arr));
        while(!q.isEmpty()){
            System.out.println(q.remove().toString());
        }
    }
}
