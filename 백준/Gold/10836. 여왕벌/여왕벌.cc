#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;


int n, m;

int main() {
	cin >> m >> n;
	// pair.first: 애벌래 크기, second: 커지는 정도
	// 핵심은 별레가 커지는 정도는 해당 좌표의 x축이 0인 값의 증분이 답임 
	vector<vector<pair<int, int>>> node(m, vector<pair<int, int>>(m, { 1,0 }));

	// idxLine: 커지는 정도 증가량의 변화가 생기는 idx 
	// ex) 2 3 2 -> 0 1| 2 3 4 | 5 6  -> 경계는 2, 5   ,  0 6 1 ->  | 0 1 2 3 4 5  | 6  -> 경계는 0, 6 , 0 0 7 ->  | | 123.. -> 0 0
	// idx: 0,1,2 ... -> [m-1][0], [m-2][0]... [0][0], ... [0][m-1] 
	vector<int> idxLine(2 * m - 1 );

	for (int i = 0; i < n; i++) {
		// 0,1,2 갯수 입력 -> 필요한건 0->1 경계, 1->2 경계
		int idx = 0;
		for (int j = 0; j < 3; j++) {
			int t;
			cin >> t;
			if (j < 2) {
				idx += t;
				if (idx >= (2 * m - 1)) continue;
				idxLine[idx]++;
			}
		}
	}

	int sizeRatio = 0;
	for (int i = 0; i < idxLine.size(); i++) {
		if (idxLine[i] != 0) {
			sizeRatio += idxLine[i];
		}
		if (m - i - 1 >= 0) {
			node[m - 1 - i][0].first += sizeRatio;
			node[m - 1 - i][0].second += sizeRatio;
		}
		else {
			node[0][i - m + 1].first += sizeRatio;
			node[0][i - m + 1].second += sizeRatio;
			// 나머지 갱신
			for (int j = 1; j < m; j++) {
				node[j][i - m + 1].first += sizeRatio;
			}
		}
	}


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << node[i][j].first << " ";
		}
		cout << "\n";
	}

	return 0;
}