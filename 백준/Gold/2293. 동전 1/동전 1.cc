#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int n, k;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	// 2차원 dp로 하니 메모리 초과
	//vector<vector<int>> dp(n+1, vector<int>(10001,0));
	vector<int> dp(k+1);
	dp[0] = 1; // 0원 만드는 법은 모든 동전 안쓰는 1가지
	for(int i=1; i<= n; i++){
		int val;
		cin >> val;
		for(int j=val; j<=k; j++){
			dp[j] += dp[j-val];
		}
	}

	cout << dp[k];
	return 0;
}