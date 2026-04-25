#include <iostream>
using namespace std;

int main() {
	int a, b;
	for (;;) {
		cin >> a >> b;
		if (cin.eof()) break;
		cout << a + b << " ";
	}
	return 0;
}
