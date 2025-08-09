#include <iostream>
#include <vector>
using namespace std;

void DFS(int);
vector<int> v[101];
bool B[101];
int cnt = 0;

int main() {
	int n,e;
	cin >> n >> e;
	for (int i = 1; i <= e; i++) {
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	DFS(1);
	cout << cnt;
	return 0;
}

void DFS(int k) {
	B[k] = true;
	for (int i = 0; i <v[k].size(); i++) {
		int val = v[k][i];
		if (!B[val]) {
			DFS(val);
			cnt++;
		}
	}
}