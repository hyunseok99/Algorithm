#include <iostream>
using namespace std;

int arr[1000001];


int main() {
	int k, n, result = 0;
	long long low = 1, high=0,middle;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		if (high< arr[i]) high = arr[i];
	}

	while (low <= high) {
		middle = (low + high) / 2;
		int cnt = 0;
		for (int i = 0;i<k; i++) {
			cnt += arr[i] / middle;
		}
		if (cnt >= n) {
			low = middle + 1;
			if (result < middle) result = middle;
		}
		else {
			high = middle - 1;
		}
	}
	cout << result;
	return 0;
}

