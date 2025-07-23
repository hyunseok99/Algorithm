#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	vector<vector<pair<int,int>>> node(n + 1); // 시작점, (끝점, 가중치) 
	vector<int> indegree(n + 1, 0); // 위상정렬을 위한 진입차수 
	vector<int> dp(n + 1, 0); // 1번에서 i번 노드까지의 최대 점수
	vector<int> prevNode(n + 1, 0); // 경로 역추적용 이전 노드 저장

	for (int i = 1; i <= m; i++) {
		int p, q, r;
		cin >> p >> q >> r;
		node[p].push_back({ q, r });
		indegree[q]++; // q로 들어오는 간선
	}


	// 위상 정렬용 큐, 진입차수가 0인 경우 삽입
	queue<int> q;
	q.push(1);

	// dp를 수행 
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		// 갈 수 있는 노드들로 계산
		for (auto i = node[cur].begin(); i != node[cur].end(); i++) {
			int next = (*i).first;
			int weight = (*i).second;
			// dp갱신 여부
			if (dp[next] < dp[cur] + weight) {
				dp[next] = dp[cur] + weight;
				prevNode[next] = cur;
			}

			// 진입 차수를 1 감소시키고 1번 노드 도착하면 끝
			indegree[next]--;
			if (indegree[next] == 0) {
				if (next != 1) {
					q.push(next);
				}
			}
		}

	}

	cout << dp[1] << "\n";

	// 경로
	stack<int>path;
	path.push(1);
	int cur = prevNode[1];
	while (cur != 1) {
		path.push(cur);
		cur = prevNode[cur];
	}
	// 다시 도착한 1번 삽입
	path.push(1);

	while (!path.empty()) {
		cout << path.top() << " ";
		path.pop();
	}
	return 0;
}