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

int n,l,cnt,res=0;
int arr[101][101];
bool check[101][101];
int dir[2] = {1,-1};

int x, y;

void rawfun(int a, int lev=0) {
	if (lev == n - 1) {
		res++;
		return;
	}
	int temp = arr[a][lev];
	int next = arr[a][lev+1];
	if (temp - 1 == next) {
		cnt = 0;
		while (cnt < l) {
			if (!check[a][lev+1] && arr[a][lev+1] == temp - 1 && lev<n) {
				cnt++;
				check[a][lev+1] = true;
				lev++;
			}
			else return;
		}
		rawfun(a, lev);
	}
	if (temp + 1 == next) {
		cnt = 0;
		while (cnt < l) {
			if (!check[a][lev] && arr[a][lev] == next - 1 && lev >= 0) {
				cnt++;
				check[a][lev] = true;
				lev--;
			}
			else return;
		}
		rawfun(a, lev + l+1);
	}
	if (temp == next) {
		rawfun(a, ++lev);
	}
	
}

void lowfun(int b, int lev =0) {
	if (lev == n - 1) {
		res++;
		return;
	}
	int temp = arr[lev][b];
	int next = arr[lev+1][b];
	if (temp - 1 == next) {
		cnt = 0;
		while (cnt < l) {
			if (!check[lev+1][b] && arr[lev+1][b] == temp - 1 && lev < n) {
				cnt++;
				check[lev+1][b] = true;
				lev++;
			}
			else return;
		}
		lowfun(b, lev);
	}
	if (temp + 1 == next) {
		cnt = 0;
		while (cnt < l) {
			if (!check[lev][b] && arr[lev][b] == next - 1 && lev >= 0) {
				cnt++;
				check[lev][b] = true;
				lev--;
			}
			else return;
		}
		lowfun(b, lev + l + 1);
	}
	if (temp == next) {
		lowfun(b, ++lev);
	}
}

int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		rawfun(i, 0);
	}
	fill(&check[0][0], &check[100][101], false);
	
	for (int i = 0; i < n; i++) {
		lowfun(i, 0);
	}
	
	cout << res;
}