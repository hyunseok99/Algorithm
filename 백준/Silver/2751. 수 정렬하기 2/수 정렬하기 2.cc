#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v;
int main() {
	
	ios_base::sync_with_stdio(false); cin.tie( NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		int x; cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.begin()+n);
	
	for (auto& k : v) {
		cout << k << '\n';
	}
	return 0;
}