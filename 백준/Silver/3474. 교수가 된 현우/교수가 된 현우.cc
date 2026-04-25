#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
using namespace std;


int n, m, cnt, call;


int main() {
	cin.tie(0);
	std::ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		for (int j = 5; j <= t; j *= 5) {
			cnt += t / j;
		}
		cout << cnt << "\n";
		cnt = 0;
	}

	return 0;
	
}