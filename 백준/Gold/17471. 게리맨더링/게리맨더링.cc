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

int n,m,res= 10000;
bool flag[11];
bool visit[11];
bool connected(vector<int>& v, bool tf);

struct type{
	int num=0;
	vector<int> adj;
};

type req[11];

bool check() {
	vector<int> type1;
	vector<int> type2;
	for (int i = 1; i <= n; i++) {
		if (flag[i]) type1.push_back(i);
		else type2.push_back(i);
	}
	if (type1.empty() || type2.empty()) return false;
	if (connected(type1, true) == false) return false;
	if (connected(type2, false) == false) return false;

	return true;
}

bool connected(vector<int> &v, bool tf) {
	fill(&visit[0],&visit[11],false);
	queue<int> q;
	int cnt = 0;
	q.push(v[0]);

	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		visit[temp] = true;
		cnt++;
		for (int i = 0; i < req[temp].adj.size(); i++) {
			if (flag[req[temp].adj[i]] != tf || visit[req[temp].adj[i]] == true) continue; 
				visit[req[temp].adj[i]] = true;
				q.push(req[temp].adj[i]);
		}
	}
	if (cnt == v.size()) return true;
	else return false;
}

void fun(int x, int lev) {
	if (lev >= 1) {
		if (check()) {
			int a = 0, b = 0;
			for (int j = 1; j <= n; j++) {
				if (flag[j]) {
					a += req[j].num;
				}	
				else {
					b += req[j].num;
				}
			}
			res = min(res, abs(a - b));
		}
	}

	for (int i = x; i <= n; i++) {
		if (flag[i]) continue;
		flag[i] = true;
		fun(x + 1, lev+1);
		flag[i] = false;
	}

}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> req[i].num;
	}
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		for (int j = 1; j <= a; j++) {
			int b;
			cin >> b;
			req[i].adj.push_back(b);
		}
	}
	fun(1, 0);
	if (res == 10000) {
		cout << -1;
	}
	else cout << res;

	return 0;
}