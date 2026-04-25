#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <set>
#include <map>
#include <numeric>
using namespace std;

// Ax + Bsinx = c
double a, b, c;

int n = 50; // 0,1,2, ... n

// Ax -B <= C <= Ax + B
// (C-B)/A <= x <= (C+B) / A   [0, 100000]  
//
long double my_sin(long double x) {
	long double res = x;
	long double x_2 = -x * x;
	for(int i = 3; i < n; i += 2) {
		x = (x * x_2) / (i * (i - 1));
		res += x;
	}

	return res;
}


int main() {
	cin >> a >> b >> c;
	double left = 0;
	double right = 100000;
	double mid = 0;
	int cnt = 50000;
	while (left < right && cnt--) {
		mid = (left + right) / 2;
		long double var = (c - (b * sin(mid))) / a;
		if (mid > var) right = mid;
		else if (mid < var) left = mid + 0.000000001;
	}
	cout.precision(19);
	cout << mid;

	return 0;
}