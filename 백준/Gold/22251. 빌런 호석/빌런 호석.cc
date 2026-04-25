#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int n, k, p, x;
int res;

// 위에서부터 아래로, 왼쪽에서 오른쪽으로 led idx 처리
// 0 -> off, 1 -> on
int led[10][7] = { {1, 1, 1, 0, 1, 1, 1},{0, 0, 1, 0, 0 ,1 ,0},{1, 0, 1, 1, 1 ,0 ,1},{1, 0, 1, 1, 0 ,1 ,1},{0, 1, 1, 1, 0 ,1 ,0},{1, 1, 0, 1, 0 ,1 ,1},{1, 1, 0, 1, 1 ,1 ,1},{1, 0, 1, 0, 0 ,1 ,0},{1, 1, 1, 1, 1 ,1 ,1},{1, 1, 1, 1, 0 ,1 ,1}
};

// x가 아닌 다른 충과의 led 차이 갯수를 확인해서 p개 이하면 정답 +1 
void action(vector<int> arrN, vector<int> arr) {
	int changes = 0;
	for (int i = 0; i < arr.size(); i++) {
		int arrLed = arr[i];
		int arrNLed = arrN[i];
		for (int j = 0; j < 7; j++) {
			if (led[arrLed][j] != led[arrNLed][j]) {
				changes++;
			}
		}
	}
	if (changes <= p) res++;
}

// n: 1~n 층 , k: 디스플레이 k자리, p: 최대 p개 반전 x: 실제 층
int main() {
	cin >> n >> k >> p >> x;

	// 실제 층의 분해 ex) k=4, n=300, x = 107 -> 0107
	vector<int> arr;
	int val = x;
	for (int i = k - 1; i >= 0; i--) {
		int tmp = val / pow(10, i);
		val -= (tmp * pow(10, i));
		arr.push_back(tmp);
	}

	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		vector<int> arrN;
		int val = i;
		for (int j = k - 1; j >= 0; j--) {
			int tmp = val / pow(10, j);
			val -= (tmp * pow(10, j));
			arrN.push_back(tmp);
		}
		action(arrN, arr);
	}

	cout << res;
	return 0;
}