#include <iostream>
using namespace std;

int GetNum(int floor, int room) {
	if (floor == 0) return room;
	if (room == 1) return 1;
	else return (GetNum(floor - 1, room) + GetNum(floor, room - 1));
}

int main(void) {
	int T;
	int n;
	int k;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> k >>n;
		cout << GetNum(k, n) << endl;
	}
	return 0;
}