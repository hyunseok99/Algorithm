#include <iostream>
#include <vector>
#include <string>
using namespace std;

int cnt = 0;
string func(string s) {
	int k = 0;
	for (int i = 0; i < s.size(); i++) {
		k += s[i] - '0';
	}
	return to_string(k);
}

int main() {
	string s;
	cin >> s;
	
	while (s.size() != 1) {
		s = func(s);
		cnt++;
	}
	cout << cnt << "\n";
	if ( s== "3" || s == "6" || s== "9") cout << "YES";
	else cout << "NO";

	return 0;
}