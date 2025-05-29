#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <set>
#include <map>
#include <numeric>
using namespace std;
int n, m, k;
int my_map[21][21];

// 주사위 위치 
int x, y;

// dir[idx]: idx가 1,2,3,4 각각 동서북남
int dir_x[5] = { -3, 0, 0, -1, 1 };
int dir_y[5] = { -3, 1, -1, 0, 0 };

// 현재 주서위의 눈 상태: 윗면,윗면 기준 서쪽, 동쪽, 북쪽, 남쪽, 바닥
int dice[6] = { 0, 0, 0, 0, 0, 0 };

// 주사위 눈 갱신 함수 
void assign_num(int dir) {
	// 동서북남 1,2,3,4
	int tmp = dice[0];
	if (dir == 1) {
		// 윗면 기준 북,남 제외 이동 idx: 0,1,2,5
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[2];
		dice[2] = tmp;
	}
	else if (dir == 2) {
		// idx: 0,1,2,5
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[1];
		dice[1] = tmp;
	}
	else if (dir == 3) {
		// idx: 0,3,4,5
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[3];
		dice[3] = tmp;

	}
	else if (dir == 4) {
		// idx: 0,3,4,5;
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[4];
		dice[4] = tmp;
	}
	return;
}
// 이동 명령 수행 함수
void my_order(int dir) {
	int new_x = x + dir_x[dir];
	int new_y = y + dir_y[dir];
	if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m) {
		assign_num(dir);
		if (my_map[new_x][new_y] == 0) {
			my_map[new_x][new_y] = dice[5];
		}
		else {
			dice[5] = my_map[new_x][new_y];
			my_map[new_x][new_y] = 0;
		}
		x = new_x;
		y = new_y;
		cout << dice[0] << "\n";
	}
	return;
}

int main() {
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> my_map[i][j];
		}
	}

	// k번 명령 수행
	for (int i = 0; i < k; i++) {
		int dir;
		cin >> dir;
		my_order(dir);
	}

	return 0;
}