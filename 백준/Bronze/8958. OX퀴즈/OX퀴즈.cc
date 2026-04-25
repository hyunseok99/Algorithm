#include <iostream>
#include <string>

using namespace std;

int OX(string& k) {
	int count = 0;
	int sum = 0;
	for (int i = 0; i < k.length(); i++) {
		if (k[i] == 'O') count++;
		else count = 0;
		sum += count;
	}
	return sum;
}

int main(void) {
	int n;
	cin >> n;
	string s;
	
	for (int i = 0; i < n; i++) {
		cin >> s;
		int count = 0;
		int sum = 0;
		cout << OX(s) << endl;
	}
	return 0;
}