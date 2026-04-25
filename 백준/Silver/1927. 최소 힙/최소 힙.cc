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
#include <cmath>
using namespace std;

int n;
priority_queue<int,vector<int>, greater<int>> pq;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
    
    cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			if (!pq.empty()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else {
				cout << 0 << "\n";
			}
		}
		else {
			pq.push(x);
		}
	}
	return 0;
}
