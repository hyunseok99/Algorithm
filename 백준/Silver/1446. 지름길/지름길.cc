#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <set>
#include <map>
#include <numeric>
using namespace std;

int n, d;
int dist[10001];

vector<int> first;
vector<int> last;
vector<int> distan;

void getMin() {
	int current = 0;
	while (current <= d) {
		if (current == 0) {
			dist[0] = 0;
		}
		else {
			dist[current] = dist[current - 1] + 1;
		}

		for (int i = 0; i < n; i++) {
			if (last[i] == current) {
				dist[current] = min(dist[current], (dist[first[i]] + distan[i]));
			}
		}
		current++;
	}
	cout << dist[d];
	return;
}

int main() {
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int start, end, route;
		cin >> start >> end >> route;
		first.push_back(start);
		last.push_back(end);
		distan.push_back(route);
	}
	getMin();
	return 0;
}
