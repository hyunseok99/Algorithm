#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
using namespace std;
#ifdef NDEL

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

vector<long long> v;
int s, c;

long long sum = 0, pa_max = 0;



int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> s >> c;

	for (int i = 0;i < s; i++) {
		long long l;
		cin >> l;
		v.push_back(l);
	}

	if (s == 1) {
		cout << 0;
		return 0;
	}

	 
	for (int i = 0; i < s; i++) {
		sum += v[i];
	}

	// sort(v.begin(), v.end(), greater<long long>());

	long long start = 0LL, end = 0x3f3f3f3f;

	while (start <= end) {
		long long  cnt = 0;
		long long len = (start+end)/2;
		if (len == 0) { cout << "0"; return 0; }
		for (int i = 0; i < s; i++) {
			cnt += v[i] / len;
		}

		if (cnt >= c) {
			start = len+1;
			pa_max = max(len, pa_max);
		}
		else {
			end = len-1;
		}
	}

	cout << sum - pa_max * c;

	return 0;
}
#endif


int main() {
	// x/y = z -> x+k/y+k > z k찾기  
	long long x, y, z, tmp = 0x3fffffff;
	long long k, left = 0, right  = tmp;
	cin >> x >> y;
	z = y * 100 / x;
	while (left <= right) {
		if (z == 100 || z == 99) { tmp = -1; break; }
		k = (left + right) / 2;
		if ((y + k) * 100 / (x + k) > z) { right = k - 1; tmp = min(tmp, k); }
		else left = k+1;
	}
	cout << tmp;

	return 0;
}


