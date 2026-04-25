#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;


vector<double> v;
int main() {
	double n, res = -1;
	int cnt = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		double a;
		cin >> a;
		v.push_back(a);
	}

	while (1) {
		double sum = 1;
		for (auto k = v.begin() + cnt; k != v.end(); k++) {
			sum *= (*k);
			if (sum > res) res = sum;
		}
		cnt++;
		if (cnt == n) break;
	}
	cout << fixed;
	cout.precision(3);
	cout << res;

	return 0;
}