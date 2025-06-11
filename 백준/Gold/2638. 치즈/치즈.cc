#include <iostream>
#include <vector>
#include <utility>
#include <stack>
using namespace std;

int n, m;
int cnt;

// 상하좌우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isInside(vector<vector<int>>& arr, stack<pair<int,int>> s) {
	vector<vector<int>> flag(n, vector<int>(m));
	while (!s.empty()) {
		pair<int, int> tmp = s.top();
		if (tmp.first == 0 || tmp.first == n - 1 || tmp.second == 0 || tmp.second == m - 1) return false;
		flag[tmp.first][tmp.second] = 1;
		s.pop();
		for (int i = 0; i < 4; i++) {
			int nx = tmp.first + dx[i];
			int ny = tmp.second + dy[i];
			if (flag[nx][ny] == 0 && arr[nx][ny] == 0 && nx >= 0 && nx < n && ny >= 0 && ny < m) {
				s.push({ nx, ny });
			}
		}
	}
	return true;
}

// 사라질 치즈인지 체크하는 함수
void check(vector<vector<int>>& arr, int& toMelt) {
	// 사라질 치즈 좌표
	vector<pair<int, int>> cheeze;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int edge = 0;
			if (arr[i][j] == 0) continue;

			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (arr[nx][ny] == 0) {
						bool flag = true;
						stack <pair<int, int>> s;
						s.push({ nx, ny });
						if (!isInside(arr, s)) {
							edge++;
						}
					}
				}
				if (edge >= 2) {
					cheeze.push_back({ i,j });
					break;
				}
			}
		}
	}

	for (int i = 0; i < cheeze.size(); i++) {
		arr[cheeze[i].first][cheeze[i].second] = 0;
	}
	
	toMelt -= (int)cheeze.size();

	//cout << "==================" << "\n";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "==================: cnt" << toMelt << "\n";


}

int main() {
	int toMelt = 0;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) toMelt++;
		}
	}
	while (toMelt > 0) {
		check(arr, toMelt);
		cnt++;
	}

	cout << cnt;

	return 0;
}