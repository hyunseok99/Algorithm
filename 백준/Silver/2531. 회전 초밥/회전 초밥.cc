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

int belt[30001];
unordered_map<int, int> myMap;
int res_max = -1;

void getMax(int n, int k, int c, int cntSum) {
	for (int i = 1; i <= n; i++) {
		int last = (i + k);
		if (last > n) {
			last = last - n;
		}

		if (myMap[belt[i]] == 1) {
			cntSum -= 1;
		}
		myMap[belt[i]] = myMap[belt[i]] - 1;

		if (myMap[belt[last]] < 1) {
			cntSum += 1;
		}

		myMap[belt[last]] = myMap[belt[last]] + 1;

		if (myMap[c] == 0) {
			res_max = max(res_max, cntSum + 1);
		}
		else {
			res_max = max(res_max, cntSum);
		}

	}
	return;
}

int main() {
	int n, d, k, c;
	int initCnt = 0;
	bool coupon = false;
	cin >> n >> d >> k >> c;
	for (int i = 1; i <= n; i++) {
		int type;
		cin >> type;
		belt[i] = type;
		if (i <= k) {
			if (myMap[type] > 0) {
				myMap[type] = myMap[type] + 1;
			}
			else {
				myMap[type] = 1;
				initCnt += 1;
			}
		}
	}
	res_max = initCnt;
	getMax(n, k, c, initCnt);

	if (res_max == initCnt && myMap[c] == 0) {
		res_max += 1;
	}
	cout << res_max;
	return 0;
} 