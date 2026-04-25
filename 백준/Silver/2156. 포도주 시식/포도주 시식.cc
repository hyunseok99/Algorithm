#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <set>
#include <map>
#include <numeric>
using namespace std;

int n;
int grape[10001];
int res[10001];

int main() {
	cin >> n;

	// 1잔을 마시는 경우 초기화 
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		grape[i] = t;
	}

	// x잔 존재할 때 최대값 계산
	res[1] = grape[1]; // x=1
	if (n >= 2) { // x=2
		res[2] = grape[1] + grape[2];
	}
	if (n >= 3) { // n=3
		res[3] = max(res[2], max((grape[1] + grape[3]), (grape[2] + grape[3])));
	}

	// 일반적인 경우의 최대값 계산
	// i번째를 먹지 않는 경우와 먹는 경우 (먹는 경우에는 이전 안먹는 경우 or 연속으로 2잔)
	for (int i = 4; i <= n; i++) {
		res[i] = max(res[i - 1], max(grape[i] + res[i - 2]
			, grape[i] + grape[i - 1] + res[i - 3]));
	}

	cout << res[n];

	return 0;
}