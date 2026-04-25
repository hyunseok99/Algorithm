#include <iostream>
#include <deque>
using namespace std;

deque<int> Dn;


int main() {
	int n,m,cnt=0;
	cin >> n>>m;
	
	for(int i = 1; i <= n; i++) { 
		Dn.push_back(i);
	}
	
	while (m--) {
		int ans,idx=0;
		cin >> ans;

		for (int i = 0; i < Dn.size(); i++) {
			if (Dn[i] == ans) {//뽑아야 하는 원소의 인덱스 값
				idx = i;
				break;
			}
		}

		if (idx <= Dn.size()/2) { // 2번째 연산 하는 경우
			for (int i = 0; i < idx; i++) {
				Dn.push_back(Dn.front());
				Dn.pop_front();
				cnt++;
			}
			Dn.pop_front();
		}
		else {
			for (int i = 0; i < Dn.size() - idx;i++) {//3번째 연산 하는 경우
				Dn.push_front(Dn.back());
				Dn.pop_back();
				cnt++;
			}
			Dn.pop_front();
		}
	}
	cout << cnt;
	
}