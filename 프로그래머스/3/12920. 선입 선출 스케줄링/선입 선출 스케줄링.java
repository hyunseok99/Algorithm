import java.util.*;

class Solution {
    public int solution(int n, int[] cores) {
        // 1. 만약 작업 개수가 코어 개수보다 적거나 같다면, 그냥 n번째 코어가 가져감
        if (n <= cores.length) {
            return n;
        }
    
        long minTime = 1;
        long maxTime = 0;
        
        // 가장 처리 속도가 느린 코어가 모든 일을 다 처리할 때가 최악의 시간
        for (int core : cores) {
            maxTime = Math.max(maxTime, (long)core * n);
        }
        
        long targetTime = 0;
        
        while (minTime <= maxTime) {
            long mid = (minTime + maxTime) / 2;
            
            long totalWork = cores.length; 
            
            for (int core : cores) {
                totalWork += (mid / core);
            }
            
            if (totalWork >= n) {
                targetTime = mid;    
                maxTime = mid - 1;   
            } else {
                minTime = mid + 1;  
            }
        }
        
        long currentWork = cores.length;
        for (int core : cores) {
            currentWork += ((targetTime - 1) / core);
        }
        
        for (int i = 0; i < cores.length; i++) {
            if (targetTime % cores[i] == 0) { 
                currentWork++;
                if (currentWork == n) {
                    return i + 1;
                }
            }
        }
        
        return 0;
    }
}
