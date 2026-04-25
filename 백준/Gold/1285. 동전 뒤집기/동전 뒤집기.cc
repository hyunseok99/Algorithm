#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <string>
#include <unordered_set>
#include <numeric>
#include <climits>
#include <stack>
#include <map>
#include <set>
using namespace std;

int n, m, cnt, res= 500;
string arr[21];

int fun(int row) {
	int sum = 0;
	for (int col = 0; col < n; col++) {
		int cnt_T = 0;

		for (int i = 0; i < n; i++) {
			
			bool check = arr[i][col] == 'H';
			if ((row & (1 << i)) != 0) check = !check;
			if (check) cnt_T++;
		}
		sum += min(cnt_T, n - cnt_T);
	}

	return sum;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < (1<<n); i++) {
		res = min(res, fun(i));
	}
	cout<<res;
	return 0;
}