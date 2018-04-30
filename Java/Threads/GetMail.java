import java.util.*;

public class GetMail implements Runnable
{
    int mf;
    GetMail(int mf)
    {
        this.mf=mf;
    }
    public void run()
    {
        try {
            Thread.sleep(mf*1000);
        }
        catch (InterruptedException e) {
        }
        System.out.println("Mail Checked");
    }
}