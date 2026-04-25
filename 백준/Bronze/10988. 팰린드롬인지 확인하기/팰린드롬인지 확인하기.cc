#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	string str;
	string cstr;
	cin >> str;
	for (int i = str.length()-1; i >= 0; i--) {
		cstr += str[i];
	}

	if (str == cstr) {
		cout << 1;
	}
	else cout << 0;

	return 0;
}