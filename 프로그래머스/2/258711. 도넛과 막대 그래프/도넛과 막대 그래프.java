import java.util.*;

// return 생성 정점 번호, 도넛 갯수, 막대 갯수, 8자 갯수 
// 도넛, 막대, 8자의
// -> 사이클 생성 or 단방향 
// 모든 점에 대해서 -> 사이클 형성하는 경우의 점과 엣지를 이용해서 판단
// 들어오는 edge가 없으면 추가한 노드임  
// 도넛 or 8자 -> 사이클이 형성된다  + 가운데 지점을 스타트로 하면 사이클 판단 어려우니 제외하고 수행
// 막대 -> 나가는 edge 0개에 들어오는 edge 1개 존재 
// 8자 -> 나가는 edge 2개 이상 존재 
class Solution {
    int max_node = 0;
    int add_node = -1;
    int[] answer = new int[4];
    public int[] solution(int[][] edges) {
        ArrayList<Integer>[] edge_in = new ArrayList[1000001];
        ArrayList<Integer>[] edge_out = new ArrayList[1000001];
        for(int i=0; i<edge_in.length; i++){
            edge_in[i] = new ArrayList<Integer>();
            edge_out[i] = new ArrayList<Integer>();
        }
        for(int[] edge: edges){
            int a = edge[0];
            int b = edge[1];
            int c = Math.max(a, b);
            edge_out[a].add(b);
            edge_in[b].add(a);
            max_node = Math.max(max_node, c);
        }
        
        // 추가된 노드 판독 
        for(int i=1; i<=max_node; i++){
            if(edge_out[i].size() >= 2 && edge_in[i].size() == 0){
                // 추가한 노드
                answer[0] = i;
                add_node = i;
                break;
            }
        }
        
        // 추가한 노드와 연결된 노드들이 각각의 포리스트 
        boolean[] connected_node = new boolean[max_node + 1];
        
        int forest_size = edge_out[add_node].size();
        for(Integer start_node: edge_out[add_node]){
            // 해당 노드로 판독 그래프 판독
            Queue<Integer> q = new LinkedList<Integer>();
            q.add(start_node);
            connected_node[start_node] = true;
            
            while(!q.isEmpty()){
                int cur = q.poll();
                
                if(edge_out[cur].size() == 0){
                    answer[2]+=1;
                    break;
                }
                
                if(edge_out[cur].size() >= 2){
                    answer[3] += 1;
                    break;
                }
                
                for(Integer next_node: edge_out[cur]){
                    if(connected_node[next_node] == false){
                        connected_node[next_node] = true;
                        q.add(next_node);
                    }
                }
            }
        }
        answer[1] = forest_size - answer[2] -answer[3];
        return answer;
    }
    
   
}