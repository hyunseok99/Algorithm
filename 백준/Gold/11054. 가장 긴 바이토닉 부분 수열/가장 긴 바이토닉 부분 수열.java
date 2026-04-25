import java.io.*;
import java.util.*;


public class Main {
     // 문자열 입력
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n;

    public static void main(String args[]) throws IOException {
        n = Integer.parseInt(br.readLine());
        int[] inc_dp = new int[n+1];
        int[] dec_dp = new int[n+1];
        int[] arr = new int[n+1];

        String[] str = br.readLine().split(" ");
        for(int i=1; i<=n; i++){
            arr[i] = Integer.parseInt(str[i-1]);
        }

        int res = getBitonic(arr, inc_dp, dec_dp);
        bw.write(res + "");

        // 최종 출력
        bw.flush();
        bw.close();
    }

    static int getBitonic(int[] arr, int[] inc_dp, int[] dec_dp){
        // 증가하는 부분 수열, 감소하는 부분 수열을 구해서 특정 k 지점 기준으로 합의 길이 최대 선택

        for(int i=1; i<=n; i++){
            // 길이는 최소 1
            inc_dp[i] = 1;
            for(int j=1; j<i; j++){
                // 현재 원소가 이전 원소보다 크면
                if(arr[i] > arr[j]){
                    // LIS
                    inc_dp[i] = Math.max( inc_dp[i],inc_dp[j] + 1);
                }
            }
        }

        for(int i=n; i>=1; i--){
            // 길이 최소 1 보장
            dec_dp[i] = 1;
            for(int j=n; j>i; j--){
                if(arr[i] > arr[j]){
                    // LDS
                    dec_dp[i] = Math.max(dec_dp[i], dec_dp[j] + 1);
                }
            }

        }

        // LIS + LDS가 최대가 되는 지점의 합 -1
        int res = 0;
        for(int i=1; i<=n; i++){
            res = Math.max(res, inc_dp[i] + dec_dp[i]);
        }

        // 0이 아닌 경우
        if(res > 0){
            res -= 1; // 자기 자신 중복 제외
        }

        return res;
    }
}
