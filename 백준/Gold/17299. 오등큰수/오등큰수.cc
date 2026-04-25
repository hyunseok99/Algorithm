#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <set>
using namespace std;

unordered_map<int, int> my_map;
unordered_map<int, int> my_map2;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
		int n, cnt = 0;
	cin >> n;
	stack<int> seq;
	stack<int> res;
	for (int i = 0; i < n; i++) {
		int m; cin >> m;
		seq.push(m);
		my_map[m]++;
	}

	stack<int> cp_st;
	while (!seq.empty()) {
		int tmp = seq.top(); seq.pop(); 
		while (!cp_st.empty() && my_map[cp_st.top()] <= my_map[tmp]) {
			cp_st.pop();
		}
		
		if (cp_st.empty()) res.push(-1);
		else { res.push(cp_st.top()); }

		cp_st.push(tmp);
	}

	while (!res.empty()) {
		cout << res.top() << " ";
		res.pop();
	}

	return 0;
}