#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int arr[26];
int main() {
	int n;
	string s;
	string result ;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		arr[s[0] - 97]++;
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] >= 5) {
			result += i+97;
		}
	}
	if (result == "") {
		cout << "PREDAJA";
	}
	else cout << result;
    
	return 0;
}