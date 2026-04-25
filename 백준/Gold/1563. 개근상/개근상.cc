#include <iostream>
#include <vector>
using namespace std;

int n;
int res;
void ref(int num, vector<vector<vector<int>>> &v) {

	for (int i = 1; i < num; i++) {
		v[i + 1][0][0] = (v[i][0][0] + v[i][0][1] + v[i][0][2]) % 1000000;
		v[i + 1][0][1] = (v[i][0][0]) % 1000000;
		v[i + 1][0][2] = (v[i][0][1]) % 1000000;
		v[i + 1][1][0] = (v[i][0][0] + v[i][0][1] + v[i][0][2] + v[i][1][0] + v[i][1][1] + v[i][1][2]) % 1000000;
		v[i + 1][1][1] = (v[i][1][0]) % 1000000;
		v[i + 1][1][2] = (v[i][1][1]) % 1000000;
	}

	res = (v[num][0][0] + v[num][0][1] + v[num][0][2] + v[num][1][0] + v[num][1][1] + v[num][1][2])%1000000;
}



int main() {
	cin >> n;
	// v[n][1][2]
	vector<vector<vector<int>>> v(n+1, vector<vector<int>>(2,vector<int>(3)));

	v[1][0][0] = 1;
	v[1][1][0] = 1;
	v[1][0][1] = 1;
	ref(n, v);

	cout << res;
	return 0;
}