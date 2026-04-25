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



int n, m, mini, res;
bool flag[100001];

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
		flag[temp.x] = true;
		
		if (mini != 0) {
			if (temp.x == y && temp.cnt == mini) {
				res++;
			}
		}

		if (mini==0 && temp.x == y) {
			mini = temp.cnt;
			res++;
		}
		
		if (temp.x * 2 <= 100000 && flag[temp.x * 2] == false) {
			q.push({ temp.x * 2,temp.cnt + 1 });
		}
		if (temp.x + 1 <= 100000 && flag[temp.x + 1] == false) {
			q.push({ temp.x + 1,temp.cnt + 1 });
		}
		if (temp.x - 1 >=0 && flag[temp.x - 1] == false) {
			q.push({ temp.x - 1,temp.cnt + 1 });
		}
	}

	return;
}

int main() {
	cin >> n >> m;
	fun(n, m);
	cout << mini << "\n" << res;
}