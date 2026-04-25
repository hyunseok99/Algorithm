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
// N,M -> (N, M) 존재 
// 인접: N이 같고 M의 차이가 1(이 경우 0과M은 인접 판정), or M이 같고 n의 차이가 1 
// 필요한것: 1. 인접 판단 및 처리 함수 2. 회전 후 위치 갱신
// 최대 2500개 -> 모두 조회에 시간 오래걸림? no -> 배열 이용

int n, m, t, x, d, k;

struct dot {
	int val;
	bool deleted = false;
};


vector<vector<dot>> v;
set<pair<int, int>> connectedDot;


void print() {
	cout << "------------\n";
	for (size_t i = 1; i <= n; i++)
	{
		for (size_t j = 1; j <= m; j++)
		{
			if (v[i][j].deleted) {
				cout << "x" << " ";
			}
			else {
				cout << v[i][j].val << " ";
			}
		}
		cout << "\n";
	}
}

// 인접 판단 : 지워지는 경우 고려 필요
// 1. 행인접 판단 (N 동일)
// 2. 열인접 판단 (M 동일)
// 1번 케이스를 만족하면서 2번 케이스를 만족하는 경우 고려 필요 : set으로 해결
void connected(int spin) {
	// 1번 케이스 판단 
	for (int i = 1; i <= n; i++) {	
		for (int j = 1; j <= m; j++) {
			// 좌우 확인해서 인접 하면 set에 추가
			if (v[i][j].deleted == true) continue;

			int left, right;
			if (j == 1) {
				left = m;
			}
			else {
				left = j - 1;
			}

			if (j == m) {
				right = 1;
			}
			else {
				right = j + 1;
			}

			if (v[i][left].deleted == false && v[i][j].val == v[i][left].val) {
				connectedDot.insert({ i,j });
				connectedDot.insert({ i,left });
			}
			if (v[i][right].deleted == false && v[i][j].val == v[i][right].val) {
				connectedDot.insert({ i,j });
				connectedDot.insert({ i,right });
			}
		}
	}
	
	// 2번 케이스 판단
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[j][i].deleted == true || j == n) {
				continue;
			}
			int right = j + 1;
			if (v[right][i].deleted == false && v[j][i].val == v[right][i].val) {
				connectedDot.insert({ j,i });
				connectedDot.insert({ right,i });
			}
		}
	}
	
	// 인접 케이스 삭제 or 평균 연산
	int sum = 0;
	int cnt = 0;
	if (connectedDot.empty()) {
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (v[i][j].deleted == false) {
					cnt++;
					sum += v[i][j].val;
				}
			}
		}
		// 평균을 int로 계산하면 문제 생길 가능성 있음 
		double avg = (double)sum / cnt;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (v[i][j].deleted == false) {
					if (v[i][j].val > avg) {
						v[i][j].val -= 1;
					}
					else if(v[i][j].val < avg) {
						v[i][j].val += 1;

					}
				}
			}
		}
	}
	else {
		for (auto iter = connectedDot.begin(); iter != connectedDot.end(); iter++) {
			pair<int, int> tmp = *iter;
			v[tmp.first][tmp.second].deleted = true;
		}
		connectedDot.clear();
	}
}


void spin() {
	// x,d,k : x의 배수 row들 k칸 회전 d:0 시계, d:1 반시계
	for (int spin = 1; spin <= t; spin++) {
		cin >> x >> d >> k;

		for (int i = x ; i <= n; i += x) {

			vector<vector<dot>> v2(n + 1, vector<dot>(m + 1));

			for (int j = 1; j <= m; j++) {
				int nextCol;
				if (d == 0) {
					if (j + k > m) {
						nextCol = j + k - m;
					}
					else {
						nextCol = j + k;
					}
				}
				else {
					if (j - k < 1) {
						nextCol = j - k + m;
					}
					else {
						nextCol = j - k;
					}
				}
				v2[i][nextCol] = v[i][j];
			}

			for (int j = 1; j <= m; j++) {
				v[i][j] = v2[i][j];
			}
		}
		connected(spin);
	}
	
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (v[i][j].deleted == false) {
				sum += v[i][j].val;
			}
		}
	}

	cout << sum;
}

int main(){
	cin >> n >> m >> t;
	v.assign(n + 1, vector<dot>(m + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dot tmp;
			cin >> tmp.val;
			v[i][j] = tmp;
		}
	}

	spin();

	return 0;
}