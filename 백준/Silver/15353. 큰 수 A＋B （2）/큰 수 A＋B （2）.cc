#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <string>
#include <unordered_set>
#include <numeric>
#include <climits>
#include <stack>
#include <map>
#include <set>
using namespace std;

int n,l,cnt,res=0;
int arrA[10001];
int arrB[10001];
vector<int> v;

int main() {
	string a,b;
	cin >> a >> b;
	if (a.size() < b.size()) {
		string temp = a;
		a = b;
		b = temp;
	}
	for (int i = 0; i < a.size(); i++) {
		arrA[i + 1] = a[i] - '0';
	}
	for (int i = 0; i < b.size(); i++) {
		arrB[i + 1 + a.size() - b.size()] = b[i] - '0';
	}
	for (int i = a.size(); i > 0; i--) {
		res = arrA[i] + arrB[i];
		if (res >= 10) {
			arrA[i - 1] += 1;
			res -= 10;
		}
		v.push_back(res);
	}
	if (arrA[0] != 0) v.push_back(1);
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i];
	}
	return 0;



}