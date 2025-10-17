import java.util.*;

// 2차원 dp 느낌 -> 훔친 경우 아닌 경우로

// dp[i][j]: i번 물건까지 훔쳤을 때 j=a의 흔적 dp[i][j] = b의 흔적  
// dp[n] -> dp[n-1] + A가 n번 훔치는 경우 or B가 훔치는 경우 
class Solution {
    public int solution(int[][] info, int n, int m) {
        int answer = n;
        int info_len = info.length;
        
        int[][] dp = new int[info_len][n];
        // dp[x][y] = m 으로 최대 흔적으로 초기화
        Arrays.stream(dp).forEach(i -> Arrays.fill(i, m));
        
        // init
        if(info[0][0] < n){
            dp[0][info[0][0]] = 0; // 0번 물건 a가 훔침
        }
        dp[0][0] = info[0][1]; // 0번 물건 b가 훔침
        
        for(int i=1; i< info_len; i++){
            for(int j=n-1; j>=0; j--){
                // i번 a가 훔친 경우, b가 훔친 경우-> 같은 a의 흔적에 b의 흔적이 더 작은 경우로 갱신
                if(j >= info[i][0]){
                    dp[i][j] = Math.min(dp[i-1][j-info[i][0]] , dp[i-1][j] + info[i][1]);
                }else{
                    // 무조건 b집어야 하는 경우
                    dp[i][j] = dp[i-1][j] + info[i][1];
                }
            }
        }
  
        // b의 흔적이 m 미만인 경우의 최소 j값이 답
        
        for(int j=0; j<n; j++){
            int val_b = dp[info_len-1][j]; 
            if( val_b < m){
                answer = Math.min(answer, j);
            }
        }        
        answer = answer != n ? answer : -1;
        return answer;
    }
}