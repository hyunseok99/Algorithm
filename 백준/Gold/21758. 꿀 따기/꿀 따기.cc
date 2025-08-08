#include <iostream>
#include <algorithm>
using namespace std;

int n, res;

void getMaxHoney(int beeA, int beeB, int house, vector<int>& memo, vector<int>& memoSum) {
	// 벌과 꿀통들의 위치 관계 3가지
	int sum;
	if (house < beeA){
		// house < beeA < beeB
		sum =
			memoSum[beeB] - memo[beeB] - memo[beeA] - memoSum[house] + memo[house] + memoSum[beeA] - memo[beeA] - memoSum[house] + memo[house];
	}
	else if (beeB < house) {
		// beeA < beeB << house
		sum =
			memoSum[house] - memoSum[beeB] + memoSum[house] - memoSum[beeA] - memo[beeB];
	}
	else {
		// beeA < house << beeB
		sum =
			memoSum[house] - memoSum[beeA] + memoSum[beeB] - memoSum[house] - memo[beeB] + memo[house];
	}
	// 최대 수집꿀 갱신
	res = max(res, sum);
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
	// a -> h 까지의 꿀의양 sum[h] - sum[a]의 절댓값  

	// 2개의 벌 놓을 위치 선택
	vector<int> comb(n);
	comb[n-1] = 1;
	comb[n-2] = 1;
	do {
		vector<int> v; // 벌 위치 무조건 v[0] < v[1]
		for (int i = 0; i < comb.size(); i++) {
			if (comb[i] == 1) {
				v.push_back(i);
			}
		}
		// 벌집 위치
		for (int i = 0; i < n; i++) {
			if (i == v[0] || i == v[1]) {
				continue;
			}
			else {
				getMaxHoney(v[0], v[1], i, memo, memoSum);
			}
		}
	} while (next_permutation(comb.begin(), comb.end()));

	cout << res;
	return 0;
}
