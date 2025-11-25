import java.util.*;

// 연속된 집을 털면 안된다는 뜻
// 마지막 집을 털면 -> idx 0 확인 필요 
class Solution {
    public int solution(int[] money) {
        int answer = 0;
        int money_len = money.length;
        // dp[idx] -> i번 집까지 고려했을 때 최대
        // dp -> 첫번째 집을 안턴경우, dp2 -> 첫집을 턴 경우
        int[] dp = new int[money_len+1];
        int[] dp2 = new int[money_len+1];
        
        // 첫집을 터는 경우
        dp2[0] = money[0];
        
        dp[1] = Math.max(dp[0], money[1]);
        dp2[1] = Math.max(dp2[0], money[1]);
        // O(n)
        // 이전을 안 털고 이번 걸 터는 경우 vs 이전을 털고 이번 걸 안터는 경우
        // o x x o , o x o x,  x o x o
        // i >= 2
        // i번 터는 경우 -> dp[i-2] + money[i],
        // i번 안터는 경우 -> dp[i-1]
        // 첫집을 터냐 안터냐에 따라서 마지막 집을 털 수 있나 없나 결정 
        for(int i=2; i<money_len; i++){
            // 첫집을 턴 경우는 마지막 집 털면 안된다
            if(i == money_len-1){
                dp2[i] = dp2[i-1];
            }else{
                dp2[i] = Math.max(dp2[i-2] + money[i], dp2[i-1]);
            }
            
            // 첫집을 안턴경우는 마지막 집까지 순회하면 끝 
            dp[i] = Math.max(dp[i-2] + money[i], dp[i-1]);
            // System.out.println(i + " dp val: " + dp[i]);
            // System.out.println(i + " dp2 val: " + dp2[i]);
            
        }
        answer = Math.max(dp[money_len-1], dp2[money_len-1]);
        return answer;
    }
}