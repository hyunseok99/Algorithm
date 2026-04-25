#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int T, K;

long long INF = LLONG_MAX;

// 누적합 
long long getSum(int i, int j, vector<long long> &conSum) {
	return conSum[j] - conSum[i-1];
}

void getDp(vector<vector<long long>> &dp, vector<long long>& val) {
	// dp[i][j] -> 2개의 집합으로 나눠서 최소 찾아야 함  dp[i][k] + dp[k+1][j]
	// dp[s][s] = 0 
	
	// 누적합 갱신
	vector<long long> conSum(K + 1);
	for (int i = 1; i <= K; i++) {
		conSum[i] = conSum[i - 1] + val[i];
	}

	// 합치는 연산을 길이가 2부터 ~ k-1까지 순차적으로 수행 
	for (int len = 2; len <= K; len++) {
		for (int i = 1; i <= K - len+1; i++) {
			int j = i + len -1;
			// 처음에 제일 큰 값으로 갱신
			dp[i][j] = INF;	
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][k] + dp[k + 1][j], dp[i][j]);
			}
			// 마지막에 i~j까지의 합도 더해줘야 함 -> 누적합으로 O(1) 이용 
			dp[i][j] += getSum(i, j, conSum	);
		}
	}
	
	cout << dp[1][K] << "\n";
	return;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> K;
		// dp[i][j] : i~j까지 합치는데 드는 최소 비용 
		vector<vector<long long>> dp(K + 1, vector<long long>(K+1));
		vector<long long> val(K + 1);
		for (int j = 1; j <= K; j++) {
			cin >> val[j];
		}
		getDp(dp, val);
	}
	return 0;
}