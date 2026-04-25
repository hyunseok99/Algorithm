#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <string>
#include <unordered_set>
#include <numeric>
#include <climits>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
using namespace std;

int n,idx;
long long cnt;
vector<int> v;
unordered_map<int, int> my_hash;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < n; i++) {
		while (idx < n) {
			if (my_hash.count(v[idx]) !=0 ) break;
			my_hash[v[idx]] = 1;
			idx++;
		}
		cnt += idx - i;
		my_hash.erase(v[i]);
	}
	cout << cnt;
	return 0;

}

