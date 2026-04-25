#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n,cnt;
int arr[101][101];
int check[101][101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;
priority_queue<int> vqvq;

void fun(int x,int y, int leev) {
	q.push(make_pair(x,y));
	check[x][y] = 1;
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int newX = temp.first + dy[dir];
			int newY = temp.second + dx[dir];
			if (newX < 0 || newY < 0 || newX >= n || newY >= n) continue;
			if (arr[newX][newY] > leev && check[newX][newY]==0) {
				q.push(make_pair(newX, newY));
				check[newX][newY] = 1;
	
			}
		}
	}
}

void fill() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = 0;
		}
	}
	cnt = 0;
}

int main() {
	cin >> n;
	int height = 0;
	int minh = 200;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > height) {
				height = arr[i][j];
			}
		}
	}

	while (height >= 0) {
		
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (arr[j][k] > height && check[j][k] == 0) {
						fun(j, k, height);
						cnt++;
					}
				}
			}
			vqvq.push(cnt);
			fill(); 
			height--;
	}
	if (minh == height) {
		cout << 1;
	}
	else {
		cout << vqvq.top();
	}
	return 0;
}