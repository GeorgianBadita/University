package container_pck;

import task_pck.Task;

import java.util.ArrayList;

public abstract class ContainerSuperClass {
    protected ArrayList<Task> tasks;

    public ContainerSuperClass() {
        tasks = new ArrayList<>();
    }

    public int size() {
        return tasks.size();
    }

    public boolean isEmpty() {
        return tasks.isEmpty();
    }
}
