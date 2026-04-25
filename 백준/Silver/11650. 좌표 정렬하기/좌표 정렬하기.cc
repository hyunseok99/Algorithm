#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
	int x, y;
};

bool compare(Point  &m, Point &n) {
	if (m.x == n.x) return m.y < n.y;
	else return m.x < n.x;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	Point p[100001];

	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	sort(p, p + n, compare);
	for (int i = 0; i < n; i++) {
		cout << p[i].x <<" "<< p[i].y << '\n';
	}
	return 0;
}