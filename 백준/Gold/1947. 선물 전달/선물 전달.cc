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

long long arr[1000001];

int main() {
	int n;
	//long long calc = 1ll;
	//long long res = 0ll;
	int share = 1000000000;

	cin >> n;
	if (n <= 3) {
		cout << n - 1;
		return 0;
	}
	arr[2] = 1;
	arr[3] = 2;

	for (int i = 4; i <= n; i++) {
		arr[i] = ((arr[i - 1] + arr[i - 2]) * (i - 1)) % share;
	}

	cout << arr[n];
	return 0;
}