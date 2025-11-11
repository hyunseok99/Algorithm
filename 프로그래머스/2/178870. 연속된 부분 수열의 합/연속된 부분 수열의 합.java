class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = new int[2];
        // idx 까지의 sum
        int n = sequence.length;
        int max_len = n+1;
        int[] sum = new int[n+1];
        
        int start = 0;
        long cur_sum = 0;
        
        for(int end=0; end<n; end++){
            cur_sum += sequence[end];
            while(cur_sum >= k){
                if(cur_sum == k){
                    int cur_len = end - start + 1;
                    if(cur_len < max_len){
                        max_len = cur_len;
                        answer[0] = start;
                        answer[1] = end;
                    }
                }
                
                // 시작점 이동
                cur_sum -= sequence[start++];
            }
        }
        
        return answer;
    }
}