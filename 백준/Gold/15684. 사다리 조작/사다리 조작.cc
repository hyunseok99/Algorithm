#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <string>
#include <unordered_set>
#include <numeric>
#include <climits>
#include <stack>
#include <map>
#include <set>
using namespace std;

int n, m, h, cnt=-1;
bool arr[32][12];

bool fun();

void bt(int depth, int lev) {
	if (depth == lev) {
		bool check = fun();
		if (check) {
			cnt = lev;
			cout << lev;
			exit(0);
		}
		return;
	}

	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= h; i++) {
			if (arr[i][j] || arr[i][j - 1] || arr[i][j + 1]) continue;
			arr[i][j] = true;
			bt(depth + 1, lev);
			arr[i][j] = false;
			while (!arr[i][j - 1] && !arr[i][j + 1])i++;
		}
	}
	return;

}

bool fun() {
	for (int j = 1; j <= n; j++) {
		int temp = j;
		for (int i = 1; i <= h; i++) {
			if (arr[i][temp]) temp++;
			else if( arr[i][temp-1] ) temp--;
		}
		if (temp != j) return false;
	}
	return true;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = true;
	}

	for (int i = 0; i <= 3; i++) {
		bt(0, i);
	}
	cout << cnt;

	return 0;
}