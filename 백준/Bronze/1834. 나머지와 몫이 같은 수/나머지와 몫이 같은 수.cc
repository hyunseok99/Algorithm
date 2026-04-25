#include <iostream>
using namespace std;

int main(void)
{
    unsigned long long n;
	unsigned long long sum=0;
	cin >> n;

	for (int i=1;i<n;i++)
	{
		sum += (n * i + i);
	}
	cout << sum<< endl;

	return 0;
}

