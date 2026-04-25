#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <stack>
using namespace std;

int n = 4;
int m;

struct fish {
	int y, x, dir;
};

// 45도 반시계 방향 이동 idx 2칸씩 증감 고려 필요 -> idx 감소 , 1보다 작아지면 다시 8로
// 좌 좌상 상 우상 우 우하 하 좌하 (idx 증가 -> 시계방향 )
int dy[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

// 상어 상 좌 하 우 : 1, 2, 3, 4
int sharkDy[5] = { 0, -1, 0, 1, 0 };
int sharkDx[5] = { 0, 0, -1, 0, 1 };

// 현재 방향으로 부터 모든 반시계를 방향 확인하고 물고기 이동 가능 여부 체크 함수 
void checkMove(pair<int, int> shark, vector<vector<vector<fish>>>& v, vector<vector<int>>& smell) {

	vector<vector<vector<fish>>> v2(n + 1, vector<vector<fish>>(n + 1));
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int s = 0; s < v[i][j].size(); s++) {
				fish f = v[i][j][s];

				int y = f.y;
				int x = f.x;

				int cnt = 8;
				int dir = f.dir;
				bool flag = false;
				while (cnt > 0) {
					if (flag) break;

					int ny = y + dy[dir];
					int nx = x + dx[dir];

					// 격자안 + 상어 위치 아닌경우 + 물고기 냄새 없는 경우
					if (nx >= 1 && nx <= 4 && ny >= 1 && ny <= 4 && !(ny == shark.first && nx == shark.second) && smell[ny][nx] == 0) {
						flag = true;
						f.y = ny;
						f.x = nx;
						f.dir = dir;
						v2[ny][nx].push_back(f);
					}
					cnt--;
					dir--;
					
					if (dir <= 0) {
						dir = 8;
					}
				}
				// 이동 불가 물고기 삽입
				if (flag == false) {
					v2[y][x].push_back(f);
				}

			}
		}
	}

	// 물고기 위치 갱신
	v = v2;
}

vector<fish> copyFish(vector<vector<vector<fish>>>& v) {
	// 복제되는 물고기들 
	vector<fish> tmp;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int s = 0; s < v[i][j].size(); s++) {
				tmp.push_back(v[i][j][s]);
			}
		}
	}
	return tmp;
}

void deleteSmell(vector<vector<int>>& smell, int time) {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (smell[i][j] != 0 && ((time - smell[i][j]) >= 2)) {
				smell[i][j] = 0;
			}
		}
	}
}

// 상어가 물고기 제일 많이 먹는 경우 
void eatFish(pair<int, int> shark, vector<vector<vector<fish>>>& v, vector<vector<int>> &flag, int move, int& eatCnt, vector<pair<int, int>>& pos, pair<int, int>& lastpos) {
	// 3번 이동 완료 
	if (move >= 3) {
		// 해당 위치로 상어 위치 리턴하고 사전순으로 제일 많이 먹은 경우의 위치들 리턴 
		int flagSize = 0;
		vector<pair<int, int>> eatPos;
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				if (flag[i][j] != 0) {
					for (int s = 0; s < v[i][j].size(); s++) {
						flagSize++;
					}
					eatPos.push_back({ i,j });
				}
			}

		}

		if (eatCnt < flagSize) {
			eatCnt = flagSize;
			pos = eatPos;
			lastpos = shark;
		}
		return;
	}

	int y = shark.first;
	int x = shark.second;

	// 먹었던 곳 다시 갈 수 있어서 이를 체크하기 위한 flag 필요 
	for (int dir = 1; dir <= 4; dir++) {
		int ny = y + sharkDy[dir];
		int nx = x + sharkDx[dir];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
			flag[ny][nx]++;
			eatFish({ ny, nx }, v, flag, move + 1, eatCnt, pos, lastpos);
			flag[ny][nx]--;
		}
	}

}

// 4*4*4 가지의 움직임을 모두 시도하고 최대로 물고기 잡는경우 확인, 3번 이동 실패하면 포기 
void moveShark(pair<int, int> &shark, vector<vector<vector<fish>>>& v, vector<vector<int>>& smell, int time) {
	// 복사할 물고기들
	vector<fish> forCopy = copyFish(v);

	// 모든 물고기 이동 
	checkMove(shark, v, smell);

	// 최대의 경우를 갖는 경우들을 가져오고
	int eatCnt = -1;
	pair<int, int> befShark = shark;
	vector<pair<int, int>> eatenFish;
	vector<vector<int>> flag(n + 1, vector<int>(n + 1, 0));
	eatFish(shark, v, flag, 0, eatCnt, eatenFish, befShark);
	shark = befShark;

	// 사전순 비교로 확정 이동 시키고 먹방 및 냄새 갱신
	for (int i = 0; i < eatenFish.size(); i++) {
		pair<int, int> pos = eatenFish[i];
		// 냄새 갱신
		while (!v[pos.first][pos.second].empty()) {
			v[pos.first][pos.second].pop_back();
			smell[pos.first][pos.second] = time;

		}
	}

	// 2턴 지난 물고기 냄새 제거 
	deleteSmell(smell, time);

	// 복제 완료
	for (int i = 0; i < forCopy.size(); i++) {
		fish f = forCopy[i];
		v[f.y][f.x].push_back(f);
	}

}

int getFishCnt(vector<vector<vector<fish>>>& v) {
	int cnt = 0;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			cnt += v[i][j].size();
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<vector<fish>>> v(n + 1, vector<vector<fish>>(n + 1));

	int s;
	// m = 물고기 수
	cin >> m >> s;
	for (int i = 0; i < m; i++) {
		fish tmp;
		cin >> tmp.y >> tmp.x >> tmp.dir;
		v[tmp.y][tmp.x].push_back(tmp);
	}

	pair<int, int> shark;
	cin >> shark.first >> shark.second;

	vector<vector<int>> smell(n + 1, vector<int>(n + 1));
	for (int time = 1; time <= s; time++) {
		moveShark(shark, v, smell, time);
	}
	// 격자의 물고기 수 
	cout << getFishCnt(v);
	return 0;
}