#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

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