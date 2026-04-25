#include<iostream>
#include<algorithm>
using namespace std;


int main() {
	
	ios_base::sync_with_stdio(false); cin.tie( NULL);
	int arr[20];
	for (int i = 0; i < 20; i++) {
		int x; cin >> x;
		arr[i] = x;
	}
	
	sort(arr, arr+10);
	sort(arr+10, arr+20);
	
	cout << arr[9] + arr[8] + arr[7] << " " << arr[19] + arr[18] + arr[17];
	
	return 0;
}