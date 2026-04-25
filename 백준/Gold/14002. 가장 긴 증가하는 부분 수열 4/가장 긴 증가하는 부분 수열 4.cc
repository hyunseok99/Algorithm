#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> seq;
	vector<pair<int, int>> pos(n); // seq 길이가 n인 경우 경우의 값 : 위치

	// 처음 원소 초기화
	pos[0] = { arr[0], 0 };
	seq.push_back(arr[0]);

	for (int i = 1; i < arr.size(); i++) {
		int val = arr[i];
		auto iter = lower_bound(seq.begin(), seq.end(), val);

		if (iter == seq.end()) {
			// lis 증가 + 위치 저장
			seq.push_back(val);
			pos[i] = { val, seq.size() - 1 };
		}
		else {
			// 아닌 경우 길이 유지에 값만 변경 + 위치 저장
			*iter = val;
			pos[i] = { val, iter - seq.begin() };

		}
	}

	// pos에는 i번째 원소의 위치가 저장되어 있음 이를 이용해 LIS ㄱㄱ
	vector<int> lis;
	int cur = seq.size() - 1; // seq 최종본의 idx
	for (int i = n - 1; i >= 0; i--) {
		// pos[i]의 삽입 idx가 cur와 같을 때
		if (pos[i].second == cur) {
			// pos[i].first가 lis에 존제 힌다면 이전에 넣은 원소보다 작아야 함 
			// 만약 lis가 비어있으면 처음에 추가
			if (lis.empty() || pos[i].first < lis.back()) {
				lis.push_back(pos[i].first);
				cur--;
			}
		}

		// cur < 0 종료
		if (cur < 0) break;
	}

	// 현재 lis에는 끝부터 존재 
	cout << lis.size() << "\n";
	for (int i = lis.size() - 1; i >= 0; i--) {
		cout << lis[i] << " ";
	}
	return 0;
}