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
#include <map>
#include <set>
using namespace std;

int n,m,cnt;
char arr[21][21];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool check[26];


void dfs(int x, int y, int lev) {
	cnt = max(cnt, lev);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (!check[arr[nx][ny] - 'A']) {
			check[arr[nx][ny] - 'A'] = true;
			dfs(nx, ny, lev + 1);
			check[arr[nx][ny] - 'A'] = false;
		}
	}
}


int main() {
	cin.tie(0); cin.sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	check[arr[0][0]-'A'] = true;
	dfs(0, 0, 1);
	cout << cnt;
	return 0;
}
