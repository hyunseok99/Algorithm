import java.util.*;

// 총 2종류 각각의 펄스 수열에 대해 최대값 -> 결국 절대값은 동일 -> 절댓값만 고려  
// O(n) 에 처리 필요 
// 3 -6 2  -> 3 6 2 or -3 -6 -2 
class Solution {
    public long solution(int[] sequence) {
        long answer = 0;
        // 누적합이 최대가 되는 지점, 최소가 되는 지점 이용해서 절대값 최대 
        long pulse_sum = 0;
        long max_v = 0;
        long min_v = 0;
        for(int i=0; i<sequence.length; i++){
            int pulse = (i%2 == 0) ? 1 : -1;
            pulse_sum += (long)sequence[i] * pulse;
            max_v = Math.max(max_v, pulse_sum);
            min_v = Math.min(min_v, pulse_sum);
            // System.out.println("idx: " + i + " pulse_sum: " + pulse_sum + " max_v: " + max_v + " min_v: " + min_v);
        }
        answer = max_v - min_v;
        
        return answer;
    }
    
}