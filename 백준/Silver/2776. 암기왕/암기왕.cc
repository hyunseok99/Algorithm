#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int	t, n, m;
	cin >> t;
	for (int i = 0; i < t; i++) {
		unordered_map<int, bool> note_1;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (note_1[a] == NULL) {
				note_1[a] = true;
			}
		}
		cin >> m;
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			if (note_1[a] == true) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
	return 0;
}