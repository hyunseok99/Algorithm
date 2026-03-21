import java.util.*;
// dp[a][b] = dp[c][d] 
// max 

class Solution {
    public int solution(int[] cookie) {
        int answer = 0;
        int n = cookie.length;
        // sum[x][y]: x y 까지의 누적합 -> 최대 길이 이용해서 x~y, y~z 최대 찾기
        // O(n^2) 투포인터 돌리면될 듯  
        
        for(int pivot = 0; pivot < n-1; pivot++){
            int left = pivot;
            int right = pivot+1;
            int leftSum = cookie[left];
            int rightSum = cookie[right];
            
            while(true){
                if(leftSum == rightSum){
                    answer = Math.max(answer, leftSum);
                }
                
                if(leftSum <= rightSum && left > 0){
                    leftSum += cookie[left-1];
                    left--;
                }else if(leftSum > rightSum && right < n-1){
                    rightSum += cookie[right+1];
                    right++;
                }else{
                    break;
                }
            }
        }
        
        return answer;
    }
}