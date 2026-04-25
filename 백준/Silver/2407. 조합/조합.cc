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

// 2407 
// nCm 출력 5<=n,m<=100 이므로 직접적인 계산으로는 불가능
// An = n! 일 때 An+1 =  n * An 이용 nCm = n!/(m!*(|n-m|!))
// or  nCm = n-1Cm-1  + n-1Cm 이용 
// 대략 10^18 승까지는 long long 타입으로 출력이 가능하나 그 이상은 출력 안됌
// 10C50 정도의 자릿수가 너무 크다  따로 자릿수도 고려해서 출력해야 함. 걍 string으로 처리


int main() {
	int n, m;
	cin >> n >> m;
	// n,m을 인덱스로 갖는 벡터 만들기
	vector<vector<string>> v(101, vector<string>(101)); // 값
	
	// 기본 값 초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || (i==j)) v[i][j] = '1';
			else {
				int sum = 0;
				string s = v[i - 1][j];
				string s2 = v[i - 1][j - 1];

				while (s.length() != 0 || s2.length() != 0 || sum != 0) {
					if (s.length() != 0) {
						sum += s.back() - '0';
						s.pop_back();
					}
					if (s2.length() != 0) {
						sum += s2.back() - '0';
						s2.pop_back();
					}
					v[i][j].push_back((sum % 10) + '0'); // 일의자리만 push 이후 몪을 넘김
					sum /= 10;
				}
				reverse(v[i][j].begin(), v[i][j].end());
			}
		}
	}

	cout << v[n][m];

	return 0;
}