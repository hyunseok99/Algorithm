#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int n, m;
int xdir[2] = { 1,n };
map<int, int> myMap;
queue<pair<int, int>> q;

// lev/2 %2 !=0 -> function  
void fun(int xpos, int ypos, int lev, int **arr) {
	int cnt = 0;
	int res = 0;
	for (int i = xpos; i < xpos+lev; i++) {
		for (int j = ypos; j < ypos+lev; j++) {
			res += arr[i][j];
		}
	}
	if (res == lev*lev) {
		cout << "1";
		cnt++;
		return;
	}
	else if (res == 0) {
		cout << "0";
		cnt++;
		return;
	}
	else {
		cout << "(";
		fun(xpos,ypos, lev / 2,  arr);
		fun(xpos, ypos + lev / 2, lev / 2, arr);
		fun(xpos + lev / 2, ypos, lev / 2, arr);
		fun(xpos + lev / 2, ypos + lev / 2, lev / 2, arr);
		cout << ")";
	}
	//for (int i = 0; i < cnt; i++) {
	//	cout << ")";
	//}
	return;
}

int main() {
	cin >> n;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int [n];
	}

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j] = str[j] - '0';
		}
	}
	fun(0, 0, n, arr);
	return 0;
}
