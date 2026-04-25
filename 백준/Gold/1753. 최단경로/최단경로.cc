#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int v, e, start;


vector<int> dijkstra(vector<vector<pair<int,int>>> &edge){
	vector<int> dist(v+1, 100000000);
	// 가중치, 점
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,start});
	dist[start] = 0;
	
	while(!pq.empty()){
		pair<int,int> tmp = pq.top();
		pq.pop();
		// 이미 경로가 더 짧은 경우 존재
		if(dist[tmp.second] < tmp.first){
			continue;
		}
		
		for(int i = 0; i < edge[tmp.second].size(); i++ ){
			int nextIdx = edge[tmp.second][i].first;
			int newDist = tmp.first + edge[tmp.second][i].second;
			if(newDist < dist[nextIdx]){
				dist[nextIdx] = newDist;
				pq.push({newDist, nextIdx});
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> v >> e >> start;

	// 여기서 메모리 초과.. -> 인접리스트 형태로 변환
	vector<vector<pair<int,int>>> edge(v+1);
	
	for (int i = 0; i < e; i++) {
		int x,y,w;
		cin >> x >> y >> w;
		edge[x].push_back({y,w});
	}

	vector<int> dist = dijkstra(edge);
	
	for(int i=1; i<=v; i++){
		if(dist[i] == 100000000){
			cout << "INF\n";
		}else{
			cout << dist[i] << "\n";
		}
	}
	
	return 0;
}