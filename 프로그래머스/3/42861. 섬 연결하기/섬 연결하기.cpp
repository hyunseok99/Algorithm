#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int answer;

// {0,2} {1,3} -> {0,2,1,3} 이런 과정을 통해서 최소 값

int getParent(int x, vector<int> &island){
    if(island[x] != x){
        return getParent(island[x], island);
    }else{
        return x;        
    }
}

void getUnion(int a, int b, vector<int>& island, vector<int> &connectedSize){
    // 2개의 원소를 union
    int parent_a = getParent(a, island);
    int parent_b = getParent(b, island);
    if(parent_a != parent_b){
        if(connectedSize[parent_a] < connectedSize[parent_b]){
           swap(parent_a, parent_b);
        }
        island[parent_b] = island[parent_a];
        connectedSize[parent_a] += connectedSize[parent_b];
    }

}

void getAns(int n, vector<vector<int>> &costs){
    // 존재 섬, 집합
    vector<int> island(n);
    vector<int> connectedSize(n);
    for(int i=0; i<n; i++){
        island[i] = i;
        connectedSize[i] = 1;
    }
    
    // 다리 인접 정보 cost기준 오름차순 정렬
    sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b){
      return a[2] < b[2];  
    });
    
    // 연결된 섬의 수
    int connection = 0;
    // 하나의 트리로 만들어질 때까지 최소 edge 전택하면서 union
    for(auto& edge: costs){
        int u,v,cost;
        u = edge[0];
        v = edge[1];
        cost = edge[2];
        
        // 연결 x 라면 선택: 최소임
        if(getParent(u,island) != getParent(v, island)){
            getUnion(u,v,island, connectedSize);
            answer += cost;
            connection++;
        }
        if(connection == n-1){
            break;
        }
    }
}

int solution(int n, vector<vector<int>> costs) {
    getAns(n, costs);
    return answer;
}