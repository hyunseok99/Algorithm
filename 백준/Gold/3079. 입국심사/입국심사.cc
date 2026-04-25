#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <limits>
using namespace std;

vector<int> v;

int main() {
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	
	long long start = 0; 
	long long end = m * (long long)1000000000;

	while (start < end) {
		long long man = 0;
		long long mid = (start + end) / 2;
		for (int i = 0; i < n; i++) {
			man += mid / v[i];
            if (man >= m) break;
		}
		if (man < m) start = mid + 1;
		else { 
			end = mid; 
		}
	}

	cout << end;
	return 0;
}