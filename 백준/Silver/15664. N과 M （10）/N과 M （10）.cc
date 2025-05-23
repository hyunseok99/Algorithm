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

int n, m;
bool flag[8];
int ans[8];
vector<int> numbers;


void bt(int idx, int lev) {

	if (lev == m) {
		for (int t = 0; t < m; t++) {
			if (t == m - 1) {
				cout << ans[t] << "\n";
			}
			else {
				cout << ans[t] << " ";
			}
		}
		return;
	}

	int comp = 0;
	for (int i = idx; i < n; i++) {
		if (flag[i] || comp == numbers[i]) {
			idx++;
			continue;
		}
		flag[i] = true;
		ans[lev] = numbers[i];
		comp = numbers[i];
		bt(i + 1, lev + 1);
		flag[i] = false;
		idx++;
	}

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		numbers.push_back(t);
	}

	// 오름차순 정렬 
	sort(numbers.begin(), numbers.end());
	bt(0, 0);

	return 0;
}