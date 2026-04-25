#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
using namespace std;


int n, m, cnt, call;
int arr[1001][1001];
bool flag[1001][1001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<pair<int, int>> cQ;
queue<pair<int, int>> box;

void check(int, int);

void fun() {
	queue<pair<int, int>> q;
	while (!cQ.empty()) {
		q.push(cQ.front());
		cQ.pop();
		
	}

	while (!q.empty()) {
		pair<int, int> temp = q.front();
		box.push(q.front());
		q.pop();
		check(temp.first, temp.second);
	}

	while (!box.empty()) {
		pair<int, int> temp = box.front();
		box.pop();
		for (int i = 0; i < 4; i++) {
			int nx = temp.first + dx[i];
			int ny = temp.second + dy[i];
			if(nx >= 0 && ny >= 0 && nx < n&& ny < m) {
				if ((arr[nx][ny] == 1 || arr[nx][ny] == 2) && flag[nx][ny]==false) {
					cQ.push(make_pair(nx, ny));
				}
				flag[nx][ny] = true;
			}
		}
	}
	if (!cQ.empty()) {
		fun();
	}
	return;
}

void check(int x, int y) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
			if (arr[nx][ny] == 0 && flag[nx][ny] == false) {
				arr[nx][ny] = arr[x][y];
			}
			if ((arr[x][y] == 2 && arr[nx][ny] == 1) && flag[nx][ny] == false) {
				arr[nx][ny] = 3;
			}
			if ((arr[x][y] == 1 && arr[nx][ny] == 2) && flag[nx][ny] == false) {
				arr[nx][ny] = 3;
			}
		}
	}
}	

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				flag[i][j] = true;

			}
			if (arr[i][j] == 2) {
				flag[i][j] = true;

			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((arr[i][j] == 1 || arr[i][j] == 2) && flag[i][j] == true) {
				cQ.push(make_pair(i,j));
			}
		}
	}
	fun();

	int A = 0, B = 0, C = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) A++;
			if (arr[i][j] == 2) B++;
			if (arr[i][j] == 3) C++;
		}
	}
	cout << A << " " << B << " " << C;
	return 0;
}