#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
using namespace std;


int n, m, cnt, call;
char arr[101][101];
int flag[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

queue<pair<int, int>> cQ;
queue<pair<int, int>> box;

void fun() {
	while (!cQ.empty()) {
		pair<int, int> temp = cQ.front();
		cQ.pop();
		for (int i = temp.second; i < m; i++) {
			int ny = i + dy[1];
			if (ny < m) {
				cnt++;
				if (flag[temp.first][ny] == -1) {
					flag[temp.first][ny] = cnt;
				}
				if (flag[temp.first][ny] != -1 && flag[temp.first][ny] > cnt) {
					flag[temp.first][ny] = cnt;
				}
			}
		}
		cnt = 0;
	}
}

int main() {
	cin >> n >> m;
	fill(&flag[0][0], &flag[100][101], -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'c') {
				cQ.push(make_pair(i, j));
				flag[i][j] = 0;
			}
		}
	}
	fun();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << flag[i][j] << " ";
		}
		cout << "\n";
	}

	
}