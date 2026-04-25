#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> v;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, x, y, res=0;
	int start=-1000000001, end= -1000000001;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}


	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		if (v[i].first <= end) end = max(end, v[i].second);
		else {
			res += end - start;
			start = v[i].first;
			end = v[i].second;
		}
	}
	res += end - start;
	cout << res;

	return 0;
}