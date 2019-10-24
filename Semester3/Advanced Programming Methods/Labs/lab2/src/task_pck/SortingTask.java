package task_pck;

import java.util.ArrayList;

public class SortingTask extends Task {

    private AbstractSorter abs;

    private ArrayList<Integer> taskArr;

    public SortingTask(String tID, String descr, StrategyTask s, ArrayList<Integer> inArr) {
        super(tID, descr);
        abs = SortingFactoryForTask.getInstance().createSorter(s);
        taskArr = inArr;
    }

    @Override
    public void execute() {
        ArrayList<Integer> arr = abs.sort(taskArr);
        for(Integer elem : arr){
            System.out.println(elem);
        }
    }
}
