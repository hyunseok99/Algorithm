#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int arr[100001];
int main() {
	int max;
	int sum= 0;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < k; i++) {
		sum += arr[i];
	}
	max = sum;

	for (int i = 0; i < n - k; i++) {	
		sum = sum - arr[i] + arr[i + k];
		if (sum > max) max = sum;
	}
	cout<<max;
	return 0;

}