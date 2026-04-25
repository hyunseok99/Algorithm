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

int arr[10001];
int flag[10001];

int n, m;
int top = -1;
void func(int lev, int depth, vector<int> &v) {
	if (depth > m) {
		for (int i = 0; i < m; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = lev; i <= top; i++) {
		if (arr[i] == 0) continue;
		v.push_back(i);
		func(i, depth + 1, v);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		top = top > tmp ? top : tmp;
		arr[tmp] += 1;
	}
	func(1,1,v);
	return 0;
}    