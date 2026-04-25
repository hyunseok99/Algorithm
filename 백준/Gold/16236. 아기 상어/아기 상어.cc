#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

// cnt = 먹은 물고기 수, res : 시간 결과 
int n, cnt, res;

int shark = 2;

// 상 하 좌 우
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int arr[21][21];

struct comp {
	bool operator()(const pair<pair<int,int>, int> &a, const pair<pair<int,int> ,int> &b) {
		if (a.first.first == b.first.first) { return a.first.second > b.first.second; }
		else return a.first.first > b.first.first;
	}
};

// 상어 위치를 기준으로 돌고 -> bfs로 한바꾸 돌고 먹을 수 있으면 먹고 다시 
// 시간도 필요
// 먹고 나서 상어 위치 리턴 하고 이전 위치와 동일하면 끝,
pair<int, int> bfs(int x, int y) {
	// flag
	int flag[21][21] = { 0, };

	// x,y, time
	priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>> ,comp> eat;
	queue<pair<pair<int, int>, int>> q;
	queue<pair<pair<int, int>, int>> q2;

	q.push({{ x,y },0});
	while (1) {
		// 먹을 수 있는 물고기 있으면 정답에 시간 더하고 pos return 
		while (!q.empty()) {
			pair<int, int> tmp = q.front().first;
			int time = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = tmp.first + dx[i];
				int ny = tmp.second + dy[i];
				if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
					// 못먹는 사이즈면 못지나감
					if (flag[nx][ny] != 0) continue;
					else {
						if (arr[nx][ny] > shark) {
							continue;
						}
						else {
							flag[nx][ny] = 1;
							if (arr[nx][ny] != 0 && arr[nx][ny] < shark) {
								eat.push({ { nx, ny }, time + 1 });
							}
							q2.push({ { nx, ny }, time + 1 });
						}
					}
				}
			}
		}

		while (!eat.empty()) {
			cnt += 1;
			pair<int, int> pos = eat.top().first;
			arr[pos.first][pos.second] = 0;
			res += eat.top().second;
			if (cnt == shark) {
				cnt = 0;
				shark += 1;
			}

			return pos;
		}

		// 먹을 상어가 모든 구간에 존재 하지 않을 때 현재 위치 그대로 리턴 
		if (q2.empty()) return { x,y };

		// 먹을 수 있는 물고기 없으면 bfs 계속 수행
		while (!q2.empty()) {
			q.push(q2.front());
			q2.pop();
		}
	}
	
}
int main() {
	int x, y;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			arr[i][j] = t;
			if (t == 9) {
				x = i;
				y = j;
				// 최초 상어 위치는 이동 가능하고 빈 공간임
				arr[i][j] = 0;
			}	
		}
	}

	while (1) {

		pair<int, int> pos = bfs(x, y);
		if (x == pos.first && y == pos.second) {
			cout << res;
			return 0;
		}
		x = pos.first;
		y = pos.second;
	}

	return 0;
}