#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, string>addr;

int main() {
	cin.tie(NULL);
	int n, m;
	int pos = 0;
	string s1, s2;
	cin >> n >> m;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, s1);
		pos = s1.find(' ');
		s2=s1.substr(pos+1, s1.length());
		s1 = s1.substr(0, pos);
		addr[s1] = s2;
	}
	for (int i = 0; i < m; i++) {
		getline(cin, s1);
		cout << addr[s1] << "\n";
	}
	return 0;
}
