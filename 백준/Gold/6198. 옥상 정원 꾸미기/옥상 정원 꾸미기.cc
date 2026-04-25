#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n, sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	vector<long long> arr;
	stack<pair<long long, long long>> s;// height, 보이는 건물 수
	for (int i = 0; i < n; i++) {
		long long tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	// idx에 따른 보이는 건물 수 갱신
	// 10 3 7 4 12 2
	// +2 -2 +12 +4 -4 + 7 +3 -3 -7 +10
	// {2,0,1,0,1,0}
	// 4 2 5 1 3
	// +3 +1 -1 -3 +5 +2 -2 +4
	// { 1,0,2,0,0}
	vector<long long> cnt(n); // 보이는 건물
	for (int i = n - 1; i >= 0; i--) {
		long long sum = 0;
		// arr[i]보다 작은 높이 건물은 보여짐 기존에 보이는 건물 + 자기 자신 
		while (!s.empty() && arr[i] > s.top().first) {
			sum += (s.top().second + 1);
			s.pop();
		}
		// arr[i] <= s.top().first 
		cnt[i] = sum;
		s.push({ arr[i], sum });
	}

	// 누적 합
	long long res = 0;
	for (int i = 0; i < cnt.size(); i++) {
		res += cnt[i];
	}

	cout << res;
	return 0;
}