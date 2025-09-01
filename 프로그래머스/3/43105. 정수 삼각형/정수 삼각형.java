import java.util.*;

class Solution {
    static int answer=0;
    public int solution(int[][] triangle) {
        // max < 5,000,000
        answer = 0;
        getDP(triangle);
        return answer;
    }
    
    static void getDP(int [][] triangle){
        int[][] dp = new int[triangle.length][triangle.length+1];
        // dp[0][0] = 7 -> dp[1][0], dp[1][1]
        dp[0][0] = triangle[0][0]; // 0 > 0,1 1> 1,2
        for(int depth = 0; depth < triangle.length-1; depth++){
            for(int i=0; i<triangle[depth].length; i++){
                // 왼
                dp[depth+1][i] = Math.max(dp[depth+1][i], dp[depth][i] + triangle[depth+1][i]);
                // 오
                dp[depth+1][i+1] = Math.max(dp[depth+1][i+1], dp[depth][i] +triangle[depth+1][i+1]);
            }
        }
        // 최대값 
        for(int i=0; i<=triangle.length; i++){
            answer = Math.max(answer, dp[triangle.length-1][i]);
        }
        
    }
}