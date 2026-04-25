#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <set>
#include <map>
using namespace std;

string n;
map<set<string>, bool> check;

void func(int left, int right, string start, set<string> tmp) {
	if (start.length() >= n.size()) {
		if (start == n) check[tmp] = true;
		return;
	}	

	if (left > 0) {
		tmp.insert(n[left - 1] + start);
		func(left - 1, right, n[left - 1] + start, tmp);
		tmp.erase(n[left - 1] + start);
	}

	if (right < n.length()) {
		tmp.insert(start + n[right + 1] );
		func(left, right + 1, start + n[right + 1] , tmp);
		tmp.erase(start + n[right + 1] );
	}
}


int main() {
	cin >> n;
	
	for (int i = 0; i < n.length(); i++) {
		string tmp = "";
		set<string> s_tmp = { tmp + n[i] };
		func(i, i, tmp + n[i], s_tmp);
	}

	cout << check.size();

	return 0;
}