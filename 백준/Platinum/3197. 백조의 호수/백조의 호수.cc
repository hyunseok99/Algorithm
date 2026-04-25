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
using namespace std;

int n,m,cnt;
pair<int, int> pos[2];
int arr[1501][1501] = { -1, };
bool flag[1501][1501];
bool posit[1501][1501];
bool check= false;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue<pair<int, int>> q;
queue<pair<int, int>> q2;
queue<pair<int, int>> p;
queue<pair<int, int>> p2;

void move() {
	while (!p.empty() && check == false) {
		pair<int, int> temp = p.front();
		p.pop();
		posit[temp.first][temp.second] = true;
		for (int i = 0; i < 4; i++) {
			int nx = temp.first + dx[i];
			int ny = temp.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (posit[nx][ny] == false) {
				if ( arr[nx][ny] == 0) {
					posit[nx][ny] = true;
					p.push({ nx,ny });
				}
				else if (arr[nx][ny]==-2) {
					posit[nx][ny] = true;
					check = true;
					break;
				}
				else if (arr[nx][ny] == -1) {
					posit[nx][ny] = true;
					p2.push({ nx,ny });
				}
			}
			
		}
	}
	return ;
}


void fun() {
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		flag[temp.first][temp.second] = true;
		for (int i = 0; i < 4; i++) {
			int nx = temp.first + dx[i];
			int ny = temp.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if ( arr[nx][ny] == -1 ) {
				arr[nx][ny] = 0;
				q2.push({ nx,ny });
			}
		}
	}
	return;
}

int main() {
	cin.tie(0); cin.sync_with_stdio(0);

	cin >> n >> m;
	int t = 0;
	char ch;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ch;
			if (ch == '.') {
				arr[i][j] = 0;
				q.push({ i,j });
			}
			else if (ch == 'L') {
				pos[t] = { i, j };
				t++;
				arr[i][j] = -2;
				q.push({ i,j });
			}
			else {
				arr[i][j] = -1;
			}
		}
	}
	p.push(pos[0]);

	while (!check) {
		move();
		if (!check) {
			fun();
			q = q2;
			p = p2;
			while (!q2.empty()) {
				q2.pop();
			}
			while (!p2.empty()) {
				p2.pop();
			}
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
