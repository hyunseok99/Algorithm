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
pair<int, int> t;
int type[101];
bool check[101];

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	for (int i = 0; i < k; i++) {
		if (!check[v[i]]) {
			if (idx < n) {
				check[v[i]] = true;
				type[idx++] = v[i];
			}
			else {
				int last = -1;
				int take = -1;
				for (int j = 0; j < n; j++) {
					int tmp = 0;
					for (int l = i + 1; l < k; l++) {
						if (v[l] == type[j]) {
							break;
						}
						tmp++;
					}
					if (tmp > last) {
						last = tmp;
						take = j;
					}
				}
				check[type[take]] = false;
				type[take] = v[i];
				check[v[i]] = true;
				res++;
			}
		}
	}
	cout << res;
	return 0;
}
