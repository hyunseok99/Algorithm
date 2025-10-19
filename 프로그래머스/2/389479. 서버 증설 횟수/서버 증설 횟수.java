import java.util.*;

class State {
    int start, end, cnt;
    public State(int start, int end, int cnt){
        this.start = start;
        this.end = end;
        this.cnt = cnt;
    }
        
}

class Solution {
    public int cur_max, duration, time, inc_val;
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        time = 0;
        inc_val = m;
        cur_max = m;
        duration = k;
        Queue<State> q = new LinkedList<>();
        for(int player: players){
            // 시간에 따른 peek 확인해서 제거 
            if(!q.isEmpty()){
                if(q.peek().end == time){
                    State tmp = q.poll();
                    cur_max -= (tmp.cnt * inc_val);
                }
            }
            answer += getState(player, q);
            time += 1;
        }
        
        return answer;
    }
    
    // 증설 일어난 횟수 return 
    public int getState(int player, Queue<State> q){
        if(player < cur_max){
            return 0;
        }
        int inc_cnt = (player-cur_max) / inc_val + 1; 
        cur_max += inc_cnt * inc_val;
        q.add(new State(time, time+duration, inc_cnt));
        
        return inc_cnt;
    }
    
}