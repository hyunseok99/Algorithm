#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


int main() {
	
	ios_base::sync_with_stdio(false); cin.tie( NULL);

	string str;
	cin >> str;
	sort(str.begin(), str.end());
	reverse(str.begin(), str.end());
	cout << str;

	return 0;
}