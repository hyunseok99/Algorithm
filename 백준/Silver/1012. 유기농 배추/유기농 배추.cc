#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int t;
int m, n, k;
int res;
int arr[51][51];
bool check[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void fun(queue<pair<int,int>> s) {
	queue<pair<int, int>> q;
	q.push(s.front());

	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int newX = temp.first + dx[dir];
			int newY = temp.second + dy[dir];
			if (newX >= 0 && newY >= 0 && newX<n && newY<m) {
				if (arr[newX][newY] == 1 && check[newX][newY] == false) {
					q.push(make_pair(newX, newY));
					check[newX][newY] = true;
				}
			}
		}

	}
	res++;
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> m >> n >> k;
		queue<pair<int, int>> s;
		for (int j = 0; j < k; j++) {
			int a, b;
			cin >> a >> b;
			arr[b][a] = 1;
			s.push(make_pair(b, a));
		}
		while (!s.empty()) {
			if (check[s.front().first][s.front().second] == false) {
				fun(s);
			}
			s.pop();
		}
		if (k == m * n) { res = 1; }
		cout << res << "\n";
		res = 0;
		fill(&arr[0][0], &arr[49][50], 0);
		fill(&check[0][0], &check[49][50], false);
	}
	return 0;
}
