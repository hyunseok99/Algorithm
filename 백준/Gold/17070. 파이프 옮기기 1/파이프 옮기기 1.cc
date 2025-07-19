#include <iostream>
#include <vector>
using namespace std;

int n, m;
int res;

// 가로 세로 대각
int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 0, 1 };

// type: 헌재 파이프 방향, dir: 이동 방향
bool regulation(int type, int dir, pair<int, int> newEnd, vector<vector<int>>& arr) {
	int x = newEnd.first;
	int y = newEnd.second;
	if (type == 1) {
		if (dir == 0) {
			if (x >= 1 && x <= n && y >= 1 && y <= n) {
				if (arr[x][y] == 0) {
					return true;
				}
			}
			return false;
		}
		else if (dir == 2) {
			if (x >= 1 && x <= n && y >= 1 && y <= n && arr[x][y] == 0) {
				if (y - 1 >= 1 && y - 1 <= n && arr[x][y - 1] == 0) {
					return true;
				}
			}
			return false;
		}
	}
	else if (type == 2) {
		if (dir == 1) {
			if (x >= 1 && x <= n && y >= 1 && y <= n) {
				if (arr[x][y] == 0) {
					return true;
				}
			}
			return false;
		}
		else if (dir == 2) {
			if (x >= 1 && x <= n && y >= 1 && y <= n && arr[x][y] == 0) {
				if (x-1 >= 1 && x - 1 <= n && arr[x-1][y] == 0) {
					return true;
				}
			}
			return false;
		}
	}
	else { // type == 3 대각인 경우 -> 자동으로 가로, 세로, 대각 검증 
		if (x >= 1 && x <= n && y >= 1 && y <= n) {
			if (arr[x][y] == 0) {
				return true;
			}
		}
		return false;
	}
	return false;
}
// 재귀 함수
void func(pair<int, int> start, pair<int, int> end, vector<vector<int>>& arr) {
	if (end.first == n && end.second == n && arr[end.first][end.second] == 0) {
		res++;
		return;
	}

	if (start.first == end.first) { // 가로인 경우
		for (int i = 0; i < 3; i++) { // 만약 0번 방향 불가능 하면 2번도 불가 
			if (i == 1) continue;
			pair<int, int> newEnd
				= make_pair(end.first + dx[i], end.second + dy[i]);
			if (regulation(1, i, newEnd, arr)) {
				func(end, newEnd, arr);
			}
			else {
				i += 3;
			}
		}
	}
	else if (start.second == end.second) { // 세로인 경우
		for (int i = 1; i < 3; i++) { // 1번 불가능 하면 2번도 불가
			pair<int, int> newEnd
				= make_pair(end.first + dx[i], end.second + dy[i]);
			if (regulation(2, i, newEnd, arr)) {
				func(end, newEnd, arr);
			}
			else {
				i += 3;
			}
		}
	}
	else { // 대각인 경우
		bool flag = true;
		for (int i = 0; i < 3; i++) {
			pair<int, int> newEnd
				= make_pair(end.first + dx[i], end.second + dy[i]);
			if (i == 2 && flag == false) {
				continue;
			}
			if (regulation(3, i, newEnd, arr)) {
				func(end, newEnd, arr);
			}
			else {
				flag = false;
			}
		}
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<vector<int>> arr(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}


	func(make_pair(1, 1), make_pair(1, 2), arr);

	cout << res;
	return 0;
}
