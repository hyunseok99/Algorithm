#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<int, string> myMap;
map<string, int> myMap2;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	string str;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		myMap.insert({ i, str });
		myMap2.insert({ str, i });
	}

	for (int i = 0; i < m; i++) {
		cin >> str;

		if (str[0] >= 65 && str[0] <= 90) {
			cout << myMap2[str] << "\n";
		}
		else {
			cout << myMap[stoi(str)] << "\n";
		}		
		
	}

	return 0;

}