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

struct compare {
	bool operator()(pair<int, int> &a, pair<int, int> &b) {
		return a.second >= b.second;
	}
};

void act(vector<pair<int, int>>* arr, int* check, int start, int check_size) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> tmp;
	int sec = 0;
	int cnt = 0;
	tmp.push({ start, sec });
	while (!tmp.empty()) {
		pair<int, int> comp = tmp.top();
		int no = comp.first;
		int time = comp.second;
		tmp.pop();
		if (check[no] != -1 && check[no] < time) continue;

		for(int i=0; i< arr[no].size(); i++){
			int no_after = arr[no][i].first;
			int time_after = time + arr[no][i].second;

			
			if (check[no_after] == -1 || time_after < check[no_after]) {
				check[no_after] = time_after;
				tmp.push({ no_after, time_after });
			}
		}
	}

	for (int i = 1; i <= check_size; i++) {
		if (check[i] != -1) {
			cnt++;
			sec = max(sec, check[i]);
		}
	}
	cout << cnt << " " << sec << "\n";
	return;
}

void depend(int cnt, int rep, int start) {
	vector<pair<int,int>> *arr = new vector<pair<int, int>>[cnt + 1];
	int* check = new int[cnt + 1];
	for (int i = 1; i <= cnt; i++) {
		check[i] = -1;
	}
	check[start] = 0;
	for (int i = 0; i < rep; i++) {
		int a, b, s;
		cin >> a >> b >> s;
		arr[b].push_back({ a,s });
	}
	act(arr, check, start, cnt);
	return;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, d, s;
		// n: 컴퓨터 개수, d: 의존성 개수, c: 해킹 컴터 
		cin >> n >> d >> s;
		depend(n, d, s);

	}
	return 0;
}