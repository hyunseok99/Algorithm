import java.io.*;

public class Main {
    public static void main(String[] args) {
        try {
            InputStreamReader isr = new InputStreamReader(System.in);
            BufferedReader bfr = new BufferedReader(isr);
            BufferedWriter bwr = new BufferedWriter(new OutputStreamWriter(System.out));
            int num = Integer.parseInt(bfr.readLine());
            int s1,s2;
            String[] str;
            for (int i = 0; i < num; i++) {
                str = bfr.readLine().split(" ");
                s1 = Integer.parseInt(str[0]);
                s2 = Integer.parseInt(str[1]);
                bwr.write(s1+s2+"\n");
            }
            bwr.flush();
            bwr.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
