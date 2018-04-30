import java.util.concurrent.ScheduledThreadPoolExecutor;
import static java.util.concurrent.TimeUnit.*;
public class MainClass
{
    static ScheduledThreadPoolExecutor threadPool = new ScheduledThreadPoolExecutor(5);
    public static void main(String[] args)
    {
        addThreads();
        threadPool.shutdown();
    }
    static void addThreads()
    {
        threadPool.scheduleAtFixedRate(new GetTime(), 0, 1000, MILLISECONDS);
        threadPool.scheduleAtFixedRate(new PerformCheck("Mail"), 2, 2, SECONDS);
        threadPool.scheduleAtFixedRate(new PerformCheck("Calendar"), 3, 3, SECONDS);
        
        try {
            Thread.sleep(8000);
        }
        catch(InterruptedException e) {}   
    }
}