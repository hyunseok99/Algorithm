#include <iostream>
using namespace std;

int main(void) {
	int n, max;
	double cen = 0;
	cin >> n;
	int* array = new int[n];
	for (int i = 0; i < n; i++)
		cin >> array[i];
	max = array[0];
	for (int i = 1; i < n; i++) {
		if (max < array[i])
			max = array[i];
	}
	for (int i = 0; i < n; i++)
		cen += (double)array[i] / max * 100;
	cout << cen /(double) n;

	return 0;
}