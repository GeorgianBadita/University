package container_pck;

import task_pck.Task;

public class QueueContainer extends ContainerSuperClass implements Container {


    public QueueContainer(){
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
        tasks.add(0, t);
    }

}
