import java.util.*;

// 순위가 정해지는 경우 
// 예제에서 [4,2] 정보가 없어도 결과 동일 
// 2 -> 3, 2-> 1, 3 -> 4
// 이 정보로 -> 2번 노드가 1,3,4 와 이어짐을 확인 가능 각각의 노드로 생각
// 이후 5 -> 2 이 정보로 5번 노드가 2,3,1,4 4개의 노드 존재  순위 결정 
// 순위가 확정되기 위한 조건 -> 앞에 몇명, 뒤에 몇명  

class Solution {
    int max_val = Integer.MAX_VALUE;
    // 원본 승리, 패배 확인 노드 

    public int solution(int n, int[][] results) {
        int answer = 0;
        
        // -> 이기는 방향 , <- 지는 방향 
        // w_node[idx] : idx를 이긴 노드
        // l_node[idx]: idx에게 진 노드  
        
        // 정답 출력용 
        Set<Integer>[] w_node = new Set[n+1];
        Set<Integer>[] l_node = new Set[n+1];
        
        // 인접 노드 
        ArrayList<Integer>[] w_adj = new ArrayList[n+1];
        ArrayList<Integer>[] l_adj = new ArrayList[n+1];
        
        for(int i=0; i<w_node.length; i++){
            w_node[i] = new HashSet<Integer>();   
            l_node[i] = new HashSet<Integer>(); 
            w_adj[i] = new ArrayList<Integer>();
            l_adj[i] = new ArrayList<Integer>();
        }
        
        for(int i=0; i<results.length; i++){
            int winner = results[i][0];
            int loser = results[i][1];
            w_adj[loser].add(winner);
            l_adj[winner].add(loser);
        }
        
        for(int i=1; i<=n; i++){
            // 승리 인원 갱신
            dfs(w_node, w_adj, i, i);
            // 패배 인원 갱신
            dfs(l_node, l_adj, i, i);
        }
        
        for(int i=1; i<=n; i++){
            if(1 + w_node[i].size() + l_node[i].size() == n){
                answer++;
            }
        }
        
        return answer;
    }
    
    // 안가지고 있으면 set에 추가  
    // 2 -> 1,3,4 
    public void dfs(Set<Integer>[] node, ArrayList<Integer>[] adj, int start, int cur){
        if(start != cur){
            node[start].add(cur);
        }
        for(int next_node: adj[cur]){
            if(node[start].contains(next_node)) continue;
            dfs(node, adj, start, next_node);
        }
    }
}