import java.util.*;

// 맨 끝에서 왼쪽 높이 보는 문제와 동일
// 오른쪽에 존재하는 크거나 같은 갯수 = 전체 - 왼쪽에 존재하는 큰 갯수
class Solution {
    public int[] solution(int[] prices) {
        int[] answer = getDur(prices);
        return answer;
    }
    
    public int[] getDur(int[] prices){
        // 가격이 떨어진다는건 -> cur < bef 
        // 2 6 5 1 2 1 6 3 6 6
        // 4 1 1 2 1 4 1 2 1 0
        // 이전 값이 더 크면  
        int[] ans = new int[prices.length];  
        Stack<Integer> s = new Stack<>(); // idx 저장
        
        for(int idx = 0; idx < prices.length; idx++){
            // 가격 하락 발생
            while(!s.empty() && prices[s.peek()] > prices[idx]){
                int prev_idx = s.pop();
                ans[prev_idx] = idx - prev_idx;
            }
            s.push(idx);
        }
        
        // 끝나고 남아있는 경우는 끝까지 하락 x
        while(!s.empty()){
            int prev_idx = s.pop();
            ans[prev_idx] = prices.length - 1 - prev_idx;
        }
        
        
        return ans;
        
    }
}