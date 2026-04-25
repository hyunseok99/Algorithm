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

int k;
char ch[11];
int num[11];
bool flag[11];
vector<string> buffer;
bool check(char x, char y, char op) {
	if (op == '<') {
		if (x < y) return true;
	}
	else {
		if (x > y) return true;
	}
	return false;
}

void bt(int index, string n) {
	if (index == (k + 1)) {
		buffer.push_back(n);
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (flag[i]) continue;
		if (index == 0 || check(n[index - 1], i + '0', ch[index - 1])) {
			flag[i]= true;
			bt(index+1,n+to_string(i));
			flag[i] = false;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> ch[i];
	}
	bt(0, "");
	sort(buffer.begin(), buffer.end());
	cout << buffer.back() << "\n" << buffer[0];
	
	return 0;
}