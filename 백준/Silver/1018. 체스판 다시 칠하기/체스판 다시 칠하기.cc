#include <iostream>
#include <string>
using namespace std;

char arr[51][51];
int ans = INT16_MAX;

int main() {
	int m, n,k;
	string s;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n-7; i++) {
		for (int j = 0; j < m-7; j++) {
			int cnt1 = 0; //w시작 색칠 갯수
			int cnt2 = 0; //b시작 색칠 갯수
			for (int a =0; a < 8; a++) {
				for (int b =0; b < 8; b++) {
					//W 시작 
					if ((a % 2 == 0) && ((b % 2) == 0)) {//행,열 짝수
						if (arr[i + a][j + b] == 'B') cnt1++;
					}
					else if ((a % 2 == 0) && ((b % 2) != 0)) {
						if (arr[i + a][j + b] == 'W') cnt1++;
					}
					else if ((a % 2 != 0) && ((b % 2) == 0)) {
						if (arr[i + a][j + b] == 'W') cnt1++;
					}
					else if ((a % 2 != 0) && ((b % 2) != 0)) {
						if (arr[i + a][j + b] == 'B') cnt1++;
					}
					//B 시작
					if ((a % 2 == 0) && ((b % 2) == 0)) {//행,열 짝수
						if (arr[i + a][j + b] == 'W') cnt2++;
					}
					else if ((a % 2 == 0) && ((b % 2) != 0)) {
						if (arr[i + a][j + b] == 'B') cnt2++;
					}
					else if ((a % 2 != 0) && ((b % 2) == 0)) {
						if (arr[i + a][j + b] == 'B') cnt2++;
					}
					else if ((a % 2 != 0) && ((b % 2) != 0)) {
						if (arr[i + a][j + b] == 'W') cnt2++;
					}
				}
			}
			k = (cnt1 > cnt2 ? cnt2 : cnt1);
			ans = (ans > k ? k : ans);
		}
	}
	cout << ans;
	return 0;
}