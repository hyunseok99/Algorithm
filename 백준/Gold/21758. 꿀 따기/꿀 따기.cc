#include <iostream>
#include <algorithm>
using namespace std;

int n, res;

void getMaxHoney(vector<int>& memo, vector<int>& memoSum) {
	// 벌과 꿀통들의 위치 관계 3가지

	// 1. 꿀벌 벌집 꿀벌인 경우 -> 사이의 벌집의 값이 최소인 경우 
	for (int i = 1; i <= n - 2; i++) {
		int cur = memoSum[n - 1] - memo[0] - memo[n - 1] + memo[i];
		res = max(res, cur);
	}

	// 2. 벌집 꿀벌 꿀벌인 경우 -> 벌집이 0번에 위치하기 마지막 벌은 n-1 위치여야 최대 
	for (int i = 1; i <= n - 2; i++) {
		int cur = memoSum[n - 1] - memo[n - 1] - memo[i]
			+ memoSum[i] - memo[i];
		res = max(res, cur);
	}

	// 3. 꿀벌 꿀벌 벌집인 경우 -> 벌집이 n-1에 위치하고, 첫벌은 0에 위치해야 최대
	for (int i = 1; i <= n - 2; i++) {
		int cur = memoSum[n - 1] - memoSum[0] - memo[i] + memoSum[n - 1] - memoSum[i];
		res = max(res, cur);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	vector<int> memo(n);
	vector<int> memoSum(n); // 누적합
	for (int i = 0; i < n; i++) {
		cin >> memo[i];
	}

	// 누적합 갱신
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			memoSum[i] = memo[i];
		}
		else {
			memoSum[i] = memoSum[i - 1] + memo[i];
		}
	}

	// 최대값 구하기
	getMaxHoney(memo, memoSum);

	cout << res;
	return 0;
}