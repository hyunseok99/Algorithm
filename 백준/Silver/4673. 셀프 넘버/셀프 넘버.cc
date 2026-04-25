#include <iostream>
using namespace std;

int function(int n) {
	int re = n;
	while (n > 0)
	{
		re = re + n % 10;
		n = n / 10;
	}

	return re;
}

int main(void) {
	int arr[10001] = { 0, };
	int state;
	for (int i = 0; i < 10001; i++) {
		state = function(i);
		if (state < 10001) {
			arr[state] = 1;
		}
	}
	for (int i = 0; i < 10001; i++) {
		if (arr[i] != 1)
		{
			cout << i << endl;
		}
	}
	return 0;
}