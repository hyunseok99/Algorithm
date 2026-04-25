#include <iostream>
#include <string>
using namespace std;

int main() {
	int cnt = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		cnt++;
		if (str[i] == '-' || str[i] == '=') {
			cnt--;
		}
		else if (str[i]=='n'&& str[i+1]=='j'||str[i]=='l'&&str[i+1]=='j') cnt--;
		else if (str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=') cnt--;
	}
	cout << cnt;
}
