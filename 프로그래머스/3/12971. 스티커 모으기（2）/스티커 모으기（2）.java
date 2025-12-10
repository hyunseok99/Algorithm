import java.util.*;

// 처음 뜯는경우, 안뜯는 경우로 풀이 
// ex) 1 5 14 -> 14 
// dp[0,1][x] -> x번 sticker를 고려했을 때 최대값 
class Solution {
    int[] arr;
    int[][] dp;
    int limit;
    int len;
    public int solution(int sticker[]) {
        int answer = 0;
        
        dp = new int[2][sticker.length];
        for(int i=0; i<dp.length; i++){
            for(int j=0; j<dp[i].length; j++){
                dp[i][j] = -1;
            }
        }
        // 첫번째 스티커를 뜯는 경우, 반대의 경우 -> 마지막 스티커 처리 경우만 달라짐 
        dp[0][0] = sticker[0];
        dp[1][0] = 0;
        if(sticker.length >= 2){
            dp[0][1] = dp[0][0] + 0;
            dp[1][1] = sticker[1];
        }
        
        // dp[x+1] = dp[x-1] + sticker[x+1] or dp[x] <- 
        for(int i=2; i<sticker.length; i++){
            if(i == sticker.length-1){
                // type 0이 경우 i번 뜯지 못함 <- 이전의 최대값
                dp[0][i] = dp[0][i-1];
                dp[1][i] = Math.max(dp[1][i-1], dp[1][i-2] + sticker[i]);
            }else{
                dp[0][i] = Math.max(dp[0][i-1], dp[0][i-2] + sticker[i]);
                dp[1][i] = Math.max(dp[1][i-1], dp[1][i-2] + sticker[i]);
            }
        }
        answer = Math.max(dp[0][sticker.length-1], dp[1][sticker.length-1]);
        return answer;
    }
    
}