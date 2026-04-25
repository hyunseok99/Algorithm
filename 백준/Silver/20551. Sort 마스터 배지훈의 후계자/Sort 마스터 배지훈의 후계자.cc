#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, value;
	cin >> n >> m;
	int* p = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p, p + n);
	for (int i = 0; i < m; i++) {
		cin >> value;
		if (binary_search(p, p + n, value)) {
			cout << lower_bound(p, p + n, value) - &p[0] << "\n";
		}
		else cout << "-1\n";
	}

}