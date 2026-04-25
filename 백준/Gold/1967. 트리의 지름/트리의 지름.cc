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

//1967
// 2개의 점을 잇는 경로 최대 10000 C 2 -> 5000*4999 개
// root_node = 1 
// depth가 같고 같은 부모 가질 때 weight 큰거 골라야 함		
// 최대는 무조건 leaf_node 2개 골라야 함	
// leaf_node 2개 고르고 부모 같아지는 경우의 depth까지 누적 합이 지름 
// -> 이거 최대 ㄱㄱ 이러면 시간 초과남 -> root부터 최대가 되도록 하는게 맞다
int res = -1;
int cnt = 0;
int flag[10001];

void get_radius(int node, vector<vector<pair<int, int>>>& v) {
	flag[node] = 1;
	for (int i = 0; i < v[node].size(); i++) {
		// leaf_node면 sum
		if (flag[v[node][i].first] == 0) {
			cnt += v[node][i].second;
			res = max(res, cnt);
			get_radius(v[node][i].first, v);
			cnt -= v[node][i].second;
		}
	}
}


int main() {
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> v(n+1);
	for (int i = 1; i < n; i++) {
		int a, b, c;
		// parent, child, weight
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	
	for (int i = 1; i <= n; i++) {
		get_radius(i, v);
		for (int j = 1; j <= n; j++) {
			flag[j] = 0;
		}
	}

	if (n == 1) res = 0;
	cout << res;

	return 0;
}