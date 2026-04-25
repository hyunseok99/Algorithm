#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <string>
#include <unordered_set>
#include <numeric>
#include <climits>
#include <stack>
#include <map>
#include <set>
using namespace std;

int n,val,val2,ans;

int main() {
	string str,str2;
	stack<char> s;
	string temp = "";
	cin >> str >> str2;

	for (int i = 0; i < str.size(); i++) {
		temp += str[i];
		if (temp.length() >= str2.length()) {
			bool flag = true;
			for (int j = 0; j < str2.length(); j++) {
				if (temp[temp.length() - str2.length() + j] != str2[j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				temp.erase(temp.end() - str2.length(), temp.end());
			}
		}
	}

	if (temp.empty()) {
		cout << "FRULA";
	}
	else {
		cout << temp;
	}

	return 0;
}