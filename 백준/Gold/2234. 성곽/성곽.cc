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

int n, m, cnt=1, res, maxN = -1, maxA = -1;
int arr[51][51];
bool flag[51][51];
int bin[4] = { 1,2,4,8 };  // 서 북 동 남 
int dx[4] = {0,-1,0,1 }; //서 북 동 남
int dy[4] = {-1,0,1,0 };
void fun(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	flag[x][y] = true;
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			if ((arr[temp.first][temp.second] & bin[i]) == 0) {
				int next_x = temp.first + dx[i];
				int next_y = temp.second + dy[i];
				if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && flag[next_x][next_y] == false) {
					flag[next_x][next_y] = true;
					q.push({ next_x,next_y });
					cnt++;
				}
			}
		}
	}
	if (maxN < cnt) maxN = cnt;
	cnt = 1;
	return;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!flag[i][j]) {
				fun(i, j);
				res++;
			}
		}
	}
	maxA = maxN;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				if ((arr[i][j] & bin[k]) != 0 ) {
					fill(&flag[0][0], &flag[50][51], false);
					arr[i][j] -= bin[k];
					fun(i, j);
					arr[i][j] += bin[k];
				}
			}
		}
	}

	cout << res << "\n" << maxA<<"\n"<<maxN;

	return 0;
}