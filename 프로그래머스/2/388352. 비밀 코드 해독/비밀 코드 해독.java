import java.util.*;

// 공통으로 가지고 있는 정수 
// 특정 정수 상태: 0,1 
// 1 갯수는 5개로 고정 
// 10 <= n <= 30 
// 30 C 5 ->n^5
class Solution {
    int answer;
    int q_len;
    int[][] quest;
    int[] res;
    boolean[] flags;
    public int solution(int n, int[][] q, int[] ans) {
        answer = 0;
        quest = q;
        res = ans;
        q_len = q.length;
        flags = new boolean[n+1];
        // 111011
        getAnsWithPermutation(n, 0, 0);
        return answer;
    }
    
    public void getAnsWithPermutation(int n, int val, int cnt){
        if(cnt >= 5){
            ArrayList<Integer> arr = new ArrayList<>();
            for(int i=1; i<=n; i++){
                if(flags[i]){
                    arr.add(i);
                }
            }
            for(int i=0; i<q_len; i++){
                int ans_val = 0;
                for(int j=0; j<5; j++){
                    // 정렬 되어 있으니 이분탐색 최적
                    // if(Collections.binarySearch(arr, quest[i][j]) >= 0){
                    //     ans_val++;
                    // }
                    if(arr.contains(quest[i][j])){
                        ans_val++;
                    }
                }
                if(ans_val != res[i]){
                    return;
                }
            }
            answer++;
            return;
        }
        // 1~n 중 5개 순열 
        
        for(int i=1; i<=n; i++){
            if(i <= val) continue;
            flags[i] = true;
            getAnsWithPermutation(n, i, cnt+1);
            flags[i] = false;
        }
        
        
    }
}