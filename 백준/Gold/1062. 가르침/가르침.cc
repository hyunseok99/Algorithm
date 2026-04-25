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
using namespace std;

int n,k,cnt,res= -1;
string str[51];
bool check[26];

void fun(int x,int lev) {
	if (lev == k) {
		bool type;
		cnt = 0;
		for (int j = 0; j < n; j++) {
			type = true;
			for (int k = 0; k < str[j].size(); k++) {
				if (!check[str[j][k] - 'a']) {
					type = false;
					break;
				}
			}
			if (type == true) {
				cnt++;
			}
		}
		res = max(res, cnt);
		return;
	}

	for (int i = x; i < 26; i++) {
		if (check[i]) continue;
		check[i] = true;
		fun(i, lev + 1);
		check[i] = false;
	}
	return;
}



int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	if (k < 5) {
		cout <<"0";
		return 0;
	}
	check['a'-'a'] = true;
	check['n' - 'a'] = true;
	check['t' - 'a'] = true;
	check['i' - 'a'] = true;
	check['c' - 'a'] = true;
	k = k - 5;
	fun(0, 0);
	cout << res;
	return 0;
}