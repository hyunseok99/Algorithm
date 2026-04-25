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

// 1. 토네이도 이동 로직 구현 2. 모래 계산 로직 구현
// 토네이도 이동방향: 왼, 아래, 오른, 위  1 1 2 2 3 3 4 4 5 5....

int dir_x[4] = { 0, 1 , 0, -1 };
int dir_y[4] = { -1, 0 , 1, 0 }; 
int arr[500][500];
int result = 0;
int loss = 0;
int n;

struct Wind{
	int x;
	int y;
	int dir_x;
	int dir_y;
};

void calc(Wind tmp);
void check(int x, int y, int percent, int sand);

void turn(Wind tmp) {
	int idx = 0;

	// 마지막에 내 코드 상에서 위치는 0,-1이지만 실제는 0,0
	while (!(tmp.x == 0 && tmp.y < 0)) {
		// wind 위치 갱신
		for (int i = 0; i < (idx / 2) + 1; i++) {
			tmp.x += dir_x[(idx % 4)];
			tmp.y += dir_y[(idx % 4)];
			tmp.dir_x = dir_x[(idx % 4)];
			tmp.dir_y = dir_y[(idx % 4)];
			// 한칸 이동 여기에 토네이도 모래 로직 ㄱㄱ
			calc(tmp);
		}
		idx++;
	}
}

// 토네이도 진행 방향 기준으로 위치 계산 
// 입력: 토네이도 이동 후 정보
void calc(Wind tmp) {
	// tmp.dir_x, tmp.dir_y -> 토네이도 진행 방향 
	// tmp.x, tmp.y -> 이동 할 모래의 좌표
	int sand = arr[tmp.x][tmp.y];
	arr[tmp.x][tmp.y] = 0;
	// 모래가 소멸되는지 체크, 각각 % 별로 , 만약 return false라면 그 위치에 누적시켜주고, true라면 사라짐
	// 전역 변수 loss는 총 손실되는 모래 양임. , 알파의 모래량 = sand - loss;

	// 진행방향 왼쪽인 경우
	if (tmp.dir_x == 0 && tmp.dir_y == -1) {
		// 5% 10% 10% 7% 7% 2% 2% 1% 1% 알파 계산
		loss = 0;
		check(tmp.x, tmp.y - 2, 5, sand);
		check(tmp.x - 1, tmp.y - 1, 10, sand);
		check(tmp.x + 1, tmp.y - 1, 10, sand);
		check(tmp.x - 1, tmp.y, 7, sand);
		check(tmp.x + 1, tmp.y, 7, sand);
		check(tmp.x - 2, tmp.y, 2, sand);
		check(tmp.x + 2, tmp.y, 2, sand);
		check(tmp.x - 1, tmp.y + 1, 1, sand);
		check(tmp.x + 1, tmp.y + 1, 1, sand);

		check(tmp.x, tmp.y - 1, 0, sand - loss);

	}
	// 진행 방향 아래인 경우
	else if (tmp.dir_x == 1 && tmp.dir_y == 0) {
		loss = 0;
		check(tmp.x + 2, tmp.y, 5, sand);
		check(tmp.x + 1, tmp.y - 1 , 10, sand);
		check(tmp.x + 1, tmp.y + 1, 10, sand);
		check(tmp.x , tmp.y + 1, 7, sand);
		check(tmp.x , tmp.y - 1, 7, sand);
		check(tmp.x , tmp.y - 2, 2, sand);
		check(tmp.x , tmp.y + 2, 2, sand);
		check(tmp.x - 1, tmp.y + 1, 1, sand);
		check(tmp.x - 1, tmp.y - 1, 1, sand);
	
		check(tmp.x+1, tmp.y, 0, sand - loss);

	}
	// 진행 방향 오른쪽인 경우
	else if (tmp.dir_x == 0 && tmp.dir_y == 1) {
		loss = 0;
		check(tmp.x , tmp.y + 2, 5, sand);
		check(tmp.x - 1, tmp.y + 1, 10, sand);
		check(tmp.x + 1, tmp.y + 1, 10, sand);
		check(tmp.x - 1, tmp.y , 7, sand);
		check(tmp.x + 1, tmp.y , 7, sand);
		check(tmp.x + 2, tmp.y , 2, sand);
		check(tmp.x - 2, tmp.y , 2, sand);
		check(tmp.x + 1, tmp.y - 1, 1, sand);
		check(tmp.x - 1, tmp.y - 1, 1, sand);

		check(tmp.x , tmp.y + 1, 0, sand - loss);

	}
	// 진행 방향 위인 경우
	else if (tmp.dir_x == -1 && tmp.dir_y == 0) {
		loss = 0;
		check(tmp.x - 2, tmp.y, 5, sand);
		check(tmp.x - 1, tmp.y - 1, 10, sand);
		check(tmp.x - 1, tmp.y + 1, 10, sand);
		check(tmp.x, tmp.y + 1, 7, sand);
		check(tmp.x, tmp.y - 1, 7, sand);
		check(tmp.x, tmp.y - 2, 2, sand);
		check(tmp.x, tmp.y + 2, 2, sand);
		check(tmp.x + 1, tmp.y + 1, 1, sand);
		check(tmp.x + 1, tmp.y - 1, 1, sand);

		check(tmp.x - 1, tmp.y, 0, sand - loss);

	}

}

// 모래가 소멸되는 위치인지 체크
void check(int x, int y, int percent, int sand) {
	// 판 안에 있음
	int tmp_sand = sand * percent / 100;
	if (percent == 0) tmp_sand = sand;

	if (x >= 0 && y >= 0 && x < n && y < n) {
		// 해당 위치에 모래량 추가 , 어차피 마지막에만 알파 계산하면 loss 상관 없음
		arr[x][y] += tmp_sand;
		loss += tmp_sand;
		return;
	}

	// 소멸되는 모래 답에 추가
	result += tmp_sand;
	loss += tmp_sand;
	return;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	Wind my_wind;
	my_wind.x = n/2;
	my_wind.y = n/2;
	turn(my_wind);
	cout << result;
	return 0;
}