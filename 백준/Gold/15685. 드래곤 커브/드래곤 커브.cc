#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n, res;
int d;
bool check[101][101];
bool flag[101][101];
int temp_arr[101][101];
int arr[101][101];
							// 0	1		2		3
vector<pair<int, int>> v = { {0,1},{-1,0},{0,-1},{1,0}};
vector<pair<int, int>> pos;


void curv(int lev) {
	pair<int, int> dragon_curv = pos[0];
	pair<int, int> dragon_curv2 = pos.back();

	vector<pair<int, int>> temp_v;
	vector<pair<int, int>>::iterator iter;
	vector<pair<int, int>>::reverse_iterator riter;

	for (iter = pos.begin(); iter != pos.end(); iter++) {
		int i = iter->first;
		int j = iter->second;
		check[i][j] = true;
		int temp_x = j;
		int temp_y = 100 - i - 1;
		temp_v.push_back({ temp_x,temp_y });
	}
	int dis_x = dragon_curv2.first - temp_v.back().first;
	int dis_y = dragon_curv2.second - temp_v.back().second;
	for (riter = temp_v.rbegin()+1; riter != temp_v.rend(); riter++) {
		int temp_x = riter->first + dis_x;
		int temp_y = riter->second + dis_y;
		check[temp_x][temp_y] = true;
		pos.push_back({ temp_x,temp_y });
	}
	if (lev != d) {
		curv(lev+1);
		return;
	}
	return;
}

void fun(int x, int y) {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			int a, b;
			a = j + 1;
			b = i + 1;
			if (a >= 0 && a <= 100 && b >= 0 && b <= 100) {
				if (check[i][j] && check[i][a] && check[b][j] && check[b][a]) {
					res++;
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		pos.clear();
		int a, b, c;
		cin >> a >> b >> c >> d;
		int temp_y = a + v[c].second;
		int temp_x = b + v[c].first;
		pos.push_back({ b,a });
		pos.push_back({ temp_x,temp_y });
		if (d == 0) {
			check[b][a] = true;
			check[temp_x][temp_y] = true;
		}
		else curv(1);
	}
	fun(0, 0);
	cout << res;
	return 0;
}
