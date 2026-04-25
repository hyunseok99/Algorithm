#include <iostream>
using namespace std;

int main(void)
{
	int a;
	int b;
	int c = 1;
	int sum = 0;
	int arr[1001];
	cin >> a >> b;
	for (int i = 1; i < 1001; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			arr[c] = i;
			if (c > 1000) break;
			c++;
		}
	}

	for (int i = a; i <= b; i++)
	{
		sum += arr[i];
	}

	cout << sum;

	return 0;
}

