#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, e;

void calcDist(vector<vector<pair<int, int>>>& node, queue<int> q, vector<int>& dist) {
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		// flag 체크
		for (auto i = node[cur].begin(); i != node[cur].end(); i++) {
			pair<int, int> next = *i;
			if (dist[next.first] > dist[cur] + next.second) {
				dist[next.first] = dist[cur] + next.second;
					q.push(next.first);
			}
		}
	}

	return;
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
	vector<int> dist(n + 1, 100000001);
	// 1-> spotA dist , distA -> distB, distB -> n;
	// spot
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	// 1 -> A, 1-> B dist 계산 
	calcDist(node, q, dist);
	
	// A -> B, A -> n dist
	vector<int> distAB(n + 1, 100000001);
	q.push(spotA);
	distAB[spotA] = 0;
	calcDist(node, q, distAB);

	// B -> A, B -> n dist
	vector<int> distBA(n + 1, 100000001);
	q.push(spotB);
	distBA[spotB] = 0;
	calcDist(node, q, distBA);

	// 1 -> A -> B -> n 경로
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
