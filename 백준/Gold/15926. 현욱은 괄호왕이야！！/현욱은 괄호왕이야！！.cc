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

int t,n,m,cnt,ans;
int str_len[200002];
void fun(string str) {
	vector<int> v;
	cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') v.push_back(i);
		else if (!v.empty() && str[i] == ')') {
			str_len[v.back()] = 1;
			str_len[i] = 1;
			v.pop_back();
		}
	}
	for (int i = 0; i < str.size(); i++) {
		if (str_len[i] == 1) {
			cnt++;
		}
		else {
			ans = max(ans, cnt);
			cnt = 0;
		}
	}
	ans = max(ans, cnt);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	string str;
	cin >> str;

	fun(str);

	cout << ans;
	return 0;
}