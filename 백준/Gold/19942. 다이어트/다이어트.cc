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

int n,m,a,b,c,d,cnt=0;
int mini = INT_MAX;
int res[16];
bool flag[16];
int type[16];

struct nut{
	int type_a;
	int type_b;
	int type_c;
	int type_d;
	int price;

};

vector<nut> v(16);

void cal(int lev) {
	nut temp = { 0,0,0,0,0 };
	for (int k = 1; k <= lev; k++) {
		nut x = v[type[k]];
		temp.type_a += x.type_a;
		temp.type_b += x.type_b;
		temp.type_c += x.type_c;
		temp.type_d += x.type_d;
		temp.price += x.price;
	}
	if (temp.type_a >= a && temp.type_b >= b && temp.type_c >= c && temp.type_d >= d && mini > temp.price) {
		mini = temp.price;
		for (int j = 1; j <= lev; j++) {
			res[j] = type[j];
		}
		cnt = lev;
	}
	return;
}

void fun(int index, int lev ) {
	for (int i = index; i <= n; i++) {
		if (!flag[i]){
			flag[i] = true;
			type[lev] = i;
			cal(lev);
			fun(type[lev], lev + 1);
			flag[i] = false;
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> a >> b >> c >> d;
	for (int i = 1; i <= n; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		nut temp = { a,b,c,d,e };
		v[i] = temp;
	}
	fun(1, 1);
	if (cnt > 0) {
		cout << mini << "\n";
		for (int i = 1; i <= cnt; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
	}
	else cout << -1 << "\n";

	return 0;
}