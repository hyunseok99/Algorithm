#include <iostream>
#include <algorithm>
using namespace std;

int A[100001];
int B[100001];

int main() {
	int n,m;
	cin >> n;
	for (int i=0; i < n; i++) {
		cin >> A[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}
	sort(A, A+n);
	for (int i = 0; i < m; i++) {
		if (binary_search(A, A + n, B[i])) cout << "1\n";
		else cout << "0\n";
	}
}