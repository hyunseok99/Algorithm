#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin >> n >> m;
	string* Cp = new string[n];
	int* p = new int[n];
	int* Ip = new int[m];
	for (int i = 0; i < n; i++) {
		cin >> Cp[i] >> p[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> Ip[i];
		cout << Cp[lower_bound(p, p + n, Ip[i]) - &p[0]]<<"\n";
	}
	return 0;
}