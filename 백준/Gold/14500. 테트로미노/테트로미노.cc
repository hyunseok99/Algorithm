#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

	int n, m;
	int res = -1;

	// 상하좌우
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	int check(vector<int> dir, int x, int y, vector<vector<int>>& arr) {
		int sum = arr[x][y];
		for (int i = 0; i < 3; i++) {
			int nx = x + dx[dir[i]];
			int ny = y + dy[dir[i]];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				sum += arr[nx][ny];
			}
			else {
				return -1;
			}
		}
		return sum;
	}

	void move(int lev, int x, int y, vector<vector<int>>& arr, vector<vector<bool>>& flag, int sum) {
		if (lev == 4) {
			res = max(res, sum);
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (flag[nx][ny] == true) {
					continue;
				}
				flag[nx][ny] = true;
				move(lev + 1, nx, ny, arr, flag, sum + arr[nx][ny]);
				flag[nx][ny] = false;
			}
		}
		return;
	}
	
	int main() {
		cin >> n >> m;
		vector<vector<int>> arr(n, vector<int>(m));
		vector<vector<bool>> flag(n, vector<bool>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int sum0 = check({ 0,1,2 }, i, j, arr);
				int sum1 = check({ 0,1,3 }, i, j, arr);
				int sum2 = check({ 0,2,3 }, i, j, arr);
				int sum3 = check({ 1,2,3 }, i, j, arr);
				res = max(res, sum0);
				res = max(res, sum1);
				res = max(res, sum2);
				res = max(res, sum3);

				flag[i][j] = true;
				move(1, i, j, arr, flag, arr[i][j]);
				flag[i][j] = false;
			}
		}

		cout << res;
		return 0;
	}