#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <math.h>
using namespace std;
//17071
// t가 지남에 따라 동생은 고정된 위치 k + t*(t+1)/2, 수빈은 3개중 택1 -> 3^t 개의 위치 가능 -> 매 이동 후 3번 모두 비교하기에는 시간초과
// 결과 자체는 정해진 규칙으로 증가하는 동생을 기준으로 ㄱㄱ
// 만약 수빈의 위치를 전부 구하려고 하면 20초만 지나도 3^20 ~= 30억 시간초과
// 수빈의 특정 위치에 도착했을 때 시간을 이용해야 할듯, 이미 수빈이가 한번 간 곳은 뭔가 의미가 있을 것 같음 
// 존재 가능한 경우의 수
// 1. 동일 위치에서 만나는 경우
// 2. 동생이 수빈이 지나갔던 곳에 도착한 경우 -> +1, -1 즉 2초를 계속 반복해서 수빈은 해당 위치 존재 가능 
// 짝수시간대에 동생이 도착 , 이전에 짝수 시간대에 수빈 도착이면 동생 도착 시간에 만나기 가능 
// 홀수시간대에 동생 도착, 이전에 홀수 시간대에 수빈 도착이면 동생 도착 시간에 만나기 가능
// -> 여기까지만 생각해서 했다가 틀림
// -> 특정 시간대에만 방문으로 문제 풀고 이미 도착한곳은 고려 안했었는데
// -> 특정 위치에 짝수시간대에 존재하고, 홀수시간대에도 존재할 수가 있음 ㅋㅋ 결론은 짝,홀 모두 가능한 경우도 고려해야함
// -> ex) 1 -> 2 -> 4 -> 3 -> 2 -> 1 : 1위치에 5초에 존재 가능
//        1 -> 2 -> 3 -> 2 -> 1      : 1위치에 4초에 존재 가능 즉 위치 1은 짝수,홀수 시간대에 모두 가능

int n, k;
unordered_map<int, pair<int, int>> pos; // 수빈의 위치에 따른 시간  <위치, <짝수 시간 방문 , 홀수 시간 방문 >>
queue<int> q; // 수빈 이동 가능 위치

bool check(int bro, int time) {
	if (pos.count(bro) > 0) {
		if (time % 2 == 0) {
			// 1. 동일 위치에서 동시에 만나는 경우
			if (pos[bro].first == time) {
				return true;
			}
			// 2. 동일 위치에 이전에 수빈이 짝수 시간대에 지나갔던 경우
			else if (pos[bro].first >= 0) {
				return true;
			}
		}
		else {
			// 1. 동일 위치에서 동시에 만나는 경우
			if (pos[bro].second == time) {
				return true;
			}
			// 2. 동일 위치에 이전에 수빈이 홀수 시간대에 지나갔던 경우
			else if (pos[bro].second >= 0) {
				return true;
			}
		}
	}
	return false;
}

// 수빈 방문 여부 갱신
void pos_update(int time) {
	queue<int> tmp;
	while (!q.empty()) {
		int val = q.front();
		q.pop();
		if (val -1 >= 0) {
			// 만약 새로운 이동 장소가 이미 수빈이가 방문한 곳이라면 스킵
			if (time%2 == 0) {
				if (pos.count(val - 1) == 0) {
					tmp.push(val - 1);
					pos[val - 1] = { time, -1};
				}
				else {
					pair<int, int> map_val = pos[val - 1];
					if (map_val.first < 0 ) {
						map_val.first = time;
						tmp.push(val - 1);
						pos[val - 1] = map_val;
					}
				}
			}
			else {
				if (pos.count(val - 1) == 0) {
					tmp.push(val - 1);
					pos[val - 1] = { -1, time};
				}
				else {
					pair<int, int> map_val = pos[val - 1];
					if (map_val.second < 0) {
						map_val.second = time;
						tmp.push(val - 1);
						pos[val - 1] = map_val;
					}
				}
			}
		}
		if (val + 1 <= 500000) {
			if (time % 2 == 0) {
				if (pos.count(val + 1) == 0) {
					tmp.push(val + 1);
					pos[val + 1] = { time, -1};
				}
				else {
					pair<int, int> map_val = pos[val + 1];
					if (map_val.first < 0) {
						map_val.first = time;
						tmp.push(val + 1);
						pos[val + 1] = map_val;
					}
				}
			}
			else {
				if (pos.count(val + 1) == 0) {
					tmp.push(val + 1);
					pos[val + 1] = { -1, time};
				}
				else {
					pair<int, int> map_val = pos[val + 1];
					if (map_val.second < 0) {
						map_val.second = time;
						tmp.push(val + 1);
						pos[val + 1] = map_val;
					}
				}
			}

		}
		if (val * 2 <= 500000) {
			if (time % 2 == 0) {
				if (pos.count(val * 2) == 0) {
					tmp.push(val * 2);
					pos[val * 2] = { time, -1};
				}
				else {
					pair<int, int> map_val = pos[val * 2];
					if (map_val.first < 0) {
						map_val.first = time;
						tmp.push(val * 2);
						pos[val * 2] = map_val;
					}
				}
			}
			else {
				if (pos.count(val * 2) == 0) {
					tmp.push(val * 2);
					pos[val * 2] = { -1, time};
				}
				else {
					pair<int, int> map_val = pos[val * 2];
					if (map_val.second < 0) {
						map_val.second = time;
						tmp.push(val * 2);
						pos[val * 2] = map_val;
					}
				}
			}
		}
	}
	q = tmp;
	return;
}

int main() {
	cin >> n >> k;

	int t = 1;
	int subin_pos = n;
	int bro_pos = k;

	pos[n] = { 0, -1};
	// 최초 수빈 위치 추가
	q.push(n);

	if (k == n) {
		cout << 0;
		return 0;
	}

	while (1) {
		bro_pos += t;
		if (bro_pos > 500000) {
			t = -1;
			break;
		}
		// 수빈 위치 갱신
		pos_update(t);

		// 찾은경우
		if (check(bro_pos, t)) break;

		t++;
	}

	cout << t;
	

	return 0;
}