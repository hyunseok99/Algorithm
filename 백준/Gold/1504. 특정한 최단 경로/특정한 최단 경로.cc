#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, e;


vector<int> myDijkstra(int start, vector<vector<pair<int, int>>>& node) {
	vector<int> dist(n + 1, 100000001);
	// 시작 노드 dist
	dist[start] = 0;
	// weight, spot
	priority_queue<pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int curDist = pq.top().first;
		int curSpot = pq.top().second;
		pq.pop();
		// 이미 더 짧은 경로 존재 하면 continue
		if (curDist > dist[curSpot]) continue;

		for (auto i = node[curSpot].begin(); i != node[curSpot].end(); i++) {
			pair<int, int> next= *i;
			int nextDist = next.second;
			int nextSpot = next.first;

			if (dist[nextSpot] > curDist + nextDist) {
				dist[nextSpot] = curDist + nextDist;
				pq.push({ dist[nextSpot], nextSpot});
			}

		}
	}

	return dist;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> e;
	// start - end - weight
	vector<vector<pair<int, int>>> node(n + 1);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b,c });
		node[b].push_back({ a,c });

	}
	// 반드시 지나야 하는 2개의 정점
	int spotA, spotB;
	cin >> spotA >> spotB;

	vector<int> dist = myDijkstra(1, node);
	vector<int> distAB = myDijkstra(spotA, node);
	vector<int> distBA = myDijkstra(spotB, node);

	int noEdge = 100000001;
	bool flagAB = true;
	bool flagBA = true;
	if (dist[spotA] == noEdge || distAB[spotB] == noEdge || distBA[n] == noEdge) {
		flagAB = false;
	}
	if (dist[spotB] == noEdge || distBA[spotA] == noEdge || distAB[n] == noEdge) {
		flagBA = false;
	}
	long long pathAB = dist[spotA] + distAB[spotB] + distBA[n];
	long long pathBA = dist[spotB] + distBA[spotA] + distAB[n];

	if (flagAB && flagBA) {
		cout << min(pathAB, pathBA);
	}
	else {
		if (flagAB) {
			cout << pathAB;
		}
		else if (flagBA) {
			cout << pathBA;
		}
		else {
			cout << -1;
		}
	}
	return 0;
}
