#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <set>
#include <map>
#include <numeric>
using namespace std;

int n;
int node[101][101];

int main() {
	int res = -1;

	cin >> n;

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		node[a][b] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (node[j][i] == 1 && node[i][k] == 1) {
					node[j][k] = 1;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (node[j][i] == 1) {
				cnt++;
			}
		}
		if (cnt == n - 1) {
			res = i;
			break;
		}
	}

	cout << res;
	return 0;
}