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

int n;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cur = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "add") {
			int x;
			cin >> x;
			cur = cur | (1 << x);
		}
		else if (str == "check") {
			int x;
			cin >> x;
			if (cur & (1 << x)) {
				cout << "1"<<"\n";
			}
			else {
				cout << "0"<<"\n";
			}
		}
		else if (str == "remove") {
			int x;
			cin >> x;
			cur = cur & ~(1 << x);
		}
		else if (str == "toggle") {
			int x;
			cin >> x;
			cur = cur ^ (1 << x);
		}
		else if (str == "all") {
			cur = (1 << 21) - 1;
		}
		else if (str == "empty") {
			cur = 0;
		}
	}

	return 0;
}