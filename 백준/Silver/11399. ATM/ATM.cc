#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int *arr;
multiset<int> M;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,sum=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		M.insert(k);
	}

	int res = 0;
	for (auto iter = M.begin(); iter != M.end(); iter++)
	{
		res += ((*iter) * n);
			n--;
	}

	cout << res;
	
	return 0;
}
