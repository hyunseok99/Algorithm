#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <string>
#include <unordered_set>
#include <numeric>
#include <climits>
#include <stack>
#include <map>
#include <set>
using namespace std;

int n,m,cnt=0;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	vector<int> my_vec;
	set<int> my_set;
	map<int, int> my_map;
	for (int i = 0; i < n; i++) {
		cin >> m;
		my_vec.push_back(m);
		my_set.insert(m);
	}

	for (auto k = my_set.begin(); k != my_set.end(); k++) {
		my_map[*k] = cnt;
		cnt++;
	}
	
	for (int i = 0; i < my_vec.size(); i++) {
		cout << my_map[my_vec[i]] << " ";
	}

	return 0;
}