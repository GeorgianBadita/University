package container_pck;

import task_pck.Task;

public interface Container {
    Task remove();
    void add(Task t);
    int size();
    boolean isEmpty();
}
