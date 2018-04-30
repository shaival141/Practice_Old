import java.util.*;

public class MainClass
{
    public static void main(String[] args)
    {
        Thread getTime = new GetTime();
        Runnable getMail = new GetMail(3);
        Runnable getMail2 = new GetMail(2);
        getTime.start();
        new Thread(getMail).start();
        new Thread(getMail2).start();
    }
}