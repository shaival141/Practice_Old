import java.util.*;
import java.text.DateFormat;

public class GetTime extends Thread
{
    public void run()
    {
        Date rightNow;
        Locale currentLocale;
        DateFormat timeFormatter;
        DateFormat dateFormatter;
        String timeOutput;
        String dateOutput;
        for(int i=0;i<5;i++)
        {
            rightNow = new Date();
            currentLocale = new Locale("en");
            timeFormatter = DateFormat.getTimeInstance(DateFormat.DEFAULT, currentLocale);
            dateFormatter = DateFormat.getDateInstance(DateFormat.DEFAULT, currentLocale);
            timeOutput = timeFormatter.format(rightNow);
            dateOutput = dateFormatter.format(rightNow);

            System.out.println(timeOutput);
            System.out.println(dateOutput);
            System.out.println();

            try {
                Thread.sleep(1000);
            }
            catch (InterruptedException e) {
            }
        }
    }
}