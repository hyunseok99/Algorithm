#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m, k;

vector<int> res;

// 오른쪽 ,하, 상, 왼쪽
int dx[4] = { 0, 1, -1, 0 };
int dy[4] = { 1, 0, 0, -1 };

// 행의 합 연산
void getRes(vector<vector<int>>& arr) {
	int mini = 100 * 50;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= m; j++) {
			sum += arr[i][j];
		}
		mini = min(mini, sum);
	}

	res.push_back(mini);
}

// 시작점과 끝점의 x좌표가 뒤바뀌면 끝 즉 증분 val > 1
// val: 2 * s 증분
void move(vector<vector<int>>& arr, pair<int, int> start, pair<int, int> end, int val) {
	int tmpX = start.first;
	int tmpY = start.second;
	int tmpVal = arr[tmpX][tmpY];

	while (val > 1) {

		// dir: -> 
		for (int i = 0; i < val; i++) {
			int tmp = tmpVal;
			tmpY += 1;
			tmpVal = arr[tmpX][tmpY];
			arr[tmpX][tmpY] = tmp;
		}

		for (int i = 0; i < val; i++) {
			int tmp = tmpVal;
			tmpX += 1;
			tmpVal = arr[tmpX][tmpY];
			arr[tmpX][tmpY] = tmp;
		}

		for (int i = 0; i < val; i++) {
			int tmp = tmpVal;
			tmpY -= 1;
			tmpVal = arr[tmpX][tmpY];
			arr[tmpX][tmpY] = tmp;
		}

		for (int i = 0; i < val; i++) {
			int tmp = tmpVal;
			tmpX -= 1;
			tmpVal = arr[tmpX][tmpY];
			arr[tmpX][tmpY] = tmp;
		}


		tmpX += 1;
		tmpY += 1;
		tmpVal = arr[tmpX][tmpY];
		val -= 2;

	}


	return;
}



void comb(vector<vector<int>> & arr, vector<int> rr, vector<int> cc, vector<int> ss) {
	vector<int> seq;
	for (int i = 0; i < k; i++) {
		seq.push_back(i);
	}

	do{
		vector<vector<int>> copyArr = arr;
		
		for (int i = 0; i < seq.size(); i++) {
			int idx = seq[i];
			pair<int, int> start = { rr[idx] - ss[idx], cc[idx] - ss[idx]};
			pair<int, int> end = { rr[idx] + ss[idx], cc[idx] + ss[idx]};
			int val = 2 * ss[idx];

			move(copyArr, start, end, val);
		}
		getRes(copyArr);


	}while(next_permutation(seq.begin(), seq.end()));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	vector<vector<int>> arr(n + 1, vector<int>(m + 1));
	vector<int> rr;
	vector<int> cc;
	vector<int> ss;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		rr.push_back(r);
		cc.push_back(c);
		ss.push_back(s);

	}
	comb(arr, rr, cc, ss);

	sort(res.begin(), res.end());

	cout << res.front();

	return 0;
}