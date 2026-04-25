#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

vector<int> v;
int n, m, s;
int dx[2] = { 1,-1 };
int dis;
pair<int,int> fun(pair<int,int> pos, int item_pos) {
	if (pos.first > item_pos) {
		while (pos.first != item_pos) {
			pos.first--;
			pos.second--;
			dis++;
		}
		return pos;
	}
	else if (pos.second < item_pos) {
		while (pos.second != item_pos) {
			pos.first++;
			pos.second++;
			dis++;
		}
		return pos;
	}
	return pos;
}
int main() {
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < s; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	pair<int, int> temp(make_pair(1, m));
	for (int i = 0; i < v.size(); i++) {
		temp = fun(temp, v[i]);
	}
	cout << dis;
}