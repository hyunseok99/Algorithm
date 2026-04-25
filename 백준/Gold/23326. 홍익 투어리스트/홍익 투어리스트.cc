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


set<int> check;
int n, q;
int pos = 1;


void func() {
	int query; cin >> query;

	if (query == 1) {
		int tmp;
		cin >> tmp;
		if (check.count(tmp)) check.erase(tmp);
		else check.insert(tmp);
		return;
	}
	else if (query == 2) {
		int tmp;
		cin >> tmp;
		int dist;
		dist = (pos + tmp) % n;
		pos = dist;
		if (dist == 0) {
			pos = n;
		}
		if (pos > n) {
			throw new out_of_range("");
		}
		return;
	}
	else {
		if (check.empty()) {
			cout << -1 << "\n";
			return;
		}

		auto iter = check.lower_bound(pos);

		if (iter == check.end()) {
			cout << n - pos + *check.begin() << "\n"; 
		}
		else { cout << *iter - pos << "\n"; }
		
		return;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		if (t) {
			check.insert(i);
		}
	}

	for (int i = 0; i < q; i++) {
		func();
	}

	return 0;
}