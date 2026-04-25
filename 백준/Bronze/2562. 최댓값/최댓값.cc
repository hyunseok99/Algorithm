#include <iostream>
using namespace std;

int main(void)
{
	int max = 0;
	int array[9];
	int k = 0;

	for (int i = 0; i < 9; i++)
	{
		while (true)
		{
			cin >> array[i];
			if ((0 < array[i]) && (array[i] < 100)) break;
			cout << "다시입력" << endl;
		}
		if (max < array[i])
		{
			max = array[i];
			k = i+1;
		}
	}

	cout << max << endl << k;

	return 0;
}