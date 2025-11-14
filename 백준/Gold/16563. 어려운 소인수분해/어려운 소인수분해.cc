#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;

// 가장 작은 소인수를 메모제이션 
void printComp(vector<int> &memo, int val) {
	
	while (val > 1) {
		cout << memo[val] << " ";
		val = val / memo[val];
	}

	cout << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin >> n;
	// v[6] -> 2 , v[45] -> 3 v[15] -> 3 이런식 
	vector<int> v(5000001);
	for (int i = 1; i <= 5000000; i++) {
		v[i] = i;
	}

	// 최소 소인수 갱신
	// O(n log(logn)) ~= O(n)
	for (int i = 2; i <= sqrt(5000000); i++) {
		if (v[i] == i) {
			for (int j = i * i; j <= 5000000; j += i) {
				if (v[j] == j) {
					v[j] = i;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		// get function
		int val;
		cin >> val;
		printComp(v, val);
	}
	return 0;
}