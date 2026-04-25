#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;

int func(vector<int> b) {
	sort(b.begin(), b.end());
	if (b[3] - b[1] < 4)
		return b[1] + b[2] + b[3];
	else return -1;
}

int main(){
	
	ios_base::sync_with_stdio(false); cin.tie( NULL);
	int t; cin >> t;
	int reV[10] = { 0, };
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < 5; j++) {
			int x; cin >> x;
			v.push_back(x);
		}
		reV[i] = func(v);
		v.clear();
	
	}


	for (int i = 0; i < t; i++) {
		if( reV[i] == -1) cout << "KIN" << '\n';
		else cout << reV[i] << '\n';
	}

	return 0;
}