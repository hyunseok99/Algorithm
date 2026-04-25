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

int n, k, idx, res = 0;
unordered_map<int, int> my_hash;
vector<int> v;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	cin >> k;

	sort(v.begin(), v.end());
	
	int start = 0; int back = n - 1;
	while (start < back) {
		int sum = v[start] + v[back];
		if (sum > k) back--;
		else if (sum < k) start++;
		else {
			res++;
			start++;
			back--;
		}
	}
	cout << res;
	return 0;
}
