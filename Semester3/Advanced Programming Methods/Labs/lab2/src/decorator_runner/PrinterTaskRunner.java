package decorator_runner;

import task_runner_pck.TaskRunner;

import java.time.LocalDateTime;

public class PrinterTaskRunner extends AbstractTaskRunner {

    public PrinterTaskRunner(TaskRunner t) {
        super(t);
    }

    @Override
    public void executeOneTask(){
        super.executeOneTask();
        System.out.println(LocalDateTime.now());
    }

    @Override
    public void executeAll(){
        while (super.hasTask()){
            executeOneTask();
        }
    }
}
