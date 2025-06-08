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


int R, C, T;
int sumTime, res;

// 상 하 좌 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// cleaner idx 0: 위, 1: 아래
vector<int> cleaner;

// 공기청정기 이동 계산 함수 
void doClean(vector<vector<int>>& arr) {
	// 시계방향 작동
	int startX = cleaner[0];
	int tmp = 0;
	for (int i = 1; i < C; i++) {
		int nTmp = arr[startX][i];
		arr[startX][i] = tmp;
		tmp = nTmp;
	}
	for (int i = startX - 1; i >= 0; i--) {
		int nTmp = arr[i][C - 1];
		arr[i][C - 1] = tmp;
		tmp = nTmp;

	}
	for (int i = (C - 2); i >= 0; i--) {
		int nTmp = arr[0][i];
		arr[0][i] = tmp;
		tmp = nTmp;

	}
	for (int i = 1; i < startX; i++) {
		int nTmp = arr[i][0];
		arr[i][0] = tmp;
		tmp = nTmp;

	}

	// 반시계방향 작동
	startX = cleaner[1];
	tmp = 0;
	for (int i = 1; i < C; i++) {
		int nTmp = arr[startX][i];
		arr[startX][i] = tmp;
		tmp = nTmp;

	}
	for (int i = startX + 1; i < R; i++) {
		int nTmp = arr[i][C - 1];
		arr[i][C - 1] = tmp;
		tmp = nTmp;

	}
	for (int i = (C - 2); i >= 0; i--) {
		int nTmp = arr[R - 1][i];
		arr[R - 1][i] = tmp;
		tmp = nTmp;

	}
	for (int i = R - 2; i > startX; i--) {
		int nTmp = arr[i][0];
		arr[i][0] = tmp;
		tmp = nTmp;
	}
}

// 미세먼지 확산 계산 함수
void moveDust(vector<vector<int>>& arr) {
	vector<vector<int>> tmp(R, vector<int>(C));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int val = arr[i][j];
			if (arr[i][j] != 0 && arr[i][j] != -1) {
				int nx;
				int ny;
				for (int k = 0; k < 4; k++) {
					nx = i + dx[k];
					ny = j + dy[k];
					if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
						if (arr[nx][ny] == -1) continue;
						tmp[nx][ny] += (val / 5);
						arr[i][j] -= (val / 5);
					}
				}
			}
		}

	}

	// 모든 미세먼지 이동 계산 후에 기존 남아있는 미세먼지에 이동 미세먼지 합산
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (tmp[i][j] != 0) {
				arr[i][j] += tmp[i][j];
			}
		}
	}

	// 공기 청정기 이동 함수 호출
	doClean(arr);
}


int main() {
	cin >> R >> C >> T;
	vector<vector<int>> arr(R, vector<int>(C));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int tmp;
			cin >> tmp;
			arr[i][j] = tmp;
			if (tmp == -1) {
				cleaner.push_back(i);
			}
		}
	}

	while (sumTime < T) {
		moveDust(arr);
		sumTime++;
	}

	// 결과 연산 & 출력
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] != -1) {
				res += arr[i][j];
			}
		}
	}

	cout << res;

	return 0;
}