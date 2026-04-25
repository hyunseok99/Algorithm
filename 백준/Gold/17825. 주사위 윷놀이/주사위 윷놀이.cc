#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <string>
#include <unordered_set>
#include <numeric>
#include <climits>
#include <stack>
#include <map>
#include <set>
using namespace std;

int n,m,ans;
int num[10];
int res[4];
int type[34];
int arr[34];
int score[34];
bool check[34];
vector<int> v;

// 말 4개


void fun(int lev, int sum ) {
	if (lev == 10) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int past_pos = res[i];
		int now_pos = past_pos;
		int cnt = num[lev];

		if (type[now_pos] != 0) {
			now_pos = type[now_pos];
			cnt--;
		}

		while (cnt > 0) {
			now_pos = arr[now_pos];
			cnt--;
		}

		if (now_pos != 21 && check[now_pos]) continue;
		check[past_pos] = false;
		check[now_pos] = true;
		res[i] = now_pos;
		fun(lev + 1, sum + score[now_pos]);
		res[i] = past_pos;
		check[now_pos] = false;
		check[past_pos] = true;
	}
}
void fun2(int lev, vector<int> h) {
	for (int j = 0; j < h.size(); j++) {
		for (int i = 0; i < 4; i++) {
			int past_pos = res[i];
			int now_pos = past_pos;
			int cnt = num[lev];

			if (type[now_pos] != 0) {
				now_pos = type[now_pos];
				cnt--;
			}

			while (cnt > 0) {
				now_pos = arr[now_pos];
				cnt--;
			}

			if (now_pos != 21 && check[now_pos]) continue;
			check[past_pos] = false;
			check[now_pos] = true;

		}
	}
}
int main() {
	for (int i = 0; i < 10; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 21; i++) {
		arr[i] = i + 1;
		score[i] = i * 2;
	}
	arr[21] = 21;
	for (int i = 22; i < 27; i++) {
		arr[i] = i + 1;
	}
	arr[27] = 20; 
	arr[28] = 29; arr[29] = 30; arr[30] = 25;
	arr[31] = 32; arr[32] = 25;
	type[5] = 22; type[10] = 31; type[15] = 28;
	score[22] = 13; score[23] = 16; score[24] = 19; score[25] = 25;
	score[26] = 30; score[27] = 35; score[28] = 28; score[29] = 27;
	score[30] = 26; score[31] = 22; score[32] = 24;

	fun(0,0);
	cout << ans;
	return 0;
}