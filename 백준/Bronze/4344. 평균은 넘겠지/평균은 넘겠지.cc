#include <iostream>
using namespace std;

int main(void) {
	int c;
	cin >> c;

	for (int i = 0; i < c; i++) {
		int n;
		int sum = 0;
		int count = 0;
		cin >> n;
		int* score = new int[n];

		for (int j = 0; j < n; j++) {
			cin >> score[j];
			sum += score[j];
		}
		for (int j = 0; j < n; j++) {
			if (score[j] > (double)sum / n)
				count++;
		}
		cout << fixed;
		cout.precision(3);
		cout << (double)count / n * 100 << "%" << endl;
	}
	
	return 0;
}