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

// 이전 이동 거리 s -> 새로운 가능 이동거리 s-1, s, s + 1   stack 내부에 (s,s-1) (s,s), (s, s+1) 이런식으로 쌓고  y보다 커지면 그 스택 버림
// 값 커지면 -> bfs 탐색으로는 깊이가 말도 안됨 -> 점화식 같은 규칙을 찾아야 할듯
// 한칸식 무한하게 이동 가능 -> 무조건 도착 가능
// ex) s = 3 -> 1 1 1  s=4 -> 1 2 1 s=5 -> 1 2 1 1 s=6 ->  1 2 2 1  s=9 -> 1 2 3 2 1 s= 16 -> 1 2 3 4 3 2 1
// 시그마 값 1, 4, 9, 16 . . n^2 , 이 시그마 값들 사이에 존재하는 경우에 어떤 횟수를 구해주면 답이 나올거 같음
// s = 3인경우 -> 1~4 사이 값 따라서 시그마 값 1 이용해서 1 + 1 + 1
// s = 6인경우 -> 4~9 사이 값 따라서 시그마 값 4 이용해서 1 + 2 + 1   최대한 2를 이용하고 남은 만큼 1 이용하면 그게 최소가 아닐까? 1 + 1 + 2 + 1
// s = 8인경우 -> 1 + 2 + 1 남은거리 3 -> 2+1 
// s = 10인경우 -> 1 + 2 + 3 + 2 + 1 남은거리 1  총 3^2의 3 + 1 = 4번 이동

int t;
long long x, y;


// y-x거리에 해당하는 누적 특정 제곱값을 만드는 n 리턴 , y-x-n => 남은 이동해야하는 거리이고 이를 n , n-1, n-2 ... 1 까지 줄여가며 나머지가 0 될때까지 
int getN() {
	long long d = y - x;
	return sqrt(y - x);
}

// 장치 작동 횟수 리턴 , 장치 작동 횟수는 기본 n에  n, n-1, n-2..1 순으로 나머지가 없어질 때까지 하고 몫을 cnt에 추가 
int getCnt() {
	int n = getN();
	int cnt = n;
	int remain = (y - x) - n;
	int divisor = n;
	while (remain != 0) {

		// 몫을 cnt에 더하고 remain = remain - (divisor * 몫) 이후 기존 divisor 값 -1 ,  remain이 0이 될 때 까지
		int share = remain / divisor;
		cnt += share;
		remain -= (divisor * share);
		divisor--;
	}
	return cnt;
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		int res = 0;
		cin >> x >> y;
		// 
		// 출력
		cout << getCnt()<< "\n";
	}

	return 0;
}