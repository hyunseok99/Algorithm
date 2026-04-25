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
using namespace std;

int n,k,max_dl;
long long res;

struct comp{
	bool operator()(pair<int, int>& x, pair<int, int>& y) {
		if (x.second == y.second) {
			return x.first < y.first;
		}
		return x.second < y.second;
	}
};

priority_queue <pair<int,int>, vector<pair<int,int>>, comp> q;
unordered_map<int, queue<int>> q2;
// queue<int> q2[1000001];
priority_queue<int,vector<int>,greater<int>> myq;

int main() {
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		q2[m].push(v);
	}

	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;

		myq.push(c);
	}

	int t = 0;
	while (!myq.empty()) {
		int temp = myq.top();
		myq.pop();
		for (int i = t; i <= temp; i++) {
			if (i >= 1000001) break;
			if (q2.count(i) > 0) {
				while (!q2[i].empty()) {
					q.push({ i,q2[i].front() });
					q2[i].pop();
				}
			}
		}
		t = temp + 1;
		if(!q.empty()) {
			
			res += q.top().second;
			q.pop();
			
		}
	}
	cout << res;
	return 0;
}