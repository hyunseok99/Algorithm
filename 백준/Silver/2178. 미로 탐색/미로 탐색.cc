#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int n, m;

map<int, int> myMap;
map<int, bool> check;
map<int, int > myLen;
queue<int> q;

void fun(int x) {
	int dx[4] = { 1,-1,m,-m };
	q.push(x);
	check[x] = true;
	myLen[x] = 1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int xDir = temp + dx[dir];
			if ((xDir % m == 0 && dx[dir] == 1) || (xDir % m == m - 1 && dx[dir] == -1) ) continue;
			else if (0 <= xDir && xDir <m*n ) {
				if (check[xDir] == false && myMap[xDir] == 1) {
					q.push(xDir);
					myLen[xDir] = myLen[temp]+1;
					check[xDir] = true;
				}
			}
		}
	}
	
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {

			myMap.insert(make_pair(m * i + j, str[j] - '0'));
			check.insert(make_pair(m * i + j, false));
			myLen.insert(make_pair(m * i + j, 0));
		}
	}
	fun(0);
	cout << myLen[m*n-1];
	return 0;
}

