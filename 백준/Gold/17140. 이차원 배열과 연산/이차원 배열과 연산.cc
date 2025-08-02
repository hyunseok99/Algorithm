#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int r, c, k;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
			return a.first < b.first;
	}
}


bool check(vector<vector<int>>& arr) {
	if (arr[r][c] == k) {
		return true;
	}
	return false;
}

void calcRow(vector<vector<int>>& arr, int& row, int& col) { // R연산 row >= col
	if (col >= 100) return;
	int curCol = col;
	// col 갱신 
	for (int i = 1; i <= row; i++) {
		vector<int> cnt(101);
		vector<pair<int, int>> v;
		for (int j = 1; j <= col; j++) {
			cnt[arr[i][j]]++;
		}
		for (int j = 1; j <= 100; j++) {
			if (cnt[j] != 0) {
				v.push_back({ j, cnt[j] });
			}
		}
		sort(v.begin(), v.end(), cmp);
		int idx = 1;
		for (int j = 0; j < v.size(); j++) {
			pair<int, int> tmp = v[j];
			if (idx <= 100) {
				arr[i][idx++] = tmp.first;
				arr[i][idx++] = tmp.second;
			}
		}
		while (idx <= col) {
			arr[i][idx++] = 0;
		}
		curCol = max(curCol, (int)(2 * v.size()));
	}
	col = curCol;
	if (col > 100) col = 100;
}

void calcCol(vector<vector<int>>& arr, int& row, int& col) { // C연산 row < col
	if (row >= 100) return;
	int curRow = row;
	for (int j = 1; j <= col; j++) {
		vector<int> cnt(101);
		vector<pair<int, int>> v;
		for (int i = 1; i <= row; i++) {
			cnt[arr[i][j]]++;
		}
		for (int i = 1; i <= 100; i++) {
			if (cnt[i] != 0) {
				v.push_back({ i, cnt[i] });
			}
		}
		sort(v.begin(), v.end(), cmp);
		int idx = 1;
		for (int i = 0; i < v.size(); i++) {
			pair<int, int> tmp = v[i];
			if (idx <= 100) {
				arr[idx++][j] = tmp.first;
				arr[idx++][j] = tmp.second;
			}
		}
		while(idx <= row){
			arr[idx++][j] = 0;
		}
		curRow = max(curRow, (int)(2 * v.size()));
	}
	row = curRow;
	if (row > 100) row = 100;
}

// time에 따른 R,C 연산 
void calc(vector<vector<int>>& arr, int& row, int& col) {
	if (row >= col) {
		calcRow(arr, row, col);
	}
	else {
		calcCol(arr, row, col);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c >> k;
	vector<vector<int>> arr(101, vector<int>(101));
	int col = 3;
	int row = 3;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}
	int time = 0;
	while (time <= 100) {
		if (time == 52) {
			int s = 52;

		}
		if (check(arr)) {
			break;
		}
		calc(arr, row, col);
		time++;
	}
	if (time > 100) {
		cout << -1;
	}
	else {
		cout << time;
	}
	return 0;
}