package factory_pck;

import container_pck.Container;
import container_pck.QueueContainer;
import container_pck.StackContainer;

public class TaskContainerStrategy implements Factory {

    private TaskContainerStrategy() {}
    private static TaskContainerStrategy instance;


    public static TaskContainerStrategy getInstance(){
        if (instance == null){
            instance = new TaskContainerStrategy();
        }
        return instance;
    }



    @Override
    public Container createContainer(Strategy s) {
        if(s == Strategy.LIFO){
            return new StackContainer();
        }else if(s == Strategy.FIFO){
            return new QueueContainer();
        }
        return null;
    }
}
