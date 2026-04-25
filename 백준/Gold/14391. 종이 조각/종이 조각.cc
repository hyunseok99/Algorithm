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

int n,m,cnt;
char arr[16];
string ret ="";
int res;
int ans = -1;

//s 1~16 5bit
// 1-> row,  0-> col

void fun(int num) {
	// check row
	res = 0;
	for (int i = 0; i < n; i++) {
		ret = "";
		for (int j = 0; j < m; j++) {
			if (num & (1 << (i * m + j))) {
				ret += arr[i * m + j];
			}
			else { 
				if(ret.size()!=0) res += stoi(ret);
				ret = "";
			}
		}
		if(ret.size()!=0)res += stoi(ret);
	}

	//check col
	for (int j = 0; j < m; j++) {
		ret = "";
		for (int i = 0; i < n; i++) {
			if (!(num & (1 << (i * m + j)))) {
				ret += arr[i * m + j];
			}
			else {
				if (ret.size() != 0) res += stoi(ret);
				ret = "";
			}
		}
		if (ret.size() != 0)res += stoi(ret);
	}

	ans = max(ans, res);
	return;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i*m+j];
		}
	}
	for (int i = 0; i < (1 << n * m); i++) {
		fun(i);
	}
	cout << ans;
}