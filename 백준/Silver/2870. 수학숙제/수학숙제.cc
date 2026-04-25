#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
using namespace std;


int n, m, cnt, call;
vector<string> myV;

bool compare(string &x, string&y) {
	if (x.size() == y.size()) return x < y;
	else return x.size() < y.size();
}

int main() {
	cin >> m;
	vector<string> v;

	for(int i = 0; i < m; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	for (int i = 0; i < v.size(); i++) {
		string temp = v[i];
		string num;
		for (int j = 0; j < v[i].length(); j++) {
			if (isdigit(temp[j])) {
				num += temp[j];
			}
			else if(!num.empty()) {
				while (num.length() >= 2 && num[0] == '0') {
					num.erase(0,1);
				}
				myV.push_back(num);
				num = "";
			}
		}
		if (!num.empty()) {
			while (num.length() >= 2 && num[0] == '0') {
				num.erase(0, 1);
			}
			myV.push_back(num);
			num = "";
		}

	}
	
	sort(myV.begin(), myV.end(), compare);
	for (auto k : myV) {
		cout << k << "\n";
	}

	return 0;
	
}