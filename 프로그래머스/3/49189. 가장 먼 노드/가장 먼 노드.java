import java.util.*;


// 1번 노드로부터 가장 멀리 떨어진 
// 1번과 이어진 -> 이후 노드로부터 이어진 -> 처음 값이 갱신되면 최단거리 

class Node implements Comparable<Node>{
    int dist = 0;
    int node;
    public Node(int dist, int node){
        this.dist = dist;
        this.node = node;
    }
    
    @Override
    public int compareTo(Node b){
        return Integer.compare(this.dist, b.dist);
    }
}

class Solution {
    int max_val = 30000;
    public int solution(int n, int[][] edge) {
        
        ArrayList<Integer>[] adj = new ArrayList[n+1];
        for(int i=0; i<adj.length; i++){
            adj[i] = new ArrayList<Integer>();
        }
        
        for(int i=0; i<edge.length; i++){
            int n1 = edge[i][0];
            int n2 = edge[i][1];
            adj[n1].add(n2);
            adj[n2].add(n1);
        }
        
        
        int[] weights = new int[n+1];
        for(int i=1; i<=n; i++){
            weights[i] = max_val;
        }
        weights[1] = 0;
        // dist, node
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(0,1));
        
        while(!pq.isEmpty()){
            Node cur = pq.poll();
            int cur_dist = cur.dist;
            int cur_node = cur.node;
            if(cur_dist > weights[cur_node]) continue;
            
            for(int next_node: adj[cur_node]){
                if(weights[next_node] > cur_dist + 1){
                    weights[next_node] = cur_dist + 1;
                    pq.add(new Node(cur_dist+1, next_node));
                }
            }
        }
        
        int most_val = -1;
        int answer = 0;
        for(int i=1; i<=n; i++){
            if(most_val < weights[i]){
                most_val = weights[i];
                answer = 0;
            }
            if(most_val == weights[i]){
                answer++;
            }
        }
        return answer;
    }
}