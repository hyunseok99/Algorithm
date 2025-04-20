#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <set>
#include <map>
#include <numeric>
using namespace std;

int n;
int res=0;
string ball;

void fun() {
	vector<int> v;
	int strick = 0;
	char color = ball[0];
	for (int i = 0; i < ball.size(); i++) {
		if (ball[i] == color) {
			strick += 1;
		}
		else {
			v.push_back(strick);
			color = ball[i];
			strick = 1;
		}
	}

	// 정답 연산
	int first = 0;
	int second = 0;
	for (int i = 0; i < v.size(); i++) {
		if ((i % 2) == 0) {
			first += v[i];
		}
		else {
			second += v[i];
		}
	}
	if (v.size() % 2 == 0) {
		second - v[v.size() - 1];
	}
	else {
		first - v[v.size() - 1];
	}


	res = min(first, second);
}

int main() {
	cin >> n >> ball;
	fun();
	cout << res;
	return 0;
}