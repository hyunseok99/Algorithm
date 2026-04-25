#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, less<int>> q;
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
	int n,k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k != 0) {
			q.push(k);
		}
		else {
			if(q.empty()){
				cout << "0" << "\n";
			}
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
	}
}