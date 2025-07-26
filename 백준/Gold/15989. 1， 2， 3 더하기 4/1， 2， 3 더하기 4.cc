#include <iostream>
#include <vector>
using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> m;

	vector<int> dp(10001);
	dp[0] = 1; // 아무것도 더하지 않는 경우는 1가지 
	for (int i = 1; i <= 10000; i++) {
		dp[i] = 1; // 1개만 사용하는 경우
	}

	for (int i = 2; i <= 10000; i++) {
		dp[i] += dp[i - 2]; // 2개를 추가로 사용하는 경우 
	}

	for (int i = 3; i <= 10000; i++) {
		dp[i] += dp[i - 3]; // 3개를 추가로 사용하는 경우
	}

	for (int i = 0; i < m; i++) {
		cin >> n;
		cout << dp[n] << "\n";
	}

	return 0;
}
