#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> myMap;

int main() {
	int n, t, index;
	string str;
	map<string, int>::iterator iter;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int result = 1;
		cin >> n;
		cin.ignore();
		for (int j = 0; j < n; j++) {
			getline(cin, str,'\n');
			index = str.find(" ");
			str = str.substr(index + 1);
			if (myMap[str] == false) {
				myMap[str] = 1;
			}
			else {
				myMap[str] += 1;
			}
		}
		for (auto iter = myMap.begin(); iter != myMap.end(); iter++) {
			result *= (iter->second + 1);
		}
		cout << result - 1 << "\n";
		myMap.clear();
	}
	return 0;

}