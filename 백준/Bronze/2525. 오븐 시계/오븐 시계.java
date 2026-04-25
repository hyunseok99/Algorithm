import java.io.*;

public class Main {
    public static void main(String[] args) {
        try {
            InputStreamReader isr = new InputStreamReader(System.in);
            BufferedReader bfr = new BufferedReader(isr);
            BufferedWriter bwr = new BufferedWriter(new OutputStreamWriter(System.out));
            int hour = 0,minute = 0;
            int rt;
            String[] str;
            str = bfr.readLine().split(" ");
            hour = Integer.parseInt(str[0]);
            minute = Integer.parseInt(str[1]);
            rt = Integer.parseInt(bfr.readLine());
            int total = hour*60 + minute + rt;
            int fHour,fMinute;
            fHour = total/60%24;
            fMinute = total%60;
            bwr.write(fHour+" "+fMinute);
            bwr.flush();
            bwr.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}