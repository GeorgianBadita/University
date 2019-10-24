package task_runner_pck;

import container_pck.Container;
import factory_pck.Strategy;
import factory_pck.TaskContainerStrategy;
import task_pck.Task;

public class StrategyTaskRunner implements TaskRunner {

    private Container taskC;

    public StrategyTaskRunner(Strategy s){
        taskC = TaskContainerStrategy.getInstance().createContainer(s);
    }

    @Override
    public void executeOneTask() {
        if(!taskC.isEmpty()){
            taskC.remove().execute();
        }
    }

    @Override
    public void executeAll() {
        while(!taskC.isEmpty()){
            executeOneTask();
        }
    }

    @Override
    public void addTask(Task t) {
        taskC.add(t);
    }

    @Override
    public boolean hasTask() {
        return !taskC.isEmpty();
    }
}
