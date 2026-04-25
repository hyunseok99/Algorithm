#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int A, B, C;

long long int myFun(long long int);

int main() {
	cin >> A >> B >> C;
	cout << myFun(B);

	return 0;
}

long long int myFun(long long int b) {
	if (b == 1) return A % C;
	long long t = myFun(b / 2) % C;
	if (b % 2 == 0) return t * t % C;
	else return t * t % C * A % C;
}