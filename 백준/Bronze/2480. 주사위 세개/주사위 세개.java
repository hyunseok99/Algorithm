
import java.io.*;
import java.util.Arrays;
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
            int[] nums = new int[str.length];
            for (int i = 0; i < str.length; i++) {
                nums[i] = Integer.parseInt(str[i]);
            }
            int stack = 0;
            if (nums[0] == nums[1]){
                stack++;
            }
            if (nums[1] == nums[2]){
                stack++;
            }
            if (nums[0] == nums[2]){
                stack++;
            }

            int ans = -1;
            Arrays.sort(nums);
            switch (stack) {
                case 0:
                    ans = nums[2]*100;
                    break;
                case 1:
                    if (nums[0] == nums[1] || nums[1] == nums[2]) {
                        ans = 1000+100*nums[1];
                    } else {
                        ans = 1000+100*nums[0];
                    }
                    break;
                case 3:
                    ans = 10000+1000*nums[0];
                    break;
            }
            bwr.write(Integer.toString(ans));
            bwr.flush();
            bwr.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
