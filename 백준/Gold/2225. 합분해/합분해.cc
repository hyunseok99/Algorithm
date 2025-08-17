#include <iostream>
#include <vector>
using namespace std;

int n, k;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	int divisor = 1000000000;
	// 0~ N원까지 k개 이용해서 구현 
	vector<vector<int>> dp(n + 1, vector<int>(k + 1));
	// dp[n][k] = dp[n][k-1] + dp[n-1][k-1] + dp[n-2][k-1] .... dp[0][k-1]
	// dp[3][2] = dp[3][1] + dp[2][1] + dp[1][1] + dp[0][1];
	// 03,30, 21, 12 = 2, 1, 1
	// dp[4][3] = dp[4][2] + dp[3][2] + dp[2][2] + dp[1][2] + dp[0][2];
	// 004, 040, 400, 013, 031, 103, 130, 301,310,022,202,220, 112, 121, 211
	// dp[4][2] = 5, dp[3][2] = 4, dp[2][2] = 3, dp[1][2] = 2, dp[0][2] = 1;
	// dp[4][2] = dp[4][1] + dp[3][1] + dp[2][1] + dp[1][1] + dp[0][1]
	//			= 1 + 1 + 1 + 1 +1

	//0을 만드는 경우 모두 1
	for (int i = 0; i <= k; i++) {
		dp[0][i] = 1;
	}


	// dp[1][1] = dp[1][0] + dp[0][0]
	// dp[2][1] = dp[2][0] + dp[1][0] + dp[0][0]
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			for (int s = i; s >= 0; s--) {
				dp[i][j] += dp[s][j - 1];
				if (dp[i][j] >= divisor) {
					dp[i][j] %= divisor;
				}
			}
		}
	}

	cout << dp[n][k];
	return 0;
}
