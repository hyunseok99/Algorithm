#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int res = -1;

void backTracking(vector<vector<int>>& player, vector<bool>& flag, int lev, int sum) {
	if (lev == 11) {
		res = max(res, sum);
		return;
	}

	for (int i = 0; i < 11; i++) {
		if (player[i][lev] != 0 && !flag[i]) {
			flag[i] = true;
			backTracking(player, flag, lev + 1, sum + player[i][lev]);
			flag[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;


	for (int i = 0; i < n; i++) {
		vector<vector<int>> player(11, vector<int>(11));
		// 선수 사용 여부	
		vector<bool> flag(11, false);

		for (int j = 0; j < 11; j++) {
			for (int k = 0; k < 11; k++) {
				cin >> player[j][k];
			}
		}
		backTracking(player, flag, 0, 0);
		cout << res << "\n";
		res = -1;
	}

	return 0;
}