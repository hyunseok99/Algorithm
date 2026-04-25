#include <iostream>
using namespace std;

int main(void) {
	int n, m;
	int count = 0;
	cin >> m;
	n = m;
	do {
		n = (n % 10) * 10 + ((n % 10) + (n / 10)) % 10;
		count++;
	} while (n != m);
	cout << count;
	return 0;
}