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

int n,m,k,cnt=0;
char arr[6][6];
bool flag[6][6];
int res[36];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void fun(int x, int y,int lev) {
	pair<int, int> temp = { x,y };
	if (x == 0 && y == m - 1) {
		res[lev]++;
		return;
	}
	flag[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int new_x = temp.first + dx[i];
		int new_y = temp.second + dy[i];
		if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m || arr[new_x][new_y]=='T' || flag[new_x][new_y] == true) continue;
		fun(new_x, new_y, lev+1);
	}
	flag[x][y] = false;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	fun(n - 1, 0, 1);
	cout << res[k];


	return 0;
}