#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

vector<long long> v;
int main() {
	for (int i = 1; i <= 1023; i++) {
		long long num = 0;
		int tmp = i;
		for (int idx = 9; idx >= 0; idx--) {
			if (tmp % 2 == 1)
				num = 10 * num + idx;
			tmp = tmp/2;
		}
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int n;
	cin >> n;
	if (n > 1022) {
		cout << "-1";	
	}
	else cout << v[n];
	
	return 0;
}