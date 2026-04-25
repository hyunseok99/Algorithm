#include <iostream>
#include <vector>
using namespace std;

int n, m;

void func(int a, int b, vector<vector<int>>& node, vector<bool>& flag, vector<int>& res, vector<vector<int>> &dis) {
	if (a == b) {
		int ans = 0;
		for (int i = 0; i < res.size() - 1; i++) {
			ans += dis[res[i]][res[i + 1]];
		}
		cout << ans << "\n";
		return;
	}

	for (int i = 0; i < node[a].size(); i++) {
		if (dis[a][node[a][i]] != 0 && flag[node[a][i]] == false) {
			flag[node[a][i]] = true;
			res.push_back(node[a][i]);
			func(node[a][i], b, node, flag, res, dis);
			res.pop_back();
		}
	}
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> m;
	vector<vector<int>> node(n + 1);
	vector<vector<int>> dis(n + 1, vector<int>(n + 1));
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back(b);
		node[b].push_back(a);
		dis[a][b] = c;
		dis[b][a] = c;
	}


	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vector<bool> flag(n + 1);
		vector<int> res;
		flag[a] = true;
		res.push_back(a);
		func(a, b, node, flag, res, dis);
	}

	return 0;
}