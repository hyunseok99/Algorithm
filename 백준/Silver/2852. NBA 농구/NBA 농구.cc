#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <set>
using namespace std;


int n, m, tim, cnt=1;
int arr[2];
int res[2];

int main() {

	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int k, min, sec;
		string str;
		cin >> k >> str;
		min = stoi(str.substr(0, 2));
		sec = stoi(str.substr(3, 2));
		if (arr[0] > arr[1]) {
			res[0] = res[0] + (min * 60) + sec - tim;
		}
		else if (arr[0] < arr[1]) {
			res[1] = res[1] + (min * 60) + sec - tim;
		}
		if (k == 1) arr[0]++;
		else arr[1]++;
		tim = (min * 60) + sec;
	}

	if (arr[0] > arr[1]) res[0] = res[0] + (48 * 60) - tim;
	else if (arr[0] < arr[1]) res[1] = res[1] + (48 * 60) - tim;
	
	printf("%02d:%02d\n", res[0] / 60, res[0] % 60);
	printf("%02d:%02d\n", res[1] / 60, res[1] % 60);

	return 0;
}