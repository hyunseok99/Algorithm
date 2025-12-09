import java.util.*;

class Solution {
    public int target_size = 0;
    public String solution(String number, int k) {
        String answer = "";
        target_size = number.length()-k;
        Stack<Integer> s = new Stack<>();
        // 이전 자리값 보다 더 크다면 제거
        for(int i=0; i<number.length(); i++){
            int cur = Integer.parseInt(number.substring(i,i+1));
            while(!s.isEmpty() && k > 0 && s.peek() < cur){
                s.pop();
                k--;
            }
            s.push(cur);
        }
        
        while(!s.isEmpty()){
            answer += s.pop();
        }
        
        answer = new StringBuilder(answer).reverse().toString().substring(0, target_size);
        return answer;
    }
    
}