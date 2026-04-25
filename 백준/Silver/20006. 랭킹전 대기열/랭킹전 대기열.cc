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
#include <string>
#include <deque>
using namespace std;

int p, m;

bool compare(pair<int, string> a, pair<int, string> b) {
	return a.second < b.second;
}

void check(pair<int, string> &lev, vector<vector<pair<int, string>>>& arr) {
	int room = 0;
	while (1) {
		if (arr[room].size() == m) {
			room += 1;
		}
		else {
			if (arr[room].empty()) {
				arr[room].push_back(lev);
				return;
			}
			else {
				if (arr[room][0].first <= (lev.first + 10) && arr[room][0].first >= (lev.first - 10)) {
					arr[room].push_back(lev);
					return;
				}
				else {
					room += 1;
				}
			}

		}
	}
	return;
}

int main() {
	cin >> p >> m;
	vector<vector<pair<int, string>>> arr(300);
	
	int room = 0;
	for (int i = 0; i < p; i++) {
		int lev;
		string name;
		cin >> lev >> name;
		pair<int, string> tmp = { lev, name };
		check(tmp, arr);
	}

	int idx = 0;
	while (1) {
		if (arr[idx].size() == 0) {
			break;
		}
		if (arr[idx].size() == m) {
			cout << "Started!" << "\n";
			sort(arr[idx].begin(), arr[idx].end(), compare);
			for (int i = 0; i < arr[idx].size(); i++) {
				cout << arr[idx][i].first << " " << arr[idx][i].second << "\n";
			}
		}
		else {
			cout << "Waiting!" << "\n";
			sort(arr[idx].begin(), arr[idx].end(), compare);
			for (int i = 0; i < arr[idx].size(); i++) {
				cout << arr[idx][i].first << " " << arr[idx][i].second << "\n";
			}
		}
		idx += 1;
	}

	return 0;
}