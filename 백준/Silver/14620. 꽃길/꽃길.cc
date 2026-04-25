#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <string>
#include <unordered_set>
#include <numeric>
#include <climits>
#include <stack>
using namespace std;

int n,m;
int arr[10][10];
int dx[5] = { 0,1,0,-1,0 };
int dy[5] = { 0,0,1,0,-1 };
bool flag[10][10];




pair<int, int> convert2xy(int index) {
	int y = index / n;
	int x = index % n;
	pair<int, int> p{y,x};
	return p;
}
void dfs(vector<int> idxs) {
	vector<bool> ok(n*n, false);
	ok[0] = true;
	ok[1] = true;
	ok[2] = true;
	int mn = INT_MAX;
	do {
		vector<int> cur_idx;
		for (int i = 0; i < ok.size(); i++) {
			if (ok[i]) {
				cur_idx.push_back(i);
			}
		}
		pair<int, int> yx1 = convert2xy(cur_idx[0]);
		pair<int, int> yx2 = convert2xy(cur_idx[1]);
		pair<int, int> yx3 = convert2xy(cur_idx[2]);
		vector<pair<int, int>> vs = { yx1,yx2,yx3 };
		vector<vector<bool>> visited(n, vector<bool>(n));
		int acc = 0;
		bool flag = true;
		for (int k = 0; k < 3; k++) {
			int y = vs[k].first;
			int x = vs[k].second;
			for (int i = 0; i < 5; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[ny][nx]) {
					flag = false;
					break;
				}
				visited[ny][nx] = true;
				acc += idxs[ny*n+nx];
			}
		}
		if (flag) {
			mn = min(mn, acc);
		}
	} while (prev_permutation(ok.begin(), ok.end()));
	cout << mn;
}


int main() {
	cin >> n;
	vector<int> all_idx;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp; cin >> tmp;
			all_idx.push_back(tmp);
		}
	}
	dfs(all_idx);
}