#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <math.h>
using namespace std;


int n, m,l,r,cnt1,cnt2, res ;
priority_queue<int> pq;
/*
void comb(int index, int start) {
	if (index == m) {
		distance();
	}

	for (int i = start; i < v.size(); i++) {
		if (!flag[v[i].first][v[i].second]) {
			flag[v[i].first][v[i].second] = true;
			comb(index+1, i + 1);
			flag[v[i].first][v[i].second] = false;

		}
	}
}
*/



int main() {

	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	pq.push(-64);
	cin >> m;
	res = 64;

	while (res > m) {
		int half = pq.top() / 2;
		pq.pop();
		
		pq.push(half);
		pq.push(half);

		if (res + half >= m) {
			int temp = pq.top();
			pq.pop();
			res += temp;
		}
	}

	cout << pq.size();
	return 0;
}