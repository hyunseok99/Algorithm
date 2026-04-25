#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool compare(const string& a, const string& b) {
	if (a.length() != b.length()) return a.length() < b.length();
	else return a < b;
}

string str[20001];

int main() {
	
	ios_base::sync_with_stdio(false); cin.tie( NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	sort(str,str+n,compare);
	
	for (int i = 0; i < n; i++) {
		if(str[i] != str[i+1]) cout << str[i] << '\n';
	}

	return 0;
}