#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, res;

void calc(vector<int>& num, vector<vector<int>>& node);

void func(vector<vector<int>>& node) {
	// 나갈 타자 순번 선택
	vector<int> bat = { 2,3,4,5,6,7,8,9 };
	do {
		vector<int> num(10);
		num[4] = 1;
		int idx = 1;
		for (int i = 0; i < bat.size(); i++) {
			if (idx == 4) {
				idx++;
			}
			num[idx] = bat[i];
			idx++;
		}

		calc(num, node);
	} while (next_permutation(bat.begin(), bat.end()));
}

// 점수 계산
// num: 선택된 타순 , 
void calc(vector<int>& num, vector<vector<int>>& node) {

	// 현재 타순
	int idx = 1;
	// 현재 점수
	int score = 0;

	for (int round = 1; round <= n; round++) {
		// 이닝별 아웃 카운트  
		int outCnt = 0;
		// 마운드 별 상황
		vector<int> mount(4);
		while (outCnt < 3) {
			if (idx == 10) {
				idx = 1;
			}
			int state = node[round][num[idx]];
			if (state == 0) {
				outCnt++;
			}
			else {
				// 마운트 진루
				for (int i = 3; i >= 1; i--) {
					if (mount[i] != 0) {
						if ((i + state) >= 4) {
							mount[i] = 0;
							score++;
						}
						else {
							mount[i] = 0;
							mount[i + state] = 1;
						}
					}
				}
				// 타자 진루
				if (state >= 4) {
					score++;
				}
				else {
					mount[state] = 1;
				}
			}
			idx++;
		}
	}
	res = max(res, score);

	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	// 이닝별 타자 결과  
	vector<vector<int>> node(n + 1, vector<int>(10));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> node[i][j];
		}
	}

	func(node);
	cout << res;
	return 0;
}
