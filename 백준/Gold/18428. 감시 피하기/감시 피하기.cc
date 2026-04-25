#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int n;
string res = "NO";

// 상 하 좌 우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 각각 선생, 학생 위치 
vector<pair<int, int>> teacherPos;
vector<pair<int, int>> studentPos;

void move(int x, int y, int dir, vector<vector<char>>& arr, bool &check) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
		if (arr[nx][ny] == 'S') {
			check = false;
			return;
		}
		else if (arr[nx][ny] == 'O') {
			return;
		}
		else {
			move(nx, ny, dir, arr, check);
		}
	}
	return;

}


bool isSecured(vector<vector<char>>& arr) {
	for (int i = 0; i < teacherPos.size(); i++) {
		int x = teacherPos[i].first;
		int y = teacherPos[i].second;
		for (int dir = 0; dir < 4; dir++) {
			bool check = true;
			move(x, y, dir, arr, check);
			if (check == false) {
				return false;
			}
		}
	}
	return true;
}

void backTracking(int lev, vector<vector<char>>& arr, vector<vector<bool>>& flag) {
	if (lev == 3) {
		if (isSecured(arr)) {
			res = "YES";
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'X' && flag[i][j] == false) {
				flag[i][j] = true;
				arr[i][j] = 'O';
				backTracking(lev + 1, arr, flag);
				arr[i][j] = 'X';
				flag[i][j] = false;
			}
		}
	}
}

int main() {
	cin >> n;
	vector<vector<char>> arr(n, vector<char>(n));
	vector<vector<bool>> flag(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char tmp;
			cin >> tmp;
			arr[i][j] = tmp;
			if (tmp == 'T') teacherPos.push_back({ i, j });
			if (tmp == 'S') studentPos.push_back({ i, j });
		}
	}

	backTracking(0, arr, flag);

	cout << res;

	return 0;
}