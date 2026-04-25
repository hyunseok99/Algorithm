#include  <iostream>
#include <cmath>
using namespace std;

void Func(int n,int start,int mid, int end )
{
	if (n == 1)
		cout << start << " "<<end << "\n";
	else
	{
		Func(n - 1, start, end, mid);
		cout << start <<" " << end << "\n";
		Func(n - 1, mid, start, end);
	}

}

int main(void)
{
	int num;
    cin >> num;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout <<(int)pow(2, num)-1 << "\n";

	Func(num, 1, 2, 3);

	return 0; 
}