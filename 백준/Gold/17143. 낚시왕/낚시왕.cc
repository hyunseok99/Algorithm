#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
// direction 1위, 2아래, 3 오른 4 왼
struct shark{
	pair<int,int> pos;
	int speed, dir, s;
};
typedef struct shark Shark;
int R, C, M, res = 0;;

struct compare {
	bool operator()(Shark a, Shark b) {
		if (a.pos == b.pos) return a.s < b.s;
		return a.pos.first > b.pos.first;
	}
};

priority_queue<Shark, vector<Shark>, compare> v[101];
priority_queue<Shark, vector<Shark>, compare> v2[101];
vector<Shark> vv;
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

Shark move(Shark a) {

	if (a.dir == 1) {
		if ( a.pos.first - a.speed <= 1) {
			int turn_cnt = (a.speed - (a.pos.first -1)) / (R - 1);
			if (turn_cnt % 2 == 0) {
				a.dir = 2;
				a.pos.first = 1 + ((a.speed - (a.pos.first - 1)) % (R - 1));
			}
			else {
				a.pos.first = R - ((a.speed - (a.pos.first - 1)) % (R - 1));
			}
		}
		else {
			a.pos.first -= a.speed;
			if (a.pos.first == 1) a.dir = 2;
		}
		return a;
	}
	else if (a.dir == 2) {
		if (a.pos.first + a.speed >= R) {
			int turn_cnt = (a.speed - (R - a.pos.first)) / (R - 1);
			if (turn_cnt % 2 == 0) {
				a.dir = 1;
				a.pos.first = R - ((a.speed - (R - a.pos.first)) % (R - 1));
			}
			else {
				a.pos.first = 1 + ((a.speed - (R - a.pos.first)) % (R - 1));
			}
		}
		else {
			a.pos.first += a.speed;
			if (a.pos.first == R) a.dir = 1;
		}
		return a;
	}
	else if (a.dir == 3) {
		if (a.pos.second + a.speed >= C) {
			int turn_cnt = (a.speed - (C - a.pos.second)) / (C - 1);
			if (turn_cnt % 2 == 0) {
				a.dir = 4;
				a.pos.second = C - ((a.speed - (C - a.pos.second)) % (C - 1));
			}
			else {
				a.pos.second = 1 + ((a.speed - (C - a.pos.second)) % (C - 1));
			}
		}
		else {
			a.pos.second += a.speed;
			if (a.pos.second == C) a.dir = 4;
		}
		return a;
	}
	else {
		if (a.pos.second - a.speed <= 1) {
			int turn_cnt = (a.speed - (a.pos.second - 1)) / (C - 1);
			if (turn_cnt % 2 == 0) {
				a.dir = 3;
				a.pos.second = 1 + ((a.speed - (a.pos.second - 1)) % (C - 1));
			}
			else {
				a.pos.second = C - ((a.speed - (a.pos.second - 1)) % (C - 1));
			}
		}
		else {
			a.pos.second -= a.speed;
			if (a.pos.second == 1) a.dir = 3;
		}
		return a;
	}
}

int main() {
	cin >> R >> C >> M;
	// m  = 0 -> reuslt =  0
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		Shark temp = { {r,c},s,d,z };
		v[c].push(temp);
	}
	if (M == 0) { cout << 0; return 0; };
	for (int i = 1; i <= C; ++i) {
		// 1. 낚시 실행
		if (!v[i].empty()) {
			Shark temp = v[i].top();
			v[i].pop();
			res += temp.s;
		}

		// 2. 상어 이동
		for (int j = 1; j <= C; j++) {
			while (!v[j].empty()) {
				Shark temp2 = v[j].top();
				v[j].pop();
				temp2 = move(temp2);
				v2[temp2.pos.second].push(temp2);
			}
		}

		// 3. 동일 위치 상어 존재시 먹방
		for (int j = 1; j <= C; j++) {
			while (!v2[j].empty() && v2[j].size() >= 2) {
				Shark temp1 = v2[j].top(); v2[j].pop();
				Shark temp2 = v2[j].top();
				if (temp1.pos != temp2.pos) { v[j].push(temp1); }
				else {
					v2[j].pop();
					v2[j].push(temp1);
				}
			}
			if (!v2[j].empty()) { v[j].push(v2[j].top()); v2[j].pop(); }
		}
	}

	cout << res;
	return 0;
}