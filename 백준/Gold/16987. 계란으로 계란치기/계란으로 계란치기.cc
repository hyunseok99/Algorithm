#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int res = 0;
struct egg {
	int weight;
	int durability;
};

// 깰 다른 계란을 또 선택하는 경우 true -> 부술 다른 계란 선택 및 
// 추가로 계란 꺠지면 flag: true
bool broken(int mine, int other, vector<egg> &arr, vector<bool> &flag) {
	arr[mine].durability -= arr[other].weight;
	arr[other].durability -= arr[mine].weight;

	if (arr[mine].durability > 0 && arr[other].durability <= 0) {
		// 상대만 꺠짐
		flag[other] = true;
		return true;
	}
	else if (arr[mine].durability > 0 && arr[other].durability > 0) {
		// 둘다 안깨짐
		return false;
	}
	else if (arr[mine].durability <= 0 && arr[other].durability > 0) {
		// 내꺼만 깨짐
		flag[mine] = true;
		return false;
	}
	else {
		// 둘다 깨짐
		flag[mine] = true;
		flag[other] = true;
		return false;
	}
}

// 손에든 계란이 깨졌거나 칠 다른 계란이 없는 경우
bool check(int mine, vector<bool>& flag) {
	if (flag[mine]) return true;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (i == mine) continue;
		if (!flag[i]) {
			cnt++;
		}
	}
	if (cnt == 0) return true;
	return false;
}

// flag가 true면 스킵
// mine: 들고 있는 계란 idx
// other: 꺨 계란 idx 
void backTracking(int mine, vector<egg> &arr, vector<bool> &flag) {
	// 마지막 계란으로 행위를 한 후 혹은 더이상 칠 계란이 없는 경우
	if (mine == n) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (flag[i] == true) {
				cnt++;
			}
		}
		res = max(res, cnt);

		return;
	}

	// 선택된 계란이 이미 깨지거나 더이상 깰 계란이 없는 경우
	if (check(mine, flag)) {
		backTracking(mine + 1, arr, flag);
		return;
	}

	// 깰 계란 선택
	for (int other = 0; other < n; other++) {
		// 만약 깰 계란과 선택된 계란이 같으면 continue;
		if (mine == other) { 
			continue; 
		}
		else {
			// 꺨 계란이 이미 깨진 상태라면 continue;
			if (flag[other]) continue;
			else {
				arr[mine].durability -= arr[other].weight;
				arr[other].durability -= arr[mine].weight;
				if (arr[mine].durability > 0 && arr[other].durability <= 0) {
					// 상대만 꺠짐
					flag[other] = true;
					backTracking(mine + 1, arr, flag);
					flag[other] = false;
				}
				else if (arr[mine].durability > 0 && arr[other].durability > 0) {
					// 둘다 안깨짐
					backTracking(mine + 1, arr, flag);

				}
				else if (arr[mine].durability <= 0 && arr[other].durability > 0) {
					// 내꺼만 깨짐
					flag[mine] = true;
					backTracking(mine + 1, arr, flag);
					flag[mine] = false;

				}
				else {
					// 둘다 깨짐
					flag[mine] = true;
					flag[other] = true;
					backTracking(mine + 1, arr, flag);
					flag[mine] = false;
					flag[other] = false;
				}
				arr[mine].durability += arr[other].weight;
				arr[other].durability += arr[mine].weight;
			}
		}
		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<egg> arr;
	// 깨짐 여부: 
	vector<bool> flag(n, false);
	for (int i = 0; i < n; i++) {
		egg tmp;
		cin >> tmp.durability >> tmp.weight;
		arr.push_back(tmp);
	}
	backTracking(0, arr, flag);

	cout << res;

	return 0;
}