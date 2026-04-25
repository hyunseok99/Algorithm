#include <iostream>
#include <stack>
using namespace std;

stack<int> arr[7];  // 기타줄 6개
int cnt = 0;

void Calc(int idx,int val, stack<int> *s) {
	if (s[idx].empty() || s[idx].top() < val) { //stack empty or top<val -> push,cnt++
		cnt++;
		s[idx].push(val);
		return;
	}
	else if (s[idx].top() > val) {// 스택 top > val 
		while (s[idx].top() > val) {//pop 했는데도 top>val
			cnt++;
			s[idx].pop();
			if (s[idx].empty()) {//pop 했는데 stack이 비었을 때
				cnt++;
				s[idx].push(val);
				return;
			}
		}
		if (s[idx].top() < val) {//pop 후 top<val
			cnt++;
			s[idx].push(val);
			return;
		}
	}
	else return; //idx,val 같은경우 아무것도 안함
	
}



int main() {
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; i++) { 
		int idx,val;
		cin >>idx>>val; // 줄의번호,프렛 입력받기
		Calc(idx, val, arr); //최소 이동횟수 계산 함수
	}
	cout << cnt;
}