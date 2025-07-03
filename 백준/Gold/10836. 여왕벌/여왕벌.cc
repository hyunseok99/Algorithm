#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;


int n, m;



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
		// x = 0 일떄의 y값의 증분의 합으로 동일 
		for (int j = 0; j < input.size(); j++) {
			if (j < m) {
				node[m - (j + 1)][0].first += input[j];
				node[m - (j + 1)][0].second += input[j];
			}
			else {
				node[0][j - m + 1].first += input[j];
				node[0][j - m + 1].second += input[j];
			}
		}
	}


	for (int i = 1; i < m; i++) {
		for (int j = 1; j < m; j++) {
			node[i][j].first += node[0][j].second;
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