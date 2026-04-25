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

vector<int> v;

int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}

	if (v.size() <= 2) {
		if (v.size() <= 1) {
			cout << "A"; return 0;
		}
		else {
			if (v[0] == v[1]) {
				cout << v[0]; return 0;
			}
			else {
				cout << 'A'; return 0;
			}
		}
	}
	
	set<int>s(v.begin(), v.end());

	if (s.size() == 1) {
		cout << v[0]; return 0;
	}
	int a, b = 0; int r=0;

	if(v[1]-v[0]==0){
		cout << 'B'; return 0;
	}

	a = (v[2] - v[1]) / (v[1] - v[0]);
	b = v[1] - v[0] * a;
	r = (v[2] - v[1]) % (v[1] - v[0]);

	if (r != 0 ) {
		cout << 'B'; return 0;
	}

	int res;
	res = v.back() * a + b;

	for (int i = 0; i < v.size()-1; i++) {
		int j = i+1;
		if (v[i] * a + b != v[j]) {
			cout << 'B'; return 0;
		}
	}
	cout << res;
	return 0;
}


