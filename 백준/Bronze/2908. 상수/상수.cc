#include <iostream>
#include <string>

using namespace std;


int main(void) {
	int idx = 2;
	string a, b;
	cin >> a >> b;

	while (idx >= 0) {
		if (a[idx] == b[idx]) {
			cout << a[idx--];
			continue;
		}
		if (a[idx] > b[idx])
			while (idx >= 0)
				cout << a[idx--];
		else while (idx >= 0)
			cout << b[idx--];
	}

	return 0;
}