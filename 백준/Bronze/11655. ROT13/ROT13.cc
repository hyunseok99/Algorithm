#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string str;
	getline(cin, str, '\n');
	for (int i = 0; i < str.length(); i++) {
		if (65 <= str[i] && str[i] <= 90) {
			if (str[i] + 13 <= 90) {
				str[i] = str[i] + 13;
			}
			else {
				str[i] = str[i] - 13;
			}
		}
		else if (97 <= str[i] && str[i] <= 122) {
			if (str[i] + 13 <= 122) {
				str[i] = str[i] + 13;
			}
			else {
				str[i] = str[i] - 13;
			}
		}
		else if (str[i] == '\0') {
			str[i] = ' ';
		}
	}
	cout << str;
	return 0;
}