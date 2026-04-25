	#include <iostream>
	#include <cmath>
	#include <vector>
	#include <queue>

	using namespace std;

	vector<pair<int,int>> v;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

	int main() {
		int n, l, start, end, len = 0, second = 0, last = 0, cnt = 0, tmp=0;
		cin >> n >> l;
		for (int i = 0; i < n; i++) {
			cin >> start >> end;
			pq.push({ start, end });
		}
	
		for (; !pq.empty(); pq.pop()) {
			if (pq.top().first > len) {
				len = pq.top().first;
			}
			while (len < pq.top().second) {
				len += l;
				cnt++;
			}
		}
		cout << cnt;
		return 0;
	}