#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n, m;

void printSequence(int , vector<bool> &);

// my_map[3] = 4,7 -> 4,7은 3 왼쪽에 존재해야 함 
unordered_map<int, vector<int>> my_map;
int main() {
	cin >> n >> m;
	vector<bool> flag(n + 1, false);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		my_map[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!flag[i]) {
			printSequence(i, flag);
		}
	}
	return 0;
}

// 6  4
// 4 6
// 5 6
// 3 5
// 1 3
// 1 3 4 5 6  + 2
void printSequence(int val, vector<bool> &flag){
	if (my_map[val].size() >= 1) {
		for (int n : my_map[val]) {
			if (!flag[n]) {
				printSequence(n, flag);
			}
		}
	}
	if (!flag[val]) {
		flag[val] = true;
		cout << val << " ";
	}

}