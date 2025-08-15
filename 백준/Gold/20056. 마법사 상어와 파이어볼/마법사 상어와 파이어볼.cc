#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

// 전역 변수들
int n, m, k;

struct ball {
	int m, s, d;
};

// 상 우상 우 우하 하 좌하 좌 좌상
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

// sum -> divide action
void action(vector<vector<vector<ball>>> & v, vector<vector<vector<ball>>>& newV) {
	// 2개이상을 합친 후 다시 4개로 분열된 상태 
	vector<vector<vector<ball>>> newV2(n + 1, vector<vector<ball>>(n + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (newV[i][j].size() >= 2) {
				int sumOfWeight = 0;
				int sumOfVelocity = 0;
				int oddCnt = 0;
				int noddCnt = 0;
				int cnt = 0;
				int dir[4] = { 1,3,5,7 };
				for (int s = 0; s < newV[i][j].size(); s++) {
					cnt++;
					sumOfWeight += newV[i][j][s].m;
					sumOfVelocity += newV[i][j][s].s;
					if ((newV[i][j][s].d % 2) == 0) {
						noddCnt++;
					}
					else {
						oddCnt++;
					}
				}
				// 2개 이상인 경우 합치고 나누는 과정 수행 
				if (oddCnt == 0 || noddCnt == 0) {
					// dir = 0,2,4,6
					dir[0] = 0;
					dir[1] = 2;
					dir[2] = 4;
					dir[3] = 6;
				}
		

				// 소멸 여부
				if (sumOfWeight / 5 == 0) {
					continue;
				}
				else {
					ball tmp;
					tmp.m = sumOfWeight / 5;
					tmp.s = sumOfVelocity / cnt;
					for (int d = 0; d < 4; d++) {
						tmp.d = dir[d];
						newV2[i][j].push_back(tmp);
					}
				}
			}
			else if(newV[i][j].size() == 1) {
				newV2[i][j].push_back(newV[i][j][0]);
			}
		}
	}
	v = newV2;
}

// fireball move
void move(vector<vector<vector<ball>>>& v) {
	vector<vector<vector<ball>>> newV(n + 1, vector<vector<ball>>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[i][j].size() >= 1) {
				// if 없이 가능한지 체크 
				for (int s = 0; s < v[i][j].size(); s++) {
					int ny = i + v[i][j][s].s * dy[v[i][j][s].d];
					int nx = j + v[i][j][s].s * dx[v[i][j][s].d];
					if (ny >= n) { 
						if (ny % n == 0) {
							ny = n;
						}
						else {
							ny = ny % n;
						}
					}
					else if (ny <= 0) {
						if (ny == 0) {
							ny = n;
						}
						else {
							ny = n - (abs(ny) % n);
						}
					}
					if (nx >= n) { 
						if (nx % n == 0) {
							nx = n;
						}
						else {
							nx = nx % n;
						}
					}
					else if (nx <= 0) {
						if (nx == 0) {
							nx = n;
						}
						else {
							nx = n - (abs(nx) % n);
						}
					}
					newV[ny][nx].push_back(v[i][j][s]);
				}
			}
		}
	}

	// 2개 이상의 파이어볼 작업 수행
	action(v, newV);
}

int getWeight(vector<vector<vector<ball>>> &v) {
	int weight = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[i][j].size() >= 1) {
				// if 없이 가능한지 체크 
				for (int s = 0; s < v[i][j].size(); s++) {
					weight += v[i][j][s].m;
				}
			}
		}
	}
	return weight;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;

	vector<vector<vector<ball>>> v(n + 1, vector<vector<ball>>(n + 1));

	for (int i = 0; i < m; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		ball tmp = { m,s,d };
		v[r][c].push_back(tmp);
	}

	for (int i = 0; i < k; i++) {
		move(v);
	}

	cout << getWeight(v);
	return 0;
}