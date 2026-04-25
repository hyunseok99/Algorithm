#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
using namespace std;


int n, m, cnt=1;
bool flag[10001];
vector<int> myM[10001];
vector<pair<int,int> > v;

void fun(int x) {
	queue<int> q;
	flag[x] = true;
	q.push(x);

	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		
		for (auto i = 0; i < myM[temp].size(); i++) {
			int ntemp = myM[temp][i];
			if (!flag[ntemp]) {
				flag[ntemp] = true;
				q.push(ntemp);
				cnt++;
			}
		}
	}
	
	while (!q.empty()) {
		int temp = q.front();
		cnt++;
		q.pop();
		fun(temp);
	}
	return;
}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		myM[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		fun(i);
		fill(flag, flag + 10001, 0);
		v.push_back(make_pair(i, cnt));
		cnt = 1;
	}
	
	
	int max = -1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second > max) {
			max = v[i].second;
		}
	}
	
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second == max) {
			cout << v[i].first << " ";
		}
	}
	

	return 0;
}