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

int n,idx,res=999999;
int v[21][21];
unordered_map<int, int> my_hash;
vector<int> s;

bool check[21];

void fun(int x, int cnt) {
	if (cnt == n / 2) {
		int a = 0, b = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (check[i] && check[j]) {
					a += v[i][j];
				}
				if (check[i] == false && check[j] == false) {
					b += v[i][j];
				}
			}
		}
		int temp = abs(a - b);
		if (temp < res) res = temp;
		return;
	}

	for (int i = x; i < n; i++) {
		check[i] = true;
		fun(i + 1, cnt + 1);
		check[i] = false;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> v[i][j];
		}
	}
	fun(1, 0);
	cout << res;
	return 0;
}

