package task_runner_pck;

import task_pck.Task;

public interface TaskRunner {
    void executeOneTask();

    void executeAll();

    void addTask(Task t);

    boolean hasTask();
}
