#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <math.h>
using namespace std;


int n, m,cnt1,cnt2, res = 100000000;
bool flag[51][51];
map<int, pair<int,int>> v;
map<int ,pair<int, int>> v2;

void distance() {
	int total = 0;
	for (int i = 0; i < v2.size(); i++) {
		int min = 100000000;
		for (int j = 0; j < v.size(); j++) {
			if (flag[v[j].first][v[j].second]) {
				int dist = abs(v2[i].first - v[j].first) + abs(v2[i].second - v[j].second);
				if (min > dist) min = dist;
			}
		}
		total += min;

	}
	if (res > total) res = total;
}

void comb(int index, int start) {
	if (index == m) {
		distance();
	}

	for (int i = start; i < v.size(); i++) {
		if (!flag[v[i].first][v[i].second]) {
			flag[v[i].first][v[i].second] = true;
			comb(index+1, i + 1);
			flag[v[i].first][v[i].second] = false;

		}
	}
}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> t;
			if (t == 1) {
				v2[cnt2]=(make_pair(i, j));
				cnt2++;
			}
			if (t == 2) {
				v[cnt1]=(make_pair(i, j));
				cnt1++;

			}
		}
	}

	comb(0,0);

	cout << res;
	return 0;
}