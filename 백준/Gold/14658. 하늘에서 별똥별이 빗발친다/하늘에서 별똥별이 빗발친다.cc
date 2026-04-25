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

vector<pair<int, int>> v;

int main() {
	int n, m, l, k;
	int res = 1;

	cin >> n >> m >> l >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}

	// 특정 별동별의 착수 지점으로 부터 l만큼 가로, 세로 확인해서 그 안에 있는 별똥별 수를 확인
	// 즉 2개의 점을 기준으로 가로 세로로 ㄱㄱ -> 이게 최대가 되는거 찾아볼까? // 같은 돌 2개 -> 최소 1개 ~ x개
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			// i-> x의 시작축으로 , j-> y의 시작축으로 둘의 교집합으로 갯수 구하면 최대가 되는 경우 체크
			int x = v[i].first;
			int y = v[j].second; 
			for (int r = 0; r < k; r++) {
				// r -> 돌의 x좌표가 x+l 사이인지, y좌표가 y+l 사이인지 체크
				if (v[r].first >= x && v[r].first <= (x + l) && v[r].second >= y && v[r].second <= (y + l)) {
					cnt++;
				}
			}
			res = res > cnt ? res : cnt;
			cnt = 0;
;		}
	}

	cout << k-res;
	return 0;
}