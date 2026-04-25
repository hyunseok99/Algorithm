#include <iostream>

using namespace std;

int main(void) {
	int a, b, c;
	int ans = 0;
	cin >> a>>b >> c;
	if (b >= c) cout << -1;
	else {
		ans = a / (c - b) + 1;
		cout << ans;
	}
	return 0;
}