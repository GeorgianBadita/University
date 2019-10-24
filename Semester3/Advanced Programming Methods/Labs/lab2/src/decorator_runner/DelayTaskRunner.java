package decorator_runner;

import task_runner_pck.TaskRunner;

public class DelayTaskRunner extends AbstractTaskRunner {

    public DelayTaskRunner(TaskRunner t) {
        super(t);
    }

    @Override
    public void executeOneTask(){
        try {
            Thread.sleep(3000);
            super.executeOneTask();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void executeAll(){
        while (super.hasTask()){
            executeOneTask();
        }
    }
}
