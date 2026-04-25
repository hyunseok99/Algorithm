#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, k;

// 8방향
int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 0, -1, 1, 1, -1, -1, 1 };

// arr 땅의 양분, tree 나무 , arrA 겨울에 추가할 양분
void yearFunc(vector<vector<int>>& arr, vector<vector<vector<int>>> &tree,
	vector<vector<int>>& arrA) {

	vector<vector<int>> trash(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			// 봄 나이 및 땅 양분 갱신
			int killIdx = -1;
			for (int s = 0; s < tree[i][j].size(); s++) {
				if (tree[i][j][s] <= arr[i][j]) {
					arr[i][j] -= tree[i][j][s];
					tree[i][j][s] += 1;
				}
				else {
					if (killIdx == -1) {
						killIdx = s;
					}
					trash[i][j] += (tree[i][j][s] / 2);
				}

			}

			if (killIdx != -1) {
				tree[i][j].erase(tree[i][j].begin() + killIdx, tree[i][j].end());
			}
		}
	}

	// 여름 양분 갱신
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] += trash[i][j];
		}
	}
	
	// 가을 연산
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n; j++) {
			for (int s = 0;s < tree[i][j].size(); s++) {
				// 번식
				if (tree[i][j][s] % 5 == 0) {
					for (int dir = 0; dir < 8; dir++) {
						int nx = i + dx[dir];
						int ny = j + dy[dir];
						if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
							// 어차피 나이가 1이라 이 연산이 다른 지역의 번식에 영향 x
							tree[nx][ny].push_back(1);
						}
					}
				}

			}
		}

	}

	// 겨울 연산
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] += arrA[i][j];
		}
	}
}


// 나무 갯수
int ans(vector<vector<vector<int>>>& tree) {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			res += tree[i][j].size();
		}
	}
	return res;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	// 땅 양분 : 5로 초기화 
	vector<vector<int>> arr(n + 1, vector<int>(n + 1, 5));
	// 겨울에 추가되는 양분 
	vector<vector<int>> arrA(n + 1, vector<int>(n + 1));
	// 나무 
	vector<vector<vector<int>>> tree(n + 1, vector<vector<int>>(n + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arrA[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].push_back(z);

	}

	// k년이 지날때까지 연산 
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			for (int s = 1; s <= n; s++) {
				sort(tree[j][s].begin(), tree[j][s].end());
			}
		}
		yearFunc(arr, tree, arrA);
	}

	cout << ans(tree);

	return 0;
}