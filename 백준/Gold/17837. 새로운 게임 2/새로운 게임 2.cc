#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
// n*n, 1~k
// W, R, B ->  0,1,2

// 우, 좌, 상 하
int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};

// 1. 흰색으로 이동 -> 이동 후 제일 위에 쌓임
// 2. 빨로 이동 -> 이동 후 새로 이동은 순서 역으로 ABC + DE -> DE + CBA
// 3. 파로 이동 or 맵밖으로 이동 -> 이동 방향 반대로 하고 한칸 이동
//						-> 만약 그 칸도 파랑 or 체스 밖이면 이동 x

// 최대 9번 pop , stack, queue 이용 

int n, k;
int res = -1;
bool flag = false;


stack<int> pos[13][13];

struct pawn {
	int y, x, dir;
};

int nextDir(int dir) {
	if (dir == 1) return 2;
	if (dir == 2) return 1;
	if (dir == 3) return 4;
	if (dir == 4) return 3;
}


// 실제로 이동이 발생하는 경우는 해당 밑 바닥이 W,R 인 경우만 이동 발생 
void action(int color, int cur, int ny,  int nx,  vector<pawn>& info) {
	int y = info[cur].y;
	int x = info[cur].x;
	// pos에 변동 생김 
	if (color == 0) {
		// 해당 말위에 다른 말 존재하는지 확인
		stack<int> tmp;
		while (!pos[y][x].empty()) {
			int num = pos[y][x].top();
			pos[y][x].pop();
			tmp.push(num);
			if (num == cur) {
				break;
			}
		}

		// tmp 순서대로 새로운 위치에 위치 정보 갱신 및 삽입
		// 위치 갱신
		while (!tmp.empty()) {
			int num = tmp.top();
			tmp.pop();
			info[num].y = ny;
			info[num].x = nx;
			pos[ny][nx].push(num);
		}

		if (pos[ny][nx].size() >= 4) {
			flag = true;
		}
	}else if (color == 1) {
		// 해당 말위에 다른 말 존재하는지 확인, 역순 배치하므로 큐 
		queue<int> tmp;
		while (!pos[y][x].empty()) {
			int num = pos[y][x].top();
			pos[y][x].pop();
			tmp.push(num);
			if (num == cur) {
				break;
			}
		}

		// tmp 순서대로새로운 위치에 위치 정보 갱신 및 삽입
		// 위치 갱신
		while (!tmp.empty()) {
			int num = tmp.front();
			tmp.pop();
			info[num].y = ny;
			info[num].x = nx;
			pos[ny][nx].push(num);
		}

		if (pos[ny][nx].size() >= 4) {
			flag = true;
		}
	}
}


void move(int cur, vector<pawn> &info, vector<vector<int>> &v) {
	int y = info[cur].y;
	int x = info[cur].x;
	int dir = info[cur].dir;
	// 이동하려는 곳
	int ny = y + dy[dir];
	int nx = x + dx[dir];

	//
	if (ny >= 1 && nx >= 1 && ny <= n && nx <= n) {
		// 이동하는 칸의 색 확인 후 이동 W,R,B
		if (v[ny][nx] != 2) {
			// W,R
			action(v[ny][nx], cur, ny, nx, info);
		}
		else {
			// 이동하려는 칸이 B
			int ndir = nextDir(dir);
			ny = y + dy[ndir];
			nx = x + dx[ndir];
			if (ny >= 1 && nx >= 1 && ny <= n && nx <= n) {
				if (v[ny][nx] != 2) {
					// W,R
					info[cur].dir = ndir;
					action(v[ny][nx], cur, ny, nx, info);
				}
				else {
					// 이동 x 방향만 반대 후 이동 x
					info[cur].dir = ndir;
				}
			}
			else {
				// 방향만 반대로고 위치는 그대로
				info[cur].dir = ndir;
			}
		}

	}else{
		// 이동 불가한 경우 
		// 방향 반대로 하고 이동 색깔도 확인
		int ndir = nextDir(dir);
		ny = y + dy[ndir];
		nx = x + dx[ndir];
		if (ny >= 1 && nx >= 1 && ny <= n && nx <= n) {
			if (v[ny][nx] != 2) {
				// W,R
				info[cur].dir = ndir;
				action(v[ny][nx], cur, ny, nx, info);

			}
			else {
				// 이동 x 방향만 반대
				info[cur].dir = ndir;
			}
		}
		else {
			// 방향만 반대로고 위치는 그대로
			info[cur].dir = ndir;
		}

	}


}

int main() {
	cin >> n >> k;
	vector<vector<int>> v(n+1, vector<int>(n+1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> v[i][j];
		}
	}

	vector<pawn> info(k + 1); // 1~k
	for (int i = 1; i <= k; i++) {
		pawn tmp;
		cin >> tmp.y >> tmp.x >> tmp.dir;
		info[i] = tmp;
		pos[tmp.y][tmp.x].push(i);
	}

	for (int turn = 1; turn <= 1000; turn++) {
		for (int i = 1; i <= k; i++) {
			move(i, info, v);
			if (flag) {
				break;
			}
		}

		if (flag) {
			res = turn;
			break;
		}
	}

	cout << res;

	return 0;
}