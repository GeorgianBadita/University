package decorator_runner;

import factory_pck.Strategy;
import task_pck.MessageTask;
import task_pck.Task;
import task_runner_pck.StrategyTaskRunner;
import task_runner_pck.TaskRunner;

import java.time.LocalDateTime;

public class TestTaskRunner {
    public static void main(String[] args) {
        Task[] arr = new Task[5];
        LocalDateTime time_ = LocalDateTime.now();
        MessageTask m1 = new MessageTask("1", "abcx", "MESAJ", "Ana", "Robert", time_);
        MessageTask m2 = new MessageTask("1", "abcx", "MESAJ", "Ana", "Robert", time_);
        MessageTask m3 = new MessageTask("1", "abcx", "MESAJ", "Ana", "Robert", time_);
        MessageTask m4 = new MessageTask("1", "abcx", "MESAJ", "Ana", "Robert", time_);
        MessageTask m5 = new MessageTask("1", "abcx", "MESAJ", "Ana", "Robert", time_);
        arr[0] = m1;
        arr[1] = m2;
        arr[2] = m3;
        arr[3] = m4;
        arr[4] = m5;

        Strategy str = Strategy.valueOf(args[0]);

        TaskRunner runner = new StrategyTaskRunner(str);

        for (Task t:
                arr) {
            runner.addTask(t);
        }

        runner.executeAll();

        for (Task t:
                arr) {
            runner.addTask(t);
        }
        System.out.println("\n");
        PrinterTaskRunner pr = new PrinterTaskRunner(runner);
        pr.executeAll();
    }
}
