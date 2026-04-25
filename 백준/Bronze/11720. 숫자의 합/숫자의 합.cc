#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int n;
	int sum = 0;
	cin >> n;
	char* ptr = new char[n];

	cin >> ptr;
	for (int i = 0; i < n; i++) {
		sum += (ptr[i] - '0');
	}

	cout << sum << endl;
	
	return 0;
}