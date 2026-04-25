#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char stc[101];
	const char* ptr = stc;
	cin >> stc;
	cout << strlen(ptr) << endl;

	return 0;
}