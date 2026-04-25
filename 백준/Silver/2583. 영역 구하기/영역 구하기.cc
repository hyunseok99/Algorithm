#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;


int arr[101][101]; 
bool check[101][101];
int dx[4] = { 1,0 ,-1,0};
int dy[4] = { 0,1, 0, -1 };
int n, m, k;
int cnt;
queue<pair<int,int >> q;
vector<int> s;

void bfs(int x, int y) {
	int myS = 1;
	q.push(make_pair(x,y));
	check[x][y] = true;
	while (!q.empty()){
		pair<int, int> fron = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int a = fron.first + dx[dir];
			int b = fron.second + dy[dir];
			if (a < 0 || b < 0) continue;
			if (check[a][b] == false && arr[a][b] == 1) {
				q.push(make_pair(a, b));
				check[a][b] = true;
				myS++;
			}
		}
	}
	s.push_back(myS);
}

int main() {
	cin >> m >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = 1;
		}
	}
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int j = a; j < c; j++) {
			for (int l = b; l < d; l++) {
				arr[j][l] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == false && arr[i][j] == 1) {
				bfs(i,j);
				cnt++;
			}
		}
	}

	sort(s.begin(), s.end());
	cout << s.size() << "\n";
	for (auto k : s) {
		cout << k << " ";
	}

	
	return 0;
}

