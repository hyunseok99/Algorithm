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

pair<int, int> ans;
bool flag[1000001];
bool flag2[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 2; i < 1000000; i++) {
		if (!flag[i]) {
			int t = 2;
			for (int j = i*t; j < 1000000; j=i*(++t)) {
				flag[j] = true;
			}
		}
	}

	int k;
	while (1) {
		cin >> k;
		if (k == 0) break;
		
		ans = { 0,0 };
		for (int i = 3; i < k; i++) {
			if (flag[i]) continue;
			else {
				int j = k - i;
				if (flag[j]) continue;
				else {
					ans = { i,j };
					break;
				}
			}
		}
		if (ans.first==0 && ans.second==0){
			cout << "Goldbach's conjecture is wrong.\n";
		}
		else cout << k << " = " << ans.first << " + " << ans.second << "\n";
	}
	
	return 0;
}