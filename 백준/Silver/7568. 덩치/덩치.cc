#include <iostream>
using namespace std;

int main(void)
{
	int n;
	int arr[100][2] = {};
	int grad[100];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
		grad[i] = 1;
		
	}

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
				grad[i]++;
		}
	}
	for (int i = 0; i < n; i++)
		cout << grad[i] << " ";

	return 0;
}
