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

int n, m, res;
unordered_map<int,int> hash_map;


int main() {
	int cnt = 0;

	cin >> n >> m;

	for (int i = 0; i < n + m; i++) {
		int x;
		cin >> x;
		if (hash_map.count(x) == 0) {
			hash_map[x] = x;
		}
		else {
			hash_map.erase(x);
		}
	}
	cout << hash_map.size();

	return 0;
}