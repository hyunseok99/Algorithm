#include <iostream>
using namespace std;



int main(void) {
	int a, b, c, res;
	int arr[10] = { 0, };
	cin >> a >> b >> c;
	res = a * b * c;
	
	while (res != 0) {
		arr[res % 10]++;
		res /= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << arr[i] << endl;

	return 0;
}