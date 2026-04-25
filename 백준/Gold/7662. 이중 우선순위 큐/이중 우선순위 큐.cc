#include <iostream>
#include <queue>
#include <map>
using namespace std;

priority_queue<int> MaxH;
priority_queue<int, vector<int>, greater<int>> MinH;
map<int, int> check; //동기화 용

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int k,t,val;
	char c;

	cin >>t;
	while (t--) {
		while (!MaxH.empty()) {
			MaxH.pop();
		}
		while (!MinH.empty()) {
			MinH.pop();
		}
		check.clear();

		cin >> k;

		for (int i = 0; i < k; i++) {
			cin >> c >> val;
			if (c == 'I') {
				MaxH.push(val);
				MinH.push(val);
				if (check.count(val) == 0) check[val] = 1;
				else { check[val]++; }
			}
			else if(c == 'D' && val == -1) {
				while (!MinH.empty() && check[MinH.top()] == 0) { //동기화
					MinH.pop();
				}
				if (!MinH.empty()) {
					check[MinH.top()]--;
					MinH.pop();
				}
			}
			else {
				while (!MaxH.empty() && check[MaxH.top()] == 0) { //동기화
					MaxH.pop();
				}
				if (!MaxH.empty()) {
					check[MaxH.top()]--;
					MaxH.pop();
				}
				
			}
			while (!MaxH.empty() && check[MaxH.top()]==0) {
					MaxH.pop();
			}
			while (!MinH.empty() && check[MinH.top()] == 0) {
					MinH.pop();
			}
			
		}

		if (MaxH.empty() || MinH.empty()) { cout << "EMPTY\n"; }
		else {
			cout << MaxH.top() << " " << MinH.top() << "\n";
		}
	}
	return 0;

}