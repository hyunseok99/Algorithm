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

int n, m, req, res;
unordered_map<int,int> hash_map;
unordered_map<int, int> hash_map2;


int piz_a[1001] = { 0, };
int piz_b[1001] = { 0, };

int main() {
	int cnt = 0;

	cin >> req >> n >> m;
	int sum_a = 0,sum_b=0;
	hash_map[sum_a]++;
	hash_map2[sum_b]++;

	for (int i = 1; i <= n; i++) {
		cin >> piz_a[i];
		sum_a += piz_a[i];
	}
	hash_map[sum_a]++;

	for (int i = 1; i <= m; i++) {
		cin >> piz_b[i];
		sum_b += piz_b[i];
	}
	hash_map2[sum_b]++;

	for (int i = 1; i <= n; i++) {
		piz_a[i] = piz_a[i - 1] + piz_a[i];
	}

	for (int i = 1; i <= m; i++) {
		piz_b[i] = piz_b[i - 1] + piz_b[i];
	}

	for (int i= 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int temp = piz_a[j] - piz_a[i];
			hash_map[temp]++;
			hash_map[sum_a - temp]++;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			int temp = piz_b[j] - piz_b[i];
			hash_map2[temp]++;
			hash_map2[sum_b - temp]++;
		}
	}
	
	int x=0,y = 0;
	for (; x <= req; x++) {
		y = req - x;
		if (hash_map[x] != 0 && hash_map2[y] != 0) {
			res += hash_map[x] * hash_map2[y];
		}
	}


	cout << res;
	return 0;

}