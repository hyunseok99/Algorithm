#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

int main() {
	int n,max=0,cnt=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		s.push(k);
	}

	while(!s.empty()) {
		if (max < s.top()) {
			max = s.top();
			cnt++;
			s.pop();
		}
		else s.pop();
	}
	cout << cnt;
}