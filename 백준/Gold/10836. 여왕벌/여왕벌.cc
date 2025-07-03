

#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;

int n, m;

// 방향 L, D, U
int dx[3] = { 0, -1, -1 };
int dy[3] = { -1, -1, 0 };

void doUp(vector<vector<pair<int, int>>>& node) {
	// x축 연산 이후 y축 연산 
	for (int i = 1; i < m; i++) {

		// x축 
		for (int j = i; j < m; j++) {

			int startX = i;
			int startY = j;
			// 커지는 정도 갱신
			int add = 0; // 증분
			for (int dir = 0; dir < 3; dir++) {
				int nx = startX + dx[dir];
				int ny = startY + dy[dir];
				add = max(add, node[nx][ny].second);
				if (dir == 2) {
					node[startX][startY].second = add;
				}
			}
			// 크기 갱신
			node[startX][startY].first += node[startX][startY].second;
		}

		// y축
		for (int j = i + 1; j < m; j++) {
			int startX = j;
			int startY = i;
			int add = 0;
			for (int dir = 0; dir < 3; dir++) {
				int nx = startX + dx[dir];
				int ny = startY + dy[dir];
				add = max(add, node[nx][ny].second);
				if (dir == 2) {
					node[startX][startY].second = add;
				}
			}
			// 크기 갱신 
			node[startX][startY].first += node[startX][startY].second;
		}
	}
	return;
}

int main() {
	cin >> m >> n;
	// pair.first: 애벌래 크기, second: 커지는 정도
	vector<vector<pair<int, int>>> node(m, vector<pair<int, int>>(m, { 1,0 }));

	for (int i = 0; i < n; i++) {

		vector<int> input;
		// 0,1,2 갯수 입력
		for (int j = 0; j < 3; j++) {
			int t;
			cin >> t;
			for (int k = 0; k < t; k++) {
				input.push_back(j);
			}
		}

		// init (2m-1 개)
		for (int j = 0; j < input.size(); j++) {
			if (j < m) {
				node[m - (j + 1)][0].first += input[j];
				node[m - (j + 1)][0].second = input[j];
			}
			else {
				node[0][j - m + 1].first += input[j];
				node[0][j - m + 1].second = input[j];
			}
		}

		doUp(node);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << node[i][j].first << " ";
		}
		cout << "\n";
	}

	return 0;
}