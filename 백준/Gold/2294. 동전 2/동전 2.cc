#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	vector<int> dp(k + 1, 10001);
	// 0과 1의 배낭문제와 유사 
	// dp[x] -> x원을 만들때 드는 최소한의 동전 갯수 
	// dp[x] = min(dp[x], dp[x-(x-1).val] + 1)
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		// 이 동전 여러번 사용 가능 -> val부터 돌면 val을 여러번 사용하는 것도 포함
        for (int j = val; j <= k; j++) {
			// val을 사용한 경우와 사용하지 않은 경우,
			if (dp[j - val] != 10001) {
				dp[j] = min(dp[j - val] + 1, dp[j]);
			}
		}
	}

	if (dp[k] == 10001) {
		dp[k] = -1;
	}

	cout << dp[k];
	return 0;
}