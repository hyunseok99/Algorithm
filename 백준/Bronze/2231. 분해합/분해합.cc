#include <iostream>
using namespace std;


int main() {
	int n,s,sum;
	cin >> n;
	for (int i = 1; i < n; i++) {
		s = i; sum = s;
		while (s) {
			sum += s%10;
			s /= 10;
		}
		if (sum == n) {
			cout << i << endl;
			return 0;
		}
	}
	cout << "0" << endl;
	return 0;
}
