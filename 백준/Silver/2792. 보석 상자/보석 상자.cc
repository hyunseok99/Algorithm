#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits>
using namespace std;


vector<int> v;

int main() {
	int n, m;
	int cnt = 0, idx =0, left=1, right=0 ;

	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		v.push_back(t);
		if (right < t) right= t;

	}


	while (left <= right) {
		cnt = 0;
		int jeal = (left + right) / 2;

		for (int i = 0; i < v.size(); i++) {
			if (v[i] % jeal != 0) ++cnt;
			cnt += v[i] / jeal;
		}

		if (cnt > n) left = jeal+1;
		else {
			idx = jeal;
			right = jeal-1;
			
		}
	}

	cout << idx;
	
}

