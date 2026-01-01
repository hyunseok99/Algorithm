import java.util.*;

// 최대 O(n*n) 
class Solution {
    ArrayList<Integer>[] adj;
    int len;
    public int solution(int n, int[][] wires) {
        int answer = n;
        len = n;
        // 특정 와이어를 잘랐을 때 
        adj = new ArrayList[n+1];
        for(int i=0; i<=n; i++){
            adj[i] = new ArrayList<>();
        }
        // adj init
        for(int i=0; i<wires.length; i++){
            adj[wires[i][0]].add(wires[i][1]);
            adj[wires[i][1]].add(wires[i][0]);
        }
        
        for(int i=0; i<wires.length; i++){
            // i번 wire를 자름 각각으로 탐색 후 정답 갱신 
            answer = Math.min(answer, getDiff(wires[i][0], wires[i][1]));
        }
        
        return answer;
    }
    
    // 분리된 송전선 차이 return 
    public int getDiff(int a, int b){
        int a_cnt = 0, b_cnt = 0;
        boolean[] a_visited = new boolean[len+1];
        boolean[] b_visited = new boolean[len+1];
        Queue<Integer> a_q = new LinkedList<>();
        Queue<Integer> b_q = new LinkedList<>();
        
        // init
        a_visited[a] = true;
        a_visited[b] = true;
        b_visited[a] = true;
        b_visited[b] = true;
        a_q.add(a);
        b_q.add(b);
        
        while(!a_q.isEmpty()){
            int cur = a_q.poll();
            
            for(int next: adj[cur]){
                if(!a_visited[next]){
                    a_q.add(next);
                    a_visited[next] = true;
                    a_cnt++;
                }
            }
        }
        
        while(!b_q.isEmpty()){
            int cur = b_q.poll();
            
            for(int next: adj[cur]){
                if(!b_visited[next]){
                    b_q.add(next);
                    b_visited[next] = true;
                    b_cnt++;
                }
            }
        }
        return Math.abs(a_cnt - b_cnt);
    }
    
}