#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[3];
	int start[3];
	int end[3];
	int cnt[101] = { 0, };
	int result = 0;
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 3; i++) {
		cin >> start[i] >> end[i];
		for (int j = start[i]+1; j <= end[i]; j++) {
			cnt[j]++;
		}
	}
	
	for (int i = 0; i <= 100; i++) {
		if (cnt[i] == 3) {
			result += 3 * a[2];
		}
		else if (cnt[i] == 2) {
			result += 2 * a[1];
		}
		else if (cnt[i] == 1) {
			result +=  a[0];
		}
	}

	cout << result;
	return 0;
}