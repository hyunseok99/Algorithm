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

int n,max_dl,res,temp;
int arr[200001];

struct comp{
	bool operator()(pair<int, int> x, pair<int, int> y) {
		if (x.second == y.second) {
			return x.first < y.first;
		}
		return x.second < y.second;
	}
};

priority_queue <pair<int,int>, vector<pair<int,int>>, comp> q;
priority_queue<int> myq[1000001];
int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (max_dl < a) max_dl = a;
		myq[a].push(b);
	}
	for (int i = 1; i <= max_dl; i++) {
		if (res < i) res = i;
		while (!myq[i].empty()) {
			res += myq[i].top();
			myq[i].pop();
		}
	}
	cout << res;
	return 0;
}