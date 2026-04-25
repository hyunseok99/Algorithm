#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int Rev(int n)
{
	string stc = to_string(n);
	reverse(stc.begin(), stc.end());
	return atoi(stc.c_str());
}
int main(void)
{
	int a, b;
	cin >> a >> b;
	cout << Rev(Rev(a) + Rev(b)) << endl;

	return 0;
}

