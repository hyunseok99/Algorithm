#include <iostream>
#include <set>
using namespace std;

set<int> M;
set<int>::iterator iter;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k; 
		cin >> k;
		M.insert(k);
	}

	for (iter = M.begin(); iter!=M.end();iter++) {
		cout << *iter << endl;
	}
	
	
	return 0;
}
