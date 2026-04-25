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

int n,val,val2,ans;
int price[100001];

struct comp{
	bool operator()(pair<int, int> x, pair<int, int> y) {
		if (x.first == y.first) {
			return x.second < y.second;
		}
		return x.first < y.first;
	}
};

priority_queue <pair<int, int>, vector<pair<int, int>>, comp> q;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p, d;
		cin >> p >> d;
		q.push({ p,d });
	}

	for (int i = 0; i < n; i++) {
		pair<int, int> temp = q.top();
		q.pop();
		for (int j = temp.second; 1 <= j; j--) {
			if (price[j] == 0) {
				price[j] = temp.first;
				ans += price[j];
				break;
			}
		}
	}
	
	cout << ans;
}