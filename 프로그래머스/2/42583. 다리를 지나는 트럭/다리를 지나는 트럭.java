import java.util.*;
class Truck {
    public int start, end, weight;
    public Truck(int start, int end, int weight){
        this.start = start;
        this.end = end;
        this.weight = weight;
    }
}

class Solution {
    // 먼저 출발한 차가 무조건 먼저 다리 지나감 
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = getTime(bridge_length, weight, truck_weights);
        return answer;
    }
    
    public int getTime(int bridge_length, int weight, int[] truck_weights){
        int tot_weight = 0;
        int tot_time = 0;
        int cnt = 0;
        int idx = 0;
        ArrayList<Integer> arrived = new ArrayList<>();
        Queue<Truck> q = new LinkedList<>();
        while(idx < truck_weights.length){
            tot_time++;
            if(!q.isEmpty() && q.peek().end <= tot_time){
                Truck tmp = q.poll();
                tot_weight -= tmp.weight;
            }
            
            if(tot_weight + truck_weights[idx] <= weight){
                q.add(new Truck(tot_time, tot_time+bridge_length, truck_weights[idx]));
                tot_weight += truck_weights[idx];
                idx += 1;
            }
        }
        
        while(!q.isEmpty()){
            Truck tmp = q.poll();
            tot_time = tmp.end;
        }
        
        return tot_time;
    }
}