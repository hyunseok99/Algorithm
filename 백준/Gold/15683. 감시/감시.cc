#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <math.h>
using namespace std;

int n, m, res= 999999;	//위 아래 좌 우
int dx[4] = { -1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1};
int d_count[6] = { 0,2,2,4,4,1 };
// 1 -> 0 or 1 or 2 or 3     4개
// 2 -> 0,1 or 2,3  2개
// 3 -> 0,2 or 0,3 or 1,2 or 1,3		4개
// 4 -> 0,1,2 or 0,1,3 or 0,2,3 or 1,2,3		4개
// 5 -> 0,1,2,3			1개

int arr[9][9];
vector<pair<int,int>> v;

void checkdir(queue<pair<int,int>> q, int state) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		arr[x][y] = state;
	}
	return;
}

void cal() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) cnt++;
		}
	}
	if (cnt < res) res = cnt;
	return;
}

void fun(int lev) {
	if (lev == v.size()) {
		cal();
		return;
	}
	pair<int, int> ca = v[lev];
	int x = ca.first;
	int y = ca.second;
	queue<pair<int, int>> q[4];
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		while (0 <= nx && 0 <= ny && nx < n && ny < m && arr[nx][ny] != 6) {
			if (arr[nx][ny] == 0) {
				q[i].push({ nx, ny });
			}
			nx += dx[i];
			ny += dy[i];
		}
	}

	if (arr[x][y] == 1) {
		for (int i = 0; i < 4; i++) {
			checkdir(q[i],-1);
			fun(lev + 1);
			checkdir(q[i],0);
		}
	}
	else if (arr[x][y] == 2) {
		for (int i = 0; i < 3; i+=2) {
			checkdir(q[i], -1);
			checkdir(q[i + 1], -1);
			fun(lev + 1);
			checkdir(q[i], 0);
			checkdir(q[i + 1], 0);
		}
	}
	else if (arr[x][y] == 3) {
		for (int i = 0; i < 2; i++) {
			checkdir(q[i], -1);
			for (int j = 2; j < 4; j++) {
				checkdir(q[j], -1);
				fun(lev + 1);
				checkdir(q[j], 0);
			}
			checkdir(q[i], 0);
		}
	}
	else if (arr[x][y] == 4) {
		// 4 -> 0,1,2 or 0,1,3 or 0,2,3 or 1,2,3		4개
		for (int i = 0; i < 4; i++) {
			checkdir(q[i], -1);
			checkdir(q[(i + 1)%4], -1);
			checkdir(q[(i + 2)%4], -1);
			fun(lev + 1);
			checkdir(q[i], 0);
			checkdir(q[(i + 1) % 4], 0);
			checkdir(q[(i + 2) % 4], 0);
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			checkdir(q[i], -1);
		}
			fun(lev + 1);
		for (int i = 0; i < 4; i++) {
			checkdir(q[i], 0);
		}
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (1 <= arr[i][j] && arr[i][j] <= 5) {
				v.push_back({ i,j });
			}
		}
	}
	fun(0);
	cout << res;

	return 0;
}