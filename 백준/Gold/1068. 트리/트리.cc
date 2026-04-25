#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <map>
using namespace std;


int n, m, cnt, call;
vector<int> v[51];

int dfs(int x) {
	if (x == m) return -1;
	if (v[x].size() == 0) {
		cnt++;
		return 0;
	}
	for (int i = 0; i < v[x].size(); i++) {
		int tmp = dfs(v[x][i]);
		if (tmp == -1 && v[x].size() == 1) cnt++;
	}
	return 0;
}

void fun() {
	dfs(call);
	cout << cnt;
}
int main() {
	cin >> n;
	// -1 경우 추가
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (k == -1) call = i;
		else v[k].push_back(i);
	}
	
	//cin >> m;
	cin >> m;
	fun();
	
	return 0;
}