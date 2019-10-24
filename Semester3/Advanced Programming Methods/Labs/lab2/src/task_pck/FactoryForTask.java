package task_pck;

public interface FactoryForTask {
    AbstractSorter createSorter(StrategyTask s);
}


