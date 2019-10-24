package container_pck;

import task_pck.Task;

public class StackContainer extends ContainerSuperClass implements Container{

    public StackContainer(){
        super();
    }

    @Override
    public Task remove() {
        if(!tasks.isEmpty()){
            Task t = tasks.get(tasks.size() - 1);
            tasks.remove(tasks.size() - 1);
            return t;
        }
        return null;
    }

    @Override
    public void add(Task t) {
        tasks.add(t);
    }
}
