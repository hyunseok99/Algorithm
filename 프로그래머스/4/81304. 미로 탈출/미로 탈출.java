import java.util.*;
import java.io.*;

// 방향의 상태는 기본, 리버스 2가지 존재
// dist[y][x][0,1] 
class Solution {
    class Node{
        int v, d, reverse; // 0 정방향, 1 역방향
        public Node(int v, int d, int rev){
            this.v = v;
            this.d = d;
            this.reverse = rev;
        }
    }
    class State{
        int v, d, bit; 
        public State(int v, int d, int bit){
            this.v = v;
            this.d = d;
            this.bit = bit;
        }
    }
    public int solution(int n, int start, int end, int[][] roads, int[] traps) {
        int answer = 0;
        int size_t = 1001;
        int trap_t = traps.length; 
        int max_t = Integer.MAX_VALUE;
        int[] trap_idx = new int[n+1]; // 트랩 매핑 
        Arrays.fill(trap_idx, -1);
        // 트랩 정보 
        int idx = 0;
        for(int trap: traps){
            trap_idx[trap] = idx++;
        }
        // 기본 인접 정보 
        ArrayList<Node>[] adj = new ArrayList[size_t]; 
        for(int i=0; i < size_t; i++){
            adj[i] = new ArrayList<>();
        }
        
        for(int i=0; i<roads.length; i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int d = roads[i][2];
            
            adj[u].add(new Node(v, d, 0)); // 정방향
            adj[v].add(new Node(u, d, 1)); // 역방향
        }
        
        int[][] dist = new int[n+1][1 << trap_t];
        for(int i=0; i<=n; i++){
            Arrays.fill(dist[i], max_t);
        }
        
        PriorityQueue<State> pq = new PriorityQueue<>((State a, State b) -> {
            return a.d - b.d;
        }); // min-heap
        dist[start][0] = 0;
        pq.add(new State(start, 0, 0));
        // 트랩이 동작한 노드를 bitmasking 활용 
        while(!pq.isEmpty()){
            State cur = pq.poll();
            if(cur.d > dist[cur.v][cur.bit]) continue;
            if(cur.v == end){
                answer = cur.d;
                break;
            }
            
            // 현재 노드 트랩 발동 여부 
            boolean cur_trap = false;
            if(trap_idx[cur.v] != -1){
                cur_trap = (cur.bit & (1 << trap_idx[cur.v])) != 0;
            }
            
            // 인접 노드 트랩 발동 여부
            for(Node next: adj[cur.v]){
                boolean next_trap = false;
                if(trap_idx[next.v] != -1){
                    next_trap = (cur.bit & (1 << trap_idx[next.v])) != 0;
                }
                
                // 둘다 켜져있거나 꺼져있으면 정방향 아니면 역방향 
                int cur_state = (cur_trap ^ next_trap) ? 1: 0; 
                
                if(next.reverse == cur_state){
                    int next_bit = cur.bit;
                    if(trap_idx[next.v] != -1){
                        // 다음 이동 노드가 트랩이면 상태 변경 
                        next_bit = (next_bit ^ (1 << trap_idx[next.v]));
                    }
                    
                    if(dist[next.v][next_bit] > cur.d + next.d){
                        dist[next.v][next_bit] = cur.d + next.d;
                        pq.add(new State(next.v, dist[next.v][next_bit], next_bit));
                    }
                }
            }
        }
        return answer;
    }
    
    // 이동 function 
    public void dijkstra(){
        
    }
}