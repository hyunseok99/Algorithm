import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        ArrayList<Integer> ans_list = new ArrayList<>();
        int date = 0;
        int cnt = 0;
        Deque<int[]> q = new ArrayDeque<>();
        for(int i=0; i<progresses.length; i++){
            q.add(new int[]{progresses[i], speeds[i]});
        }
        while(!q.isEmpty()){
            int[] cur = q.poll();
            int quotient = ((100 - cur[0]) / cur[1]);
            int remain = ((100 - cur[0]) % cur[1]);
            if(remain != 0){
                quotient++;
            }
            if(date == 0){
                date = quotient;
                cnt++;
            }else if(date >= quotient){
                cnt++;
            }else{
                date = quotient;
                ans_list.add(cnt);
                cnt = 1;
            }
        }
        // 마지막꺼 추가 
        ans_list.add(cnt);
        
        int[] answer = new int[ans_list.size()];
        for(int i = 0; i<ans_list.size(); i++){
            answer[i] = ans_list.get(i);
        }
        return answer;
    }
}