#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int n;

int main() {
	cin >> n;
	vector<pair<int,int>> line;
	vector<int> seq;
	// 연결된 전깃줄 초기화 
	for(int i = 0; i < n; i++){
		int a,b;
		cin >> a >> b;
		line.push_back({a, b});
	}
	// 전깃줄 순서대로 정렬
	sort(line.begin(), line.end());

	// 증가하는 최장의 seq 길이를 구하자 -> 총 전깃줄 - 크기 = 답
	for(int i=0; i<n; i++){
		int b = line[i].second;
		// 연결될 전깃줄의 가능 위치 
		auto iter = lower_bound(seq.begin(), seq.end(), b);

		
		if(iter == seq.end()){ // LIS 증가 
			seq.push_back(b);
		}else{
			// 사이에 들어갈 수 있으면 LIS 길이 유지에, 값만 갱신 
			*iter = b;			
		}
	}

	// 제거해야 할 전깃줄 수
	cout << n - seq.size();
	
	return 0;
}
