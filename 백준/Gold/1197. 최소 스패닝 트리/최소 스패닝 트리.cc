#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

struct Edge {
	int u, v;
	int weight;

	bool operator<(Edge& b) {
		return weight < b.weight;
	}
};

int find(vector<int>& parents, int a) {
	if (parents[a] == a) {
		return a;
	}
	return find(parents, parents[a]);
}

bool myUnion(vector<int>& parents, vector<int>& parentsSize, Edge& e, int& weight) {
	int a = find(parents, e.u);
	int b = find(parents, e.v);

	// size가 적은게 큰 쪽으로 union
	if (parentsSize[a] < parentsSize[b]) {
		swap(a, b);
	}
	if (a != b) {

		// union
		parents[b] = a;
		weight += e.weight;
		parentsSize[a] += parentsSize[b];
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	vector<Edge> edges;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ a,b,c });
	}

	sort(edges.begin(), edges.end());

	vector<int> parents(n + 1);
	vector<int> parentsSize(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		parents[i] = i;
	}

	int cnt = 0;
	int weight = 0;
	for (auto& edge : edges) {
		if (myUnion(parents, parentsSize, edge, weight)) {
			cnt++;
		}
		if (cnt >= n - 1) break;
	}
	cout << weight;
	return 0;
}