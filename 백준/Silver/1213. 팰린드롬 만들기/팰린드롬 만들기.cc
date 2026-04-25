#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;


int arr[26];
vector<char> v[26];
vector<char> val;
int main() {
	string str, check = "";
	int idx = -1;
	int odd = 0;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		v[str[i] - 'A'].push_back(str[i]);
		arr[str[i] - 'A']++;
	}

	for (int i = 0; i < 26; i++) {
		if (arr[i] > 0) {
			if (arr[i] % 2 == 1) {
				odd++;
				idx = i;
				arr[i]--;
			}
		}
	}

	if (odd >= 2) {
		cout << "I'm Sorry Hansoo" << "\n";
	}
	else {
		for (int i = 0; i < 26; i++) {
			if (arr[i] > 0) {
				for (int j = 0; j < arr[i] / 2; j++) {
					check += (i + 'A');
				}
			}
		}

		string rev(check);
		reverse(rev.begin(), rev.end());

		if (idx != -1) {
			check += idx + 'A';
		}

		cout << check + rev;
	}
	
	return 0;
}