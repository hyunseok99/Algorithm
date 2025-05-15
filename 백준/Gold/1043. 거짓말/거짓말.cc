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

// truthHuman: n명의 사람 중에서 무조건 진실을 말해야 하는 사람 
// parent: n번째 사람의 union 체크 판단을 위한 지표
int n, m, k;
vector<int> truthHuman;
int parent[51];

int find(int x) {
	if (parent[x] == x) return x;
	else return find(parent[x]);
}

void myUnion(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}

bool check(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return true;
	else return false;
}

int main() {
	cin >> n >> m >> k;
	int res = m;
	vector<vector<int>> v(m + 1);

	// 모든 손님의 parent 자기 자신으로 초기화
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < k; i++) {
		// 진실만을 말해야 하는 경우 
		int t;
		cin >> t;
		truthHuman.push_back(t);
	}

	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		for (int j = 0; j < t; j++) {
			// 파티에 오는 사람 번호 
			int come;
			cin >> come;
			v[i].push_back(come);
		}
	}

	// 파티에 존재하는 사람들 union
	for (int i = 0; i < m; i++) {
		int x = v[i][0];
		for (int j = 1; j < v[i].size(); j++) {
			int y = v[i][j];
			myUnion(x, y);
		}
	}

	// 정답 계산
	for (int i = 0; i < m; i++) {
		bool isTruth = true;
		for (int j = 0; j < v[i].size(); j++) {
			if (isTruth == false) {
				break;
			}
			int x = v[i][j];
			for (int l = 0; l < truthHuman.size(); l++) {
				int y = truthHuman[l];
				// 만약 반드시 진실을 말해야 하는 경우가 포함되어 있으면 체크
				if (check(x, y)) {
					isTruth = false;
					break;
				}
			}
		}
		// 만약 해당 파티에서 진실을 말해야 하는 경우 res -= 1
		if (isTruth == false) {
			res -= 1;
		}
	}

	cout << res;

	return 0;
}