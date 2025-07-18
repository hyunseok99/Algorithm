#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;

priority_queue<int> q1;
priority_queue<int, vector<int>, greater<int>> q2;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	int leftTop = -1;
	int rightTop = -1;

	// i번째 삽입
	for (int i = 1; i <= n; i++) {
		int m;
		cin >> m;

		if (i % 2 == 1) {
			q1.push(m);
		}
		else {
			q2.push(m);
		}

		if (i >= 2) {
			leftTop = q1.top();
			rightTop = q2.top();
			if (leftTop > rightTop) {
				q1.pop();
				q2.pop();
				q1.push(rightTop);
				q2.push(leftTop);
			}
		}

		cout << q1.top() << "\n";
	}

	return 0;
}