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

int n,m,cnt=0;
int sum[1206][1206];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	int t;

	for (int i = 1; i <= n; i++) {
		cnt = 0;
		for (int j = 1; j <= n; j++) {
			cin >> t;
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + t - sum[i - 1][j - 1];
		}
	}

	for (int i = 0; i < m; i++) {
		cnt = 0;
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cnt = sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1];
		cout << cnt << "\n";
	}

	return 0;
}