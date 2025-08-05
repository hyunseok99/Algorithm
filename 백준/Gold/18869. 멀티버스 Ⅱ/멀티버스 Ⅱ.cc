#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, m, res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> m >> n;

	vector<vector<int>> planet(m, vector<int>(n));
	vector<vector<int>> grade(m, vector<int>(n));
	vector<vector<int>> seq(m);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> planet[i][j];
			grade[i][j] = planet[i][j];
		}
		sort(grade[i].begin(), grade[i].end());
		unordered_map<int, int> myMap;
		int num = 1;
		int now = grade[i][0];
		myMap[now] = num;

		for (int j = 1; j < n; j++) {
			if (now == grade[i][j]) continue;
			num++;
			myMap[grade[i][j]] = num;
			now = grade[i][j];
		}

		for (int j = 0; j < n; j++) {
			seq[i].push_back(myMap[planet[i][j]]);
		}
	}

	for (int i = 0; i < m - 1; i++) {
		for (int j = i + 1; j < m; j++) {
			bool flag = true;
			for (int s = 0; s < n; s++) {
				if (seq[i][s] != seq[j][s]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				res++;
			}
		}
	}

	cout << res;
	return 0;
}
