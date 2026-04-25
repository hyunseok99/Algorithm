#include  <iostream>
using namespace std;

int Func(int k)
{
	if (k == 0)
		return 0;
	if (k == 1)
		return 1;
	return Func(k - 2) + Func(k - 1);
}
int main(void)
{
	int n;
	while (true)
	{
		cin >> n;
		if ((0 <= n) && (n <= 20)) break;
	}

	cout << Func(n) << endl;

	return 0; 
}