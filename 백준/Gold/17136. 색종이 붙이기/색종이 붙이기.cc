#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;


int res = -1;
int dx[5] = { 1,2,3,4,5 };


void flagCheck(pair<int, int> &pos, int dir, vector<vector<bool>> &flag) {
	int x = pos.first;
	int y = pos.second;

	for (int i = x; i < x + dx[dir]; i++) {
		for (int j = y; j < y + dx[dir]; j++) {
			flag[i][j] = true;
		}
	}
}

void flagUncheck(pair<int, int>& pos, int dir, vector<vector<bool>>& flag) {
	int x = pos.first;
	int y = pos.second;

	for (int i = x; i < x + dx[dir]; i++) {
		for (int j = y; j < y + dx[dir]; j++) {
			flag[i][j] = false;
		}
	}
}

void getRes(vector<vector<bool>>& flag, vector<int>& cntPaper) {

	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		cnt += cntPaper[i];
	}
	if (res == -1) {
		res = cnt;
	}
	else {
		res = min(res, cnt);
	}
}

bool paperSize(vector<int>& cntPaper) {
	int len = 0;
	for (int i = 0; i < 5; i++) {
		len += dx[i] * dx[i] * cntPaper[i];
	}
	if (len > 100) {
		return false;
	}
	else return true;
}

void func(vector<vector<int>>& arr, vector<vector<bool>>& flag, vector<int>& cntPaper) {
	int len = 0;
	for (int i = 0; i < 5; i++) {
		len += cntPaper[i];
	}

	// 만약 이미 res보다 사용한 종이 많으면 스킵 
	if (len > res && res!= -1) {
		return;
	}

	pair<int, int> pos = {-1, -1};
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (pos.first == -1 && arr[i][j] == 1 && !flag[i][j]) {
				pos.first = i;
				pos.second = j;
			}
		}
	}

	if (pos.first == -1) {
		getRes(flag, cntPaper);
		return;
	}

	int x = pos.first;
	int y = pos.second;
	


	for (int i = 0; i <  5; i++) {
		bool check = true;

		// 해당 크기 색종이 모두 사용시 사용 불가
		if (cntPaper[i] >= 5) {
			continue;
		}

		for (int j = x; j < x + dx[i]; j++) {
			for (int k = y; k < y + dx[i]; k++) {
				if (j >= 0 && j < 10 && k >= 0 && k < 10) {
					if (arr[j][k] == 0 || flag[j][k] == true ) {
						check = false;
					}
				}
				else {
					check = false;
				}
			}
		}
		// 해당 색종이 추가 가능 
		if (check) {
			// 해당 경로 추가 및 방문 체크 
			cntPaper[i]++;
			flagCheck(pos, i, flag);
			
			// 재귀 호출
			func(arr, flag, cntPaper);
	

			// 방문 해제 
			cntPaper[i]--;
			flagUncheck(pos, i, flag);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<int>> arr(10, vector<int>(10));
	// n*n 종이 사용 갯수 n:1~5
	vector<int> cntPaper(6);
	// 방문 여부 
	vector<vector<bool>> flag(10, vector<bool>(10, false));

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
		}
	}

	func(arr, flag, cntPaper);

	cout << res;

	return 0;
}