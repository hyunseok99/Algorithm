#include <iostream>
#include <vector>
using namespace std;

int n, m;

int val[6] = { 1, 2, 3, 4, 5, 6 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	vector<int> arr(101);
	// 0이 아니면 이동 위치   

	vector<int> cnt(101, 200); // 최소 이동 횟수 
	cnt[1] = 0;


	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		arr[x] = y;
	}

	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		arr[u] = v;
	}

	bool flag = true; // cnt 값 갱신 발생 여부 
	
	while (flag) {
		flag = false;
		for (int i = 1; i <= 100; i++) {
			if (cnt[i] == 200) continue; 
			for (int dx = 0; dx < 6; dx++) {
				int ndx = i + val[dx];
				if (ndx <= 100){
					int pos = ndx;
					if (arr[ndx] != 0) { // 사다리 or 뱀 존재 -> 이동
						pos = arr[ndx];
					}

					// 최소 이동거리 갱신 
					if (cnt[pos] > cnt[i] + 1) {
						cnt[pos] = cnt[i] + 1;
						flag = true;
					}

				}

			}
		}

	}

	cout << cnt[100];
	return 0;
}