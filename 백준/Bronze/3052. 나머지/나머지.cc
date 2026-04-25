#include <iostream>
#include <cstring>

using namespace std;


int main(void)
{
	int arr[42] = { 0, };
	int num;
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> num;
		if (arr[num % 42] == 0)
		{
			arr[num % 42]++;
			count++;
		}
	}
	cout << count;
	return 0;
}

