#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	stack<int> s;
	vector<char> v;
	int n; 
	cin >> n;
	int num=1;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		while (num <= k) {
			s.push(num);
			num += 1;
			v.push_back('+');	
		}

		if (s.top() == k) {
			s.pop();
			v.push_back('-');
		}
		else {
			cout << "NO" << "\n";
				return 0;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	return 0;
}