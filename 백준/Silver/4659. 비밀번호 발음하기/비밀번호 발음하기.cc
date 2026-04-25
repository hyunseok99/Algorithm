#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
using namespace std;


int n, m, cnt;

bool fun(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	}
	return false;
}

int main() {
	while (1) {
		field:
		stack<char> st;
		string str;
		cin >> str;
		bool check = false;
		int consonant=0;
		int vowel=0;
		if (str == "end") break;
		for (int i = 0; i < str.size(); i++) {
			if (fun(str[i])) {
				check = true;
				vowel++;
				consonant = 0;
			}
			else {
				consonant++;
				vowel = 0;
			}
			if (vowel == 3 || consonant == 3) {
				cout << "<" << str << "> is not acceptable.\n";
				goto field;

			}
			if (i > 0 && str[i - 1] == str[i] && !(str[i] == 'e' || str[i] == 'o')) {
				cout << "<" << str << "> is not acceptable.\n";
				goto field;
			}

		}

		if (check == false) {
			cout << "<" << str << "> is not acceptable.\n";
		}
		else {
			cout << "<" << str << "> is acceptable.\n";

		}
	}
}