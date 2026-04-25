#include <iostream>
using namespace std;

void Fact(int k)
{
	int res=1;
	for (int n = 1; n <= k; n++)
		res *= n;
	cout << res;
}
 
int main()
{
	int N;
	cin >> N;
	while (N<0 || N>13)
	{	
		cin >> N;
	}

	if (N == 0)
	{
		cout << 1 << endl;
	}
	else Fact(N);
	
	return 0;
}