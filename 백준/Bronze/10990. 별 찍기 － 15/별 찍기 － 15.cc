#include<iostream>;
using namespace std;

void Func(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			cout <<" ";
		}
		cout << "*";
		for (int j = 0; j < 2 * i - 1; j++)
		{
			cout <<" ";
		}
		 if(i!=0) cout <<"*";
		 cout << endl;
	}
}

int main(void)
{
	int s;
	cin >> s;
	Func(s);

	return 0;
}
	
