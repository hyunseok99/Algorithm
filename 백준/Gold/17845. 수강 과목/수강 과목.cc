#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	// 중요도, 시간
	vector<pair<int, int>> v(k);

	// dp[x][y] : x번 과목까지 고려했을 때 y시간까지 들을 수 있는 과목의 최대값
	// dp[1][3] = 3, dp[2][3] = 4, -> dp[2][6] = dp[1][3] + dp[2][3] = 7  
	vector<vector<int>> dp(k+1, vector<int>(n + 1));

	for (int i = 0; i < k; i++) {
		int s, t;
		cin >> s >> t;
		v[i] = { s,t };
	}


	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			// 이번 과목을 선택하지 않는 경우
			dp[i][j] = dp[i - 1][j];

			// 이번 과목을 선택하는 경우
			if (j >= v[i-1].second) {
				dp[i][j] = max((dp[i - 1][j - v[i-1].second] + v[i-1].first), dp[i][j]);
			}

		}
	}
	for (int i = 0; i <= n; i++) {
		res = max(res, dp[k][i]);

	}
	cout << res;
	return 0;
}
