#include <iostream>
using namespace std;

int mycount = 0;

void function(int n) {
	int a, b, c;
	a = n / 100;
	b = n % 100 / 10;
	c = n % 10;
	if (n < 100) {
		mycount++;
	}
	else {
		if (a - b == b - c) {
			mycount++;
		}
	}
}

int main(void) {
	int n; 
	cin >> n;
	for (int i = 1; i < n + 1; i++)
		function(i);
	cout <<  mycount;
	return 0;
}