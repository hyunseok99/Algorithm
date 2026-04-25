#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, res=-1;
vector<int> arr;

void calc() {
	int total = 0;
	for(int i=0; i<=n-2; i++){
		int j = i+1;
		int val = abs(arr[i] - arr[j]);
		total += val;
	}
	res = max(total, res);
}

void backTracking() {
	do{
		calc();
	}while(next_permutation(arr.begin(),arr.begin()+n));
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin>>tmp;
		arr.push_back(tmp);
	}
    sort(arr.begin(), arr.end());
	backTracking();
	cout << res;
	
	return 0;
}