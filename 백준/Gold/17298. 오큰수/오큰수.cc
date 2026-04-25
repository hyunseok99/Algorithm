#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> s;
vector<int> v;
vector<int> v2(1000001);
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		v.push_back(k);
	}

	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && (s.top() <= v[i])) {
			s.pop();
		}

		if (s.empty()) {
			v2[i] = -1;
		}
		else {
			v2[i] = s.top();
		}
		s.push(v[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << v2[i] << " ";
	}
    return 0;
}

