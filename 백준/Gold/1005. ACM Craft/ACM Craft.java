import java.io.*;
import java.util.ArrayList;

public class Main {
         // 문자열 입력
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String args[]) throws IOException {
        int T = Integer.parseInt(br.readLine());

        for(int i=0; i<T; i++){
            String[] str = br.readLine().split(" ");
            int n = Integer.parseInt(str[0]);
            int k = Integer.parseInt(str[1]);
            int[] time = new int[n+1];
            long[] dp = new long[n+1];
            str = br.readLine().split(" ");

            // dp의 메모이제이션이 0인 경우를 고려해야 하기에 초기화를 -1로 수행
            for(int j=1; j<=n; j++){
                dp[j] = -1;
            }

            // 건설 시간
            for(int j=1; j<=n; j++){
                time[j] = Integer.parseInt(str[j-1]);
            }

            // 규칙 설정
            // rule[y] = {a,b,c...} -> y건설에 a,b,c 건물 필요
            ArrayList<Integer>[] rule = new ArrayList[n+1];
            for(int j=1; j<=n; j++){
                rule[j] = new ArrayList<>();
            }

            for(int j=0; j<k; j++){
                str = br.readLine().split(" ");
                rule[Integer.parseInt(str[1])].add(Integer.parseInt(str[0]));
            }

            int target = Integer.parseInt(br.readLine());

            // 하향식으로 고고
            getDP(target, dp, time, rule);

            // 승리 필요 시간: target 건설 완료 시점
            long res = dp[target];
            bw.write(res + "\n");
        }

        // 최종 출력
        bw.flush();
        bw.close();
    }

    // 하향식으로 구현 -> 모두 dfs 하다보니 반복 계산 이슈 -> 메모이제이션 ㄱㄱ
    static long getDP(int cur, long[] dp, int[] time, ArrayList<Integer>[] rule){
        // dp 메모이제이션 한 경우는 return
        if(dp[cur] != -1){
            return dp[cur];
        }


        // 해당 건물 건설에 필요한 자식들 순회 하고  -> 자식들 중 최대 거리는 경우 + 자신의 건설 시간
        // ex) 1 -> 2   ->  4  => 6
        //       -> 3   ->  5
        long maxBeforeCraft = 0;
        for(int child: rule[cur]){
            maxBeforeCraft = Math.max(maxBeforeCraft, getDP(child, dp, time, rule));
        }
        // 결과 저장 및 반환
        dp[cur] = maxBeforeCraft + time[cur];
        return dp[cur];
    }
}
