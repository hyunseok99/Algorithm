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


int n, m,cnt1,cnt2, res = 100000000;
bool flag[1001][1001];
bool flag2[1001][1001];
char arr[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> human;
queue<pair<int, int>> fire;

map<int,int> myM;
/*
void comb(int index, int start) {
	if (index == m) {
		distance();
	}

	for (int i = start; i < v.size(); i++) {
		if (!flag[v[i].first][v[i].second]) {
			flag[v[i].first][v[i].second] = true;
			comb(index+1, i + 1);
			flag[v[i].first][v[i].second] = false;

		}
	}
}
*/

void fun2();

bool fun1() {
	if (human.empty()) return true;
	int size = human.size();
	fun2();
	for (int i = 0; i < size; i++) {
		pair<int, int> temp = human.front();
		human.pop();
		flag[temp.first][temp.second] = true;
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = temp.first + dx[dir];
			int ny = temp.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (arr[nx][ny] == '.' && flag[nx][ny] == false) {
				flag[nx][ny] = true;
				human.push(make_pair(nx,ny));
				if (nx == 0 || ny == 0 || nx == n-1 || ny == m-1) {
					myM[cnt2] = cnt1;
					cnt2++;
				}
			}
		}
	}
	cnt1++;
	return false;
}

void fun2() {
	int size = fire.size();
	for (int i = 0; i < size; i++) {
		pair<int, int> temp = fire.front();
		fire.pop();
		flag[temp.first][temp.second] = true;

		for (int dir = 0; dir < 4; dir++) {
			int nx = temp.first + dx[dir];
			int ny = temp.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (arr[nx][ny] == '.' && flag[nx][ny] == false) {
				flag[nx][ny] = true;
				fire.push(make_pair(nx, ny));
			}
		}
	}
	return;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	char t;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> t;
			if (t == '#') {
				arr[i][j] = '#';
			}
			if (t == 'F') {
				fire.push(make_pair(i, j));
			}
			if (t == 'J') {
				human.push(make_pair(i, j));
			}
			if (t == '.') {
				arr[i][j] = '.';
			}
		}
	}
	int x = human.front().first;
	int y = human.front().second;
	if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
		cout << "1";
		return 0;
	}

	while (1) {
		bool check = fun1();
		if (check) break;
	}

	if (myM.size() == 0) {
		cout << "IMPOSSIBLE";
	}
	else {
		for (int i = 0; i < myM.size(); i++) {
			if (res > myM[i]) res = myM[i];
		}
		cout << res + 2;
	}
	return 0;
}