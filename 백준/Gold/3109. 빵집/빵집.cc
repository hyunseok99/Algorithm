#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int r, c, cnt;

// 오른쪽 윗대각, 오른쪽, 오른쪽 아랫대각
int dy[3] = { -1, 0, 1 };
int dx[3] = { 1, 1, 1 };

bool dfs(vector<vector<char>>& arr, vector<vector<bool>>& flag, int row, int col) {
	if (col == c) {
		// 파이프라인 형성
		cnt++;
		return true;
	}

	for (int dir = 0; dir < 3; dir++) {
		int ny = row + dy[dir];
		int nx = col + 1;
		if(ny >= 1 && ny <= r && nx >= 1 && nx <= c && arr[ny][nx] == '.' && flag[ny][nx] == false) {
			flag[ny][nx] = true;
			if (dfs(arr, flag, ny, nx)) {
				// 경로 찾으면 종료
				return true;
			}
		}
	}

	// 파이프 설치 경로 없음		
	return false;

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c;

	vector<vector<char>> arr(r + 1, vector<char>(c + 1));

	// 각각의 열마다 가능한 이동경로 담기 
	vector<vector<bool>> flag(r + 1, vector<bool>(c + 1, false));
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> arr[i][j];
		}
	}

	// 첫행부터 끝행까지 파이프라인 형성 체크
	for (int i = 1; i <= r; i++) {
		dfs(arr, flag, i, 1);
	}

	cout << cnt;
	return 0;
}