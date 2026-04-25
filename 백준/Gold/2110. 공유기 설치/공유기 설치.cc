#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <limits>
using namespace std;

vector<int> v;
vector<int> dist;
int N, C;
int result = -1;


int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	
	int start = 1; 
	int end = v[N - 1] - v[0];

	while (start <= end){
		int mid = (start + end) / 2;
		int last = v[0];
		int cnt = 1;
		
		for (int i = 1; i < N; i++) {
			if (v[i] - last >= mid) {
				cnt++;
				last = v[i];
			}
		}

		if (cnt >= C) {
			result = max(result, mid);
			start = mid + 1;
		}
		else end = mid - 1;

	}

	cout << result;
	return 0;
}