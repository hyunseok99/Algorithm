#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;

int n, m;
// 동 서 남 북
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1,-1, 0, 0 };

// melt: 1년후 녹을 양 = 인접한 물의 칸 수 
struct ice {
	int val;
	int melt = 0;
};

void checkFourDimension(int y, int x, vector<vector<ice>>& arr, vector<vector<bool>>& flag) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < n && nx >= 0 && nx < m && arr[ny][nx].val != 0 && flag[ny][nx] == false) {
			flag[ny][nx] = true;
			checkFourDimension(ny, nx, arr, flag);
		}
	}
}

// 빙산의 갯수 리턴하는 함수
int getIceCnt(vector<vector<ice>>& arr) {
	int cnt = 0;
	vector<vector<bool>> flag(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j].val != 0 && flag[i][j] == false) {
				flag[i][j] = true;
				checkFourDimension(i, j, arr, flag);
				cnt++;
			}
		}
	}

	return cnt;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	vector<vector<ice>> arr(n, vector<ice>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j].val;
		}
	}

	// 녹는양 초기화화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int melt = 0;
			if (arr[i][j].val != 0) {
				for (int dir = 0; dir < 4; dir++) {
					int ny = i + dy[dir];
					int nx = j + dx[dir];
					if (ny >= 0 && ny < n && nx >= 0 && nx < m && arr[ny][nx].val == 0) {
						melt++;
					}
				}
				arr[i][j].melt = melt;
			}
		}
	}

	int time = 0;
	while (1) {
		time++;
		stack<pair<int, int>> meltedIce;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j].val != 0) {
					int nVal = arr[i][j].val - arr[i][j].melt;
					if (nVal <= 0) {
						arr[i][j].val = 0;
						meltedIce.push({ i,j });
					}
					else {
						arr[i][j].val = nVal;
					}
				}
			}
		}

		// 빙산 갯수 체크 
		int island = getIceCnt(arr);
		if (island >= 2) {
			break;
		}
		else if (island == 0) {
			time = 0;
			break;
		}

		// melt 갱신
		while (!meltedIce.empty()) {
			pair<int, int> cur = meltedIce.top();
			meltedIce.pop();
			for (int i = 0; i < 4; i++) {
				int ny = cur.first + dy[i];
				int nx = cur.second + dx[i];
				if (ny >= 1 && ny < n && nx >= 1 && nx < m && arr[ny][nx].val != 0) {
					arr[ny][nx].melt += 1;
				}
			}
		}

	}

	cout << time;
	return 0;
}
