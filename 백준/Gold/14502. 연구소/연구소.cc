#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
using namespace std;


int n, m, cnt;
int arrs[8][8];
bool check[8][8];
bool check2[8][8];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<int> v;
queue<pair<int, int>> q;


void fun(int x, int y, int arr[][8]) {
	q.push(make_pair(x, y));
	check[x][y] = true;
	
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = temp.first + dx[i];
			int ny = temp.second + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (arr[nx][ny] == 0 && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return;
}

void comb(int arr[][8], int start) {
	if (cnt == 3) {
		fill(&check[0][0], &check[7][8], false);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 2 && check[i][j] == false) {
					fun(i, j, arr);
				}
			}
		}
		int area = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0 && check[i][j] == false) area++;
			}
		}
		v.push_back(area);
	}
	else {
		for (int i = start ; i < n*m; i++) {
			int x = i / m;
			int y = (i % m);

			if (arr[x][y] == 0) {
				cnt++;
				arr[x][y] = 1;
				comb(arr, i + 1);
				arr[x][y] = 0;
				cnt--;
			}
		}
	}
	
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arrs[i][j];
		}
	}

	int temp[8][8];
	copy(&arrs[0][0], &arrs[0][0] + 64, &temp[0][0]);
	comb(temp, 0);
	sort(v.begin(), v.end());
	cout << v.back();

}