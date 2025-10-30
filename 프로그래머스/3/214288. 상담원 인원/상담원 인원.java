import java.util.*;

// 유형별로 독립적
// 
class Solution {
    int answer = -1;
    public int solution(int k, int n, int[][] reqs) {
        int[] seq = new int[k+1]; // 1~k
        getMento(k, n, 1, seq, reqs);
        return answer;
    }
    
    public void getMento(int k, int n, int k_lev, int[] seq, int[][] reqs){
        if(k_lev >= k+1){
            int tot = 0;            
            for(int v: seq){
                tot += v;
            }
            if(tot != n){
                return;
            }else{
                // do getTotalTime
                getTotalTime(k, seq, reqs);
                return;
            }
        }
        // 가능한 상담 유형의 최대 멘토 수 
        int max_v = n-(k-1);

        // n명으로 k개 가짓수 분할 
        for(int i=1; i<= max_v; i++){
            seq[k_lev] = i;

            getMento(k, n, k_lev+1, seq, reqs);
        }
    }
    
    // 분할한 멘토들 이용해서 기다린 시간 결과 갱신; 
    public void getTotalTime(int k, int[] mentors, int[][] reqs){
        // tpye, end_time
        PriorityQueue<Integer>[] tot = new PriorityQueue[k+1];
        for(int i=0; i<tot.length; i++){
            tot[i] = new PriorityQueue<>((a,b) -> a - b);
        }
        
        int waited_time = 0;
        int cur_time = 0;
        // 대기시간 처리
        for(int[] human: reqs){
            int start = human[0];
            int dur = human[1];
            int type = human[2];
            while(cur_time < start){
                cur_time += 1;
            }
            // 만약 종료된 상담이라면 큐에서 제거
            while(!tot[type].isEmpty() && tot[type].peek() <= cur_time){
                tot[type].poll();
            }

            if(tot[type].size() < mentors[type]){
                // 대기 시간 없음 
                tot[type].add(cur_time + dur);
            }else{
                // 대기 시간 생김
                int last_end = tot[type].poll();
                waited_time += last_end - start;
                tot[type].add(last_end + dur);
            }
        }
        System.out.println("waited_time: " + waited_time);
        if(answer == -1){
            answer = waited_time;
        }else{
            answer = Math.min(answer, waited_time);
        }
    }
}