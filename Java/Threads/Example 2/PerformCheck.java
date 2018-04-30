import java.util.concurrent.locks.ReentrantLock;
public class PerformCheck implements Runnable
{
    String parameter;
    ReentrantLock lock = new ReentrantLock();
    PerformCheck(String parameter)
    {
        this.parameter = parameter;
    }
    public void run()
    {
        lock.lock();
        System.out.println("Checking for "+parameter);
        lock.unlock();
    }
}