#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	vector<int> dp(n+51);

	// dp[x] : x일에 최대 금액 
	for(int i=1; i<=n; i++){
		int t,p;
		cin >> t >> p;
		// i에 상담 안하는 경우
		dp[i+1] = max(dp[i+1],dp[i]);
		// i에 상담 하는 경우
		dp[i+t] = max(dp[i+t], dp[i] + p);
	}
	

	cout << dp[n+1];
	return 0;
}
