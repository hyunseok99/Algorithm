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

struct enemy {
	pair<pair<int, int>, int> info;
};

struct cmp {
	bool operator()(enemy a, enemy b) {
		if (a.info.second == b.info.second) {
			return a.info.first.second > b.info.first.second;
		}
		else {
			return a.info.second > b.info.second;
		}
	}
};

struct defend {
	pair<int, int> pos;
	priority_queue<enemy, vector<enemy>, cmp> enemys; // enemy : dist
};



int n, m, d;
int res = 0;

int defend_y[3] = { 0, };

vector<pair<int, int>> enemy_pos;
bool check(pair<int, int> pos_tmp, vector<pair<int, int>> pos, int tmp_turn);
// 궁수가 공격하는 적은 거리가 D이하인 적 중에서 가장 가까운 적이고
// 그러한 적이 여럿일 경우에는 가장 왼쪽에 있는 적을 공격한다. 같은 적이 여러 궁수에게 공격당할 수 있다

void dis(defend *tmp) {
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < enemy_pos.size(); i++) {
			int dist = abs(tmp[j].pos.first - enemy_pos[i].first) + abs(tmp[j].pos.second - enemy_pos[i].second);
			enemy tmp_enemy = { {enemy_pos[i], dist } };
			tmp[j].enemys.push(tmp_enemy);
		}
	}
}

// return: 처치 유닛 수 
int kill(defend *boy) {
	int killed = 0;
	int turn[3] = { 1, 1, 1 };
	vector<pair<int, int>> pos;
	vector<pair<int, int>> kill_pos;
	defend copy_b[3];
	copy_b[0] = boy[0];
	copy_b[1] = boy[1];
	copy_b[2] = boy[2];

	// 최대 턴 n
	for (int i = 1; i <= n; i++) {
		int tmp_turn = i;
		if (copy_b[0].enemys.empty() && copy_b[1].enemys.empty() && copy_b[2].enemys.empty()) break;
		for (int j = 0; j < 3; j++) {
			if (copy_b[j].enemys.empty()) continue;
			pair<int, int> pos_tmp = copy_b[j].enemys.top().info.first;
				
			// 적이 성에 도착한 경우 && 해당 턴 전에 죽은 적인 경우
			while(check(pos_tmp, pos, tmp_turn)) {
				if (copy_b[j].enemys.empty()) {
					turn[j]++;
					break;
				}
				copy_b[j].enemys.pop();
				if (!copy_b[j].enemys.empty()) {
					pos_tmp = copy_b[j].enemys.top().info.first;
					continue;
				}
			}
		
			if (tmp_turn != turn[j]) continue;

			// 해당 턴에 kill case
			for (int k = 0; k < kill_pos.size(); k++) {
				if (kill_pos[k].first == pos_tmp.first && kill_pos[k].second == pos_tmp.second) {
					copy_b[j].enemys.pop();
					turn[j]++;
					break;
				}
			}
			


			// kill
			if (turn[j] == tmp_turn && (copy_b[j].enemys.top().info.second - tmp_turn + 1) <= d) {
				kill_pos.push_back(pos_tmp);
				killed++;
				copy_b[j].enemys.pop();
			}

			// 이동 & pos 갱신
			if (turn[j] == tmp_turn) turn[j]++;
			if (j >= 2) {
				for (int s = 0; s < kill_pos.size(); s++) {
					pos.push_back(kill_pos[s]);
				}
				kill_pos.clear();
			}

		}
	}
	return killed;

}

// combination 구해서 처치 수 계산 함수 호출
void putCase(int idx = 0, int next = 0) {
	//  m combination 3   ex) m=4  -> 012 013 023 123
	if (idx == 3) {
		// distance calc
		defend def[3];
		def[0].pos = { n, defend_y[0]};
		def[1].pos = { n, defend_y[1]}; 
		def[2].pos = { n, defend_y[2]}; 
		//cout << defend_y[0] << defend_y[1] << defend_y[2] << "\n";
		dis(def);
		int kill_return = kill(def);
		//if (def[0].pos.second == 0 && def[1].pos.second == 2 && def[2].pos.second == 4) {
		//	kill_return = kill(def);
		//}
		res = (res < kill_return) ? kill_return : res;
		return;
	}

	for (int i = next; i < m ; i++) {
		defend_y[idx] = i;
		putCase(idx+1, i+1);
	}

}

bool check(pair<int, int> pos_tmp, vector<pair<int, int>> pos, int tmp_turn ) {
	// 적이 성에 도착한 경우 return true
	if (pos_tmp.first + tmp_turn - 1 >= n) return true;
	// 해당 턴 전에 죽은 적 return true
	for (int i = 0; i < pos.size(); i++) {
		if (pos[i].first == pos_tmp.first && pos[i].second == pos_tmp.second) {
			return true;
		}
	}
	return false;
}






int main() {
	// N * M ,  pos.x = n+1 -> fin 
	cin >> n >> m >> d;
	for(int i=0; i<n; i++){
		for (int j = 0; j < m; j++) {
			int state;
			cin >> state;
			if (state == 1) {
				enemy_pos.push_back({ i,j });
			}
		}
	}
	putCase(0, 0);

	cout << res;

	return 0;
}