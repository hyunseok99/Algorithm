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

int t,n,m,ans,root,depth;
bool flag[1002];
vector<int> v[1002];

int fun(int x, int lev) {
	if (flag[x]) return 0;
	flag[x] = true;
	for (auto i : v[x]) {
		if (!flag[i]) {
			lev += fun(i, 1);
		}
	}
	return lev;
}

int main(){
	cin >> t;
	for (int i = 0; i < t; i++) {
		v->clear();
		fill(&flag[0], &flag[1002], false);
		root = 0;
		depth = 0;
		cin >> n >> m;
		for (int j = 1; j <= m; j++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
			if (!root) root = a;
		}
		if (m != (n - 1)) cout << "graph\n";
		else {
			if (fun(root, 1) == n) cout << "tree\n";
			else cout << "graph\n";
		}
	}
	return 0;
}