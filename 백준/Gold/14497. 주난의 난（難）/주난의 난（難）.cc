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

int n, m, cnt, res, maxN = -1, maxA = -1;
char arr[301][301];
bool flag[301][301];
int dx[4] = {0,-1,0,1 }; //서 북 동 남
int dy[4] = {-1,0,1,0 };



bool fun(int x,int y) {
	queue<pair<int,int>> q;
	flag[x][y] = true;
	q.push({x,y});
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = temp.first + dx[i];
			int ny = temp.second + dy[i];
			if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && flag[nx][ny] == false) {
				if (arr[nx][ny] == '0') {
					q.push({ nx,ny });
					flag[nx][ny] = true;
				}
				else if (arr[nx][ny] == '1') {
					arr[nx][ny] = '0';
					flag[nx][ny] = true;
				}
				else if (arr[nx][ny] == '#') {
					return false;
				}
			}
		}
	}
	cnt++;
	return true;
}

int main() {
	int x1, y1, x2, y2;
	cin >> n >> m>> x1>> y1>> x2>> y2;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	while (1) {
		fill(&flag[0][0], &flag[300][301], false);
		bool check = fun(x1, y1);
		if (!check) {
			cout << ++cnt;
			break;
		}
	}

	return 0;
}