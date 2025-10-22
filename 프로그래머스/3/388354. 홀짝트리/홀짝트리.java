import java.util.*;


// 홀: 번호 odd, 자식갯수 odd    역홀: 번호 odd, 자식갯수 even
// 짝: 번호 even, 자식갯수 even  역짝: 번호 even, 자식갯수 odd

// 홀짝 트리: 홀수 노드와 짝수 노드로만 이루어진 트리
// 역홀짝 트리: 역홀수 노드와 역짝수 노드로만 이루어진 트리
// 루트 노드 설정 -> 홀짝 트리 , 역홀짝 트리 가능 갯수

// 특정 노드 루트 노드 설정시 ->  0,1,2,3  가능한 케이스 : 홀, 짝, 역홀, 역짝 

class Solution {
    public int first_req_cnt = 0;
    public int second_req_cnt = 0;
    
    public int[] solution(int[] nodes, int[][] edges) {
        // O(nodes * edges)는 에바
        // 간선들 추가해 놓고 -> nodes 순회하면서 홀짝 트리, 역홀짝 트리 가능 여부 판단 
        // -> O(nodes + edges)
        

        ArrayList<Integer>[] connected = new ArrayList[1000001];
        int[] degree = new int[1000001]; // 미리 노드에 연결된 간선 수 계산
        for(int i=1; i<= 1000000; i++){
            connected[i] = new ArrayList<Integer>();
        }
        
        for(int[] edge: edges){
            int a,b;
            a = edge[0];
            b = edge[1];
            connected[a].add(b);
            connected[b].add(a);
            degree[a] += 1;
            degree[b] += 1;
        }
        
        getReq(nodes, connected, degree);
        int[] answer = {first_req_cnt, second_req_cnt};
        return answer;
    }
    
    // 요구사항 계산 함수 
    public void getReq(int[] nodes, ArrayList<Integer>[] connected, int[] degree){
        
        // 포리스트 생성 여부 판단 
        boolean[] parent = new boolean[connected.length];
        
        // 각각의 노드를 루트로 설정해서 포리스트 구성 후 연산 -> 각 노드에 연결된 
        for(int node: nodes){
            // 방문 안한 노드면 방문 체크-> 이미 방문 체크 되어있다면 해당 노드는 포리스트에 포함되어 있음
            if(parent[node]) continue;
            parent[node] = true;
            // 포레스트 구성 노드 
            ArrayList<Integer> tree_node = new ArrayList<>();
            makeTree(node, parent, connected, tree_node);
            // 홀트 갯수, 역홀짝 갯수 연산
            judgeReq(tree_node, degree);
        }
    }
    
    // 포리스트 구성
    public void makeTree(int node, boolean[] parent, ArrayList<Integer>[] connected, ArrayList<Integer> tree_node){
        tree_node.add(node);
        for(Integer child_node: connected[node]){
            // 이미 포레스트에 포함된 경우는 스킵
            if(parent[child_node]) continue;
            parent[child_node] = true;
            makeTree(child_node, parent, connected, tree_node);
        }
    }
    
    // 홀짝 트리 여부, 역홀짝 트리 여부 확인해서 연산 
    public void judgeReq(ArrayList<Integer> tree_node, int[] degree){
        
        // 현재 노드가 루트 노드라면 -> cnt = degree , 아니라면 degree -1 
        // 위의 조건으로 이중 for문 -> 시간 초과  O(n) 으로 수정
        // 효율을 위해서 모두 degree-1로 계산하고 -> 단 하나의 케이스만 다르다면 그 노드를 루트로 설정시 가능
        ArrayList<Integer> firstMiss = new ArrayList<>();
        ArrayList<Integer> secondMiss = new ArrayList<>();        
        int first_req_root = 0;
        int second_req_root = 0;
        
        // 루트 노드가 아니라면 -1         
        for(Integer node: tree_node){
            int child_cnt = degree[node]-1;

            // 홀수 혹은 짝수 트리가 아닌 경우
            if(node % 2 != child_cnt % 2){
                firstMiss.add(node);
            }

            // 역홀 트리가 아닌 경우
            if(node % 2 == child_cnt % 2){
                secondMiss.add(node);
            }
            
            // 각 노드가 루트 노드일 경우 조건 만족 카운트
            if(node % 2 == degree[node] % 2){
                first_req_root += 1;
            }
            if(node % 2 != degree[node] % 2){
                second_req_root += 1;
            }
        }
        
        // miss에 따른 정답 갱신
        if(firstMiss.size() == 0){
            // 루트 노드가 짝홀 트리면 가능
            for(Integer node: tree_node){
                if(node % 2 == degree[node] % 2){
                    first_req_cnt += 1;
                }
            }
        }else if(firstMiss.size() == 1){
            // 예외가 1개이면 그 경우만 가능
            int node = firstMiss.get(0);
            if(node % 2 == degree[node] % 2){
                    first_req_cnt += 1;
            }
        }
        
        if(secondMiss.size() == 0){
            for(Integer node: tree_node){
                if(node % 2 != degree[node] % 2){
                    second_req_cnt += 1;
                }
            }
        }else if(secondMiss.size() == 1){
            int node = secondMiss.get(0);
            if(node % 2 != degree[node] % 2){
                second_req_cnt += 1;
            }
        }
        
        // miss가 2개 이상이면 홀짝트리, 역홀짝트리 불가능
        
        return;
    }
}