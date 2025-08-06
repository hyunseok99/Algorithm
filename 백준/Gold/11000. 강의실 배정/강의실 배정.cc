#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <utility>
using namespace std;

int n;

struct comp{
	bool operator()(pair<long long, long long> a, pair<long long, long long> b) {
		// true면 swap
		return a.second > b.second;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	vector<pair<long long, long long>> time;

	for (int i = 0; i < n; i++) {
		long long s, t;
		cin >> s >> t;
		time.push_back({ s,t });
	}
	sort(time.begin(), time.end());

	// 강의실 시간을 저장할 q -> 종료시간을 기준으로 min heap
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, comp> q;

	q.push(time[0]);
	for (int i = 1; i < n; i++) {
		long long start = time[i].first;
		long long roomEnd = q.top().second;
		// 기존 강의실 이용 가능
		if (start >= roomEnd) {
			q.pop();
		}

		// 강의실 시간 갱신 
		q.push(time[i]);
	}

	cout << q.size();

	return 0;
}