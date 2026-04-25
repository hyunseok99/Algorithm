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



int n, m, mini;
bool flag[100001];
int path[100001];
vector<int> v;

struct pos {
	int x;
	int cnt;
};


// 홀수 -> +1 or -1 
// 짝수 /2 

void fun(int x, int y) {
	queue<pos> q;
	q.push({x,0});
	flag[x] = true;

	while (!q.empty()) {
		pos temp = q.front();
		q.pop();

		if (temp.x == y) {
			mini = temp.cnt;
			int back = temp.x;
			while (back != x) {
				v.push_back(back);
				back = path[back];
			}
			v.push_back(x);
			return;
		}

		if (temp.x + 1 <= 100000 && flag[temp.x + 1] == false) {
			flag[temp.x + 1] = true;
			path[temp.x + 1] = temp.x;
			q.push({ temp.x + 1,temp.cnt + 1});
		}

		if (temp.x - 1 >= 0 && flag[temp.x - 1] == false) {
			flag[temp.x - 1] = true;
			path[temp.x - 1] = temp.x;
			q.push({ temp.x - 1,temp.cnt + 1 });
		}

		if (temp.x * 2 <= 100000 && flag[temp.x * 2] == false) {
			flag[temp.x * 2] = true;
			path[temp.x * 2] = temp.x;
			q.push({ temp.x * 2,temp.cnt + 1 });

		}
		
	}

	return;
}

int main() {
	cin >> n >> m;
	fun(n, m);
	cout << mini << "\n";
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << " ";
	}
	return 0;
}