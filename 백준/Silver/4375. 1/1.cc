#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#define N 200
using namespace std;


int n;

int main() {

	while (cin >> n) {
		int t = 1;
		int cnt = 1;

		while (1) {
			if (t % n == 0) {
				break;
			}
			else {
				cnt++;
				t = t * 10 + 1;
				t = t % n;
			}
		}
		cout << cnt<<"\n";
	}
}