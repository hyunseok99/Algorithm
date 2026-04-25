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



int n, m, l, cnt2, cnt1 = 6, res = 1;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int flag[61][61][61];
int a[3];
int types[6][3] = {
	{
		9,3,1
	},
	{
		9,1,3
	},

	{   
		3,9,1
	},
	{
		3,1,9
	},
	{
		1,9,3
	},
	{
		1,3,9
	}
};

struct scv {
	int a, b, c;
};

void fun() {
	queue<scv> q;
	q.push({ a[0],a[1],a[2] });
	flag[a[0]][a[1]][a[2]] = 1;
	while (!q.empty()) {
		int x = q.front().a;
		int y = q.front().b;
		int z = q.front().c;
		q.pop();
		if (x == 0 && y == 0 && z == 0) {
			cout << flag[x][y][z]-1;
			return;
		}
		for (int i = 0; i < 6; i++) {
			int nx = max(0,x - types[i][0]);
			int ny = max(0,y - types[i][1]);
			int nz = max(0,z - types[i][2]);
			if (flag[nx][ny][nz] == 0 ){
				flag[nx][ny][nz] = flag[x][y][z] + 1;
				q.push({ nx,ny,nz });
			}
		}
	}
}

int main() {

	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < 6; i++) {
		if (a[0] <= types[i][0] && a[1] <= types[i][1] && a[2] <= types[i][2]) {
			cout << 1;
			return 0;
		}
	}
	fun();
	
	return 0;
}