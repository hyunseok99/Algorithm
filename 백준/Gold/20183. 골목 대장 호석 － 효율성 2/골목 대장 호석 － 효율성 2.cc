#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;
typedef long long ll;
ll INF = LLONG_MAX;
int n, m;
int start, dest;
long long c;
long long res = -1;



// 최대 코스트를 제한했을 떄 가능 여부 
bool getTotalCost(vector<vector<pair<int, ll>>>& edges, ll maxCost) {
	// maxCost 이하의 이동 경로를 통해서 이동 가능한지 여부 중 최소 
	vector<ll> dist(n + 1, c + 1);

	// 누적 비용, 시작점  -> 비용 더 큰거 나오게 
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
	pq.push({0,start});
	dist[start] = 0;

	while (!pq.empty()) {
		ll curCost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		// 누적 코스트가 기존 dist값보다 크면 스킵: 최단 거리 = maximum값 최대 
		if (curCost > dist[cur]) {
			continue;
		}
		
		// c이내에 목적지 도달 가능하면 break
		if (cur == dest) {
			return true;
		}


		// 가능 경로 
		for (auto& edge : edges[cur]) {
			int next = edge.first;
			ll cost = edge.second;

			// 현재	간선 비용이 최대 비용 넘어가면 스킵
			if (cost > maxCost) continue;

			ll newCost = curCost + cost;

			if (newCost <= c && newCost < dist[next]) {
				// 길이 갱신
				dist[next] = newCost;
				pq.push({ newCost, next });
			}
		}
	}

	// 목적지 체크
	if (dist[dest] <= c) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> start >> dest >> c;
	vector<int> vertex(n + 1);
	// edge[a] = {b, cost}
	vector<vector<pair<int, ll>>> edges(n + 1);

	ll right = 0; // 0~c 이분탐색의 high로 이용
	ll left = 0;

	for (int i = 0; i < m; i++) {
		int s, e;
		ll cost;
		cin >> s >> e >> cost;
		edges[s].push_back({ e,cost });
		edges[e].push_back({ s,cost });
		right = max(right, cost);
	}

	while (left <= right) {
		ll mid = (left + right) / 2;
		if (getTotalCost(edges, mid)) {
			res = mid;
			// 가능한 더 작은 maxCost 가능할지 탐색
			right = mid -1;

		}
		else {
			left = mid + 1;
		}
	}


	cout << res;
	return 0;
}