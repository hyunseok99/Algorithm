#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int n = 5;


// 상하좌우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 중복 여부 체크

// cntS: 포함한 S 갯수 , cntY: 포함한 Y 갯수 
int getRes(vector<string>& arr) {
	// res: 가능 가짓수
	int res = 0;

	// 7개 포함 조합의 경우 생성하기 : 정렬 필요 
	vector<int> comb;
	for (int i = 0; i < 25; i++) {
		if (i < 7){
			comb.push_back(1); 
		}
		else {
			comb.push_back(0);
		}
	}
	sort(comb.begin(), comb.end());

	do {
		queue<pair<int, int>> q;
		// 방문 체크용
		vector<vector<bool>> flag(n, vector<bool>(n, false));

		// 25개중 선택된 7명의 위치 체크용 
		vector<vector<bool>> selected(n, vector<bool>(n, false));

		// line: 인접한 사람 수, cntS: S그룹 인원
 		int line = 0;
		int cntS = 0; 

		for (int i = 0; i < 25; i++) {
			// 선택된 7명의 idx
			if (comb[i] == 1) {
				int x = i / 5;
				int y = i % 5;
				selected[x][y] = true;		
				// 중복 방지
				if (q.empty()) {
					q.push({ x, y });
					flag[x][y] = true;
				}
			}

		}

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			line++;

			if (arr[x][y] == 'S') {
				cntS++;
			}

			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					// 선택된 노드이며 방문하지 않은 경우에 push
					if (!flag[nx][ny] && selected[nx][ny]) {
						q.push({ nx, ny });
						flag[nx][ny] = true;
					}
				}
			}
		}

		if (line >= 7 && cntS >= 4) {
			res++;
		}

	} while (next_permutation(comb.begin(), comb.end()));

	return res;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<string> arr;

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	

	cout << getRes(arr);

	return 0;
}