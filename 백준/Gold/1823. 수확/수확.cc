#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <set>
using namespace std;

vector<int> v;

int dp[2001][2001];

int func_dp(int left, int right, int cnt) {
	if (left > right) return 0;
	if (dp[left][right] != 0) return dp[left][right];

	return dp[left][right] = max(func_dp(left + 1, right, cnt + 1) + v[left] * cnt, func_dp(left, right - 1, cnt + 1) + v[right] * cnt);
}


int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	
	int cnt = 1;
	cout << func_dp(0, n - 1, cnt);

	return 0;
}