#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool arr[10000001];

int main() {
	int n, m, k;
	int result = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		arr[k] = true;
	}
	for (int i = 1; i <= m / 2; i++) {
		if (i == m - i) break;
		else if (arr[i] == true && arr[m - i] == true) result++;
	}
	cout << result;
	return 0;
}

