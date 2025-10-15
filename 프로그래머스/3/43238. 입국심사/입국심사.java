import java.util.*;

class Solution {
    public long solution(int n, int[] times) {
        Arrays.sort(times);
        int last_idx = times.length-1;
        long answer = 0;
        long start = 0;
        long last = (long)times[last_idx] * (n);
        while(start <= last){
            // 1 3 -> 1 2
            long mid = (start + last)/2;
            if(getCalc(mid, n, times)){
                answer = mid;
                last = mid-1;
            }else{
                start = mid+1;
            }
        }
        
        return answer;
    }
    
    public boolean getCalc(long time, int n, int[] times){
        long sum = 0;
        // time동안 케어 가능한 최대의 사람 
        // 0~7,7~14,14~21,21~28 0~10,10~20 -> 몫의 합이 n 이하면 가능 
        for(int i=0; i<times.length; i++){
            sum += (time / times[i]);
            if(sum >=n) return true;
        }
        return false;
    }
}