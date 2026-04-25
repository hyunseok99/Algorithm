#include <iostream>
#include <vector>
using namespace std;

vector<int>v(101);

int main() {
	int n, m, ans;
	ans = 0;
	cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				for (int k = j + 1; k < n; k++) {
					if (ans <= v[i] + v[j] + v[k] && v[i] + v[j] + v[k] <= m) ans = v[i] + v[j] + v[k];
				}
			}
		}
		cout << ans;
		return 0;
}
