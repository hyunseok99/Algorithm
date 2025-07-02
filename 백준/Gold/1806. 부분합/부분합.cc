#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
long long s;

void getSum(vector<int> &sequence){
	long long sum = 0;
	int cnt = n + 1; 
	int start = 0;
	int last = 0;
	
	while(1){
		// 합이 s 이상이면 오른쪽으로 이동 
		if ( sum >= s ){
			cnt = min(cnt, last-start);
			sum = sum - sequence[start];
			start++;
		}else if( last == n){
			// 더이상 불가
			break;
		}else{
			// s보다 작으면 연속 수열 늘리기
			sum += sequence[last];
			last++;
		}
	}

	if(cnt == n+1){
		cout << 0;
	}else{
		cout << cnt;
	}
	
	return;
}


int main() {
	cin >> n >> s;
	vector<int> sequence(n);

	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	}

	getSum(sequence);
	
	return 0;
}