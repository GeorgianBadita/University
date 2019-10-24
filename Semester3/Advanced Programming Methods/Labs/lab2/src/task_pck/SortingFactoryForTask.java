package task_pck;

public class SortingFactoryForTask implements FactoryForTask {

    private SortingFactoryForTask() {};
    private static SortingFactoryForTask instance;

    static SortingFactoryForTask getInstance(){
        if(instance == null){
           instance = new SortingFactoryForTask();
        }
        return instance;
    }

    @Override
    public AbstractSorter createSorter(StrategyTask s) {
        if(s == StrategyTask.BUBBLE){
            return new BubbleSort();
        }else if(s == StrategyTask.QUICK){
            return new QuickSort();
        }
        return null;
    }
}
