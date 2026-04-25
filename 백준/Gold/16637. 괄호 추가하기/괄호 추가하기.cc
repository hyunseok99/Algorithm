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



int n, m, l,maxT, cnt2, cnt1 = 6, res = -2147483648;
string s;

int fun2(int, int, char);

void fun(int index, int cal) {
	if (index > n - 1) {
		res = max(res, cal);
		return;
	}
	
	char emo;
	if (index == 0) {
		emo = '+';
	}
	else {
		emo = s[index - 1];
	}

	if (index + 2 < n) {
		int temp = fun2(s[index] - '0', s[index + 2] - '0', s[index + 1]);
		fun(index + 4, fun2(cal,temp,emo));
	}
	fun(index + 2, fun2(cal, s[index]-'0',emo));
}

int fun2(int x, int y, char mul) {
	int temp = x;
	if (mul == '*') {
		return temp * y;
	}
	else if (mul == '-') {
		return temp - y;
	}
	else if (mul == '+') {
		return temp + y;
	}
	return temp;
}
int main() {

	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	int temp;
	int result = 0;
	cin >> n >> s;
	fun(0, 0);
	cout << res;

	return 0;
}