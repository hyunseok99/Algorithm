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


int n, m,cnt1,cnt2, res = -1;
bool flag[51][51];
char arr[51][51];
int dx[4] = {1,0,-1,0};
int dy[4] = { 0,1,0,-1 };
int dis[51][51];

map<int,int> myM;
/*
void comb(int index, int start) {
	if (index == m) {
		distance();
	}

	for (int i = start; i < v.size(); i++) {
		if (!flag[v[i].first][v[i].second]) {
			flag[v[i].first][v[i].second] = true;
			comb(index+1, i + 1);
			flag[v[i].first][v[i].second] = false;

		}
	}
}
*/

void fun(int x, int y) {

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	flag[x][y] = true;

	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = temp.first + dx[i];
			int ny = temp.second + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (arr[nx][ny] == 'L' && flag[nx][ny]==false) {
					q.push(make_pair(nx, ny));
					flag[nx][ny] = true;
					dis[nx][ny] = dis[temp.first][temp.second] + 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'L' && res < dis[i][j]) {
				res = dis[i][j];
			}
		}
	}

	return;
}

int main() {

	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'L') {
				fun(i, j);
				fill(&flag[0][0], &flag[50][51], false);
				fill(&dis[0][0], &dis[50][51], 0);

			}
		}
	}
	cout << res;
	return 0;
}