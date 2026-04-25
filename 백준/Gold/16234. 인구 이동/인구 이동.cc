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


int n, m,l,r,cnt1,cnt2, res = -1;
int flag[51][51];
int arr[51][51];
int dx[4] = {1,0,-1,0};
int dy[4] = { 0,1,0,-1 };

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

void fun(int x, int y) {
	vector<pair<int, int>> v;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	v.push_back(make_pair(x, y));
	flag[x][y] = cnt1;
	int cnt = 1;
	int human = arr[x][y];

	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		flag[temp.first][temp.second] = true;
		for (int i = 0; i < 4; i++) {
			int nx = temp.first + dx[i];
			int ny = temp.second + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n && flag[nx][ny]==-1) {
				if( (l<=abs(arr[nx][ny]-arr[temp.first][temp.second])) && (abs(arr[nx][ny] - arr[temp.first][temp.second])<=r)){
					q.push(make_pair(nx,ny));
					v.push_back(make_pair(nx, ny));
					flag[nx][ny] = cnt1;
					human += arr[nx][ny];
					cnt++;
				}
			}
		}	
	}

	for (int i = 0; i < v.size(); i++) {
		arr[v[i].first][v[i].second] = human / cnt;
	}

	cnt1++;
	return;

}

int main() {

	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	while (1) {
		fill(&flag[0][0], &flag[50][51], -1);


		cnt1 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (flag[i][j] == -1) {
					fun(i, j);
				}
			}
		}
		if (cnt1 == n * n) break;
		cnt2 += 1;
	}

	cout << cnt2;
	return 0;
}