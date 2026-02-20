import java.util.*;

class Solution {
    // 핵심은 가장 큰 값과 존재 갯수를 알아야 함 
    // O(n^2)
    // max-heap으로 최대값 찾고, queue로 뽑아내면 될 듯 
    public int solution(int[] priorities, int location) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> Integer.compare(b,a));
        Deque<Integer> q = new ArrayDeque<>();
        // 별개로 location을 계속 갱신해줘야 함 
        int cur_location = location;
        for(int p: priorities){
            pq.add(p);
            q.add(p);
        }
        while(!pq.isEmpty()){
            int cur_max = pq.poll();
            while(!q.isEmpty() && q.peek() != cur_max){
                q.add(q.poll());
                cur_location--;
                if(cur_location < 0){
                    cur_location = q.size()-1;
                }
            }
            // q.peek() == cur_max
            if(!q.isEmpty()){
                int t = q.poll();
                answer++;
                if(cur_location == 0){
                    return answer;
                }
                cur_location--; // 아니라면 location 하나씩 당겨짐 
            }
        }
        return answer;
    }
}