#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int m, n;
long long l;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> n >> l;

	int cnt = 0;

	vector<long long> shoot;
	// 입력 받고 탐지 가능한 값 갱신 
	for (int i = 0; i < m; i++) {
		long long shootPos;
		cin >> shootPos;
		shoot.push_back(shootPos);
	}
	sort(shoot.begin(), shoot.end());

	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		long long start = 0;
		long long end = m - 1;
		bool flag = false;

		// 첫 사대 기준 왼쪽 
		if (x < shoot[start]) {
			if (shoot[start] - x <= l) {
				if (y <= l - (shoot[start] - x)) {
					cnt++;
				}
			}
		}else if (x > shoot[end]) { // 마지막 사대 오른쪽
			if (x - shoot[end] <= l) {
				if (y <= l - (x - shoot[end])) {
					cnt++;
				}
			}
		}
		else { // 사이의 경우
			while (start < end) {
				long long mid = (start + end) / 2;
				if (start == mid) break;
				if (shoot[mid] > x) {
					end = mid;
				}
				else if (shoot[mid] < x) {
					start = mid;
				}
				else if (shoot[mid] == x) {
					flag = true;
					break;
				}
			}

			if (flag) {
				if (y <= l) cnt++;
			}
			else {
				if (x - shoot[start] <= shoot[end] - x) {
					if (x - shoot[start] <= l) {
						if (y <= l - (x - shoot[start])) {
							cnt++;
						}
					}
				}
				else {
					if (shoot[end] - x <= l) {
						if (y <= l - (shoot[end] - x)) {
							cnt++;
						}
					}
				}
			}
		}
		
	}

	cout << cnt;

	return 0;
}
