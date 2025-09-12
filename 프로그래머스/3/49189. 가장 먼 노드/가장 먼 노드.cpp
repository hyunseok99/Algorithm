#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;

// O(nlogE)

int dijkstra(int n, vector<vector<int>> &adj){
    // 1번 노드로부터 최단 경로
    vector<int> dist(n+1, 20001);
    // distance, node
    priority_queue<pair<int,int>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty()){
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        
        // 최단 거리 아니면 스킵
        if(cur_dist > dist[cur_node]) continue;
        
        for(int i=0; i<adj[cur_node].size(); i++){
            int next_node = adj[cur_node][i];
            if(dist[next_node] > cur_dist + 1){
                dist[next_node] = cur_dist+1;
                pq.push({cur_dist+1, next_node});
            }
        }        
    }
    
    // 최대 길이 체크 
    int max_size = 0;
    for(int i=1; i<=n; i++){
        max_size = max(max_size, dist[i]);
    }
    
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(dist[i] == max_size){
            ans++;
        }
    }
    return ans;
}


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    // 인접 여부 판단
    vector<vector<int>> adj(n+1);
    for(int i=0; i<edge.size(); i++){
        int e = edge[i][0];
        int v = edge[i][1];
        adj[e].push_back(v);
        adj[v].push_back(e);
    }
    answer = dijkstra(n, adj);
    return answer;
}