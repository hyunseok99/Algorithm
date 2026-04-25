#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
using namespace std;


int n, m, cnt, call;
int arr[100][100];
bool flag[100][100];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<pair<int, int>> cQ;

void fun() {
	queue<pair<int, int>> q;
	while (!cQ.empty()) {
		q.push(cQ.front());
		flag[cQ.front().first][cQ.front().second] = true;
		cQ.pop();
	}

	while(!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = temp.first + dx[dir];
			int ny = temp.second + dy[dir];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (arr[nx][ny]==0 && flag[nx][ny] == false) {
					flag[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
				else if (arr[nx][ny] == 1 && flag[nx][ny] == false) {
					flag[nx][ny] = true;
					arr[nx][ny] = 0;
					cQ.push(make_pair(nx, ny));
				}
			}
		}
	}
	call++;
}


int main() {
	cin >> n >> m;	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) cnt++;
		}
	}

	cQ.push(make_pair(0, 0));

	while (1) {
		fun();
		cnt -= cQ.size();
		if (cnt==0) {
			cout << call << "\n" << cQ.size();
			return 0;
		}
		
	}
}