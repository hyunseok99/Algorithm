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

int dist[11][11];
int n;
int dist_sum = 100000;
bool flag[11];



void func() {

	int arr[11][11];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = dist[i][j];
		}
	}

	// 거치는 노드
	for (int i = 0; i < n; i++) {
		//출발 노드
		for (int j = 0; j < n; j++) {
			// 끝 노드
			for (int k = 0; k < n; k++) {
				if (dist[j][k] > dist[j][i] + dist[i][k]) {
					dist[j][k] = dist[j][i] + dist[i][k];
				}
			}
		}
	}
}

void comb(int pos, int dep, vector<int> v) {
	if (dep == n) { 
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			int j = i + 1;
			sum += dist[v[i]][v[j]];
		}
		dist_sum = min(dist_sum, sum);
		return; 
	}
	
	for (int i = 0 ; i < n; i++) {
		if (!flag[i]) {
			flag[i] = true;
			v.push_back(i);
			comb(i, dep + 1, v);
			v.pop_back();
			flag[i] = false;
		}
	}
}


int main() {
	int k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			dist[i][j] = t;
		}
	}
	vector<int> v;
	v.push_back(k);
	flag[k] = true;

	func();
	comb(k,1,v);

	cout << dist_sum;

	return 0;
}