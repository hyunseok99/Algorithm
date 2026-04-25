#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;


map< int, pair<int,int> > myMap;


struct customMap {
	int key;
	pair <int, int> value;
	customMap(int k, pair<int,int> v) {
		key = k;
		value = v;
	}
};

bool cmp(customMap a, customMap b) {
	if (a.value.second == b.value.second) {
		return a.value.first < b.value.first;
	}
	else {
		return a.value.second > b.value.second; 
	}
}

int main() {
	int n, c,k;
	int max = 0;
	int order = 1;
	vector<customMap> v;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (myMap[k].second == 0) {
			myMap[k] = make_pair(order, 1);
			order++;
		}
		else {
			myMap[k].second++;
		}
	}

	for (auto s : myMap) {
		customMap x(s.first, s.second);
		v.push_back(x);
	}

	sort(v.begin(), v.end(), cmp);


	for (auto s : v) {
		for (int i = 0; i < s.value.second; i++) {
			cout << s.key << " ";
		}
	}
	return 0;
}

