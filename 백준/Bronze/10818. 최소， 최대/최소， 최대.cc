#include  <iostream>
using namespace std;

int main(void)
{
	int n;
	int min = 1000000;
	int max = -1000000;
	int array[1000001];

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
		if (max < array[i]) max = array[i];
		if (min > array[i]) min = array[i];
	}

	cout << min << "\n" << max << endl;

	return 0; 
}