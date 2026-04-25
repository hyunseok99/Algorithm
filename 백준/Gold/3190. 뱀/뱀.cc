#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <string>
#include <unordered_set>
#include <numeric>
#include <climits>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
using namespace std;

int n, k, l, c,len, res = 0;
unordered_map<int, int> my_hash;
vector<pair<int,char>> v_dir;
bool apple[101][101];
char change[10001];
							// ->    아래   <-     위
pair<int, int> now_dir[4] = { {0,1},{1,0},{0,-1},{-1,0} };
priority_queue<int, vector<int>, greater<int>> pq;
deque<pair<int, int>> dq;

int forward(int idx, int ack) {
	if(change[ack]=='D'){
		idx++;
		if (idx == 4) idx = 0;
	}
	else {
		idx--;
		if (idx == -1) idx = 3;
	}
	return idx;
}

void fun(int dir, int ack) {
	deque<pair<int, int>>::iterator iter;
	pair<int, int> tail = dq.front();
	pair<int, int> head = dq.back();
	int nx = head.first + now_dir[dir].first;
	int ny = head.second + now_dir[dir].second;
	for (iter = dq.begin(); iter != dq.end(); iter++) {
		if (nx < 1 || ny < 1 || nx > n || ny > n || (iter->first == nx && iter->second == ny)) {
			cout << ack;
			return;
		}
	}
	dq.push_back({ nx,ny });
	if (!apple[nx][ny]) {
		dq.pop_front();
	}
	else {
		apple[nx][ny] = false;
	}

	if (change[ack] != 0) {
		dir = forward(dir, ack);
	}
	fun(dir, ack + 1);
	return;
}

int main() {

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		apple[x][y] = true;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int t;
		char dir;
		cin >> t >> dir;
		change[t] = dir;
	}
	dq.push_back({1,1});
	fun(0, 1);

	return 0;
}
