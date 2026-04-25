#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); ) {
		if ((i <= str.size() - 2) && ((str[i] == 'p' && str[i + 1] == 'i') || (str[i] == 'k' && str[i + 1] == 'a'))) {
			i = i + 2;
			if (i == str.size()) {
				cout << "YES";
				return 0;
			}
		}
		else if ((i <= str.size() - 3) && (str[i] == 'c' && str[i + 1] == 'h' && str[i + 2] == 'u')) {
			i = i + 3;
			if (i == str.size()) {
				cout << "YES";
				return 0;
			}
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	return 0;
}