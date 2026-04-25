#include <iostream>
using namespace std;

int main(void)
{
	int a;
	int b;
	int height;
	int day = 1;


	while (true)
	{
		cin >> a >> b >> height;
		if ((1 <= b) && (b < a) && (a <= height) && (height <= 1000000000)) break;
	}

	day += (height - a) / (a - b);
	if (((height - a) % (a - b)) != 0)
		day++;
	if (a >= height)
		cout<<"1";
	else
		cout << day;

	return 0;
}