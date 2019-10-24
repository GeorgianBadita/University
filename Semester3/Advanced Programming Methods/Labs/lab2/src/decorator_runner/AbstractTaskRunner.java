package decorator_runner;

import task_pck.Task;
import task_runner_pck.TaskRunner;

public class AbstractTaskRunner implements TaskRunner {

    private TaskRunner tRunner;

    public AbstractTaskRunner(TaskRunner t){
        tRunner = t;
    }


    @Override
    public void executeOneTask() {
        tRunner.executeOneTask();
    }

    @Override
    public void executeAll() {
        tRunner.executeAll();

    }

    @Override
    public void addTask(Task t) {
        tRunner.addTask(t);
    }

    @Override
    public boolean hasTask() {
        return tRunner.hasTask();
    }
}
