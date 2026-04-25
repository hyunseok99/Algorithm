#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <stack>
using namespace std;

int n;

struct tower{
	int height;
	int ans = 0;
	int leftTop = -1;
	int rightTop = -1;
};

void move(vector<tower> &v, stack<int> &leftSee, stack<int> &rightSee){
	// 왼쪽에 볼 수 있는 경우
	for(int i=2; i <= n; i++){
		if(v[i].height < v[i-1].height){
			// 현재 빌딩이 이전 빌딩 보다  작은 경우
			leftSee.push(i-1);
		}else{
			// 현재 빌딩이 이전 빌딩 보다 큰 경우 
			// 이전에 보이던 것 중 현재 빌딩보다 작거낙 같은것 제외 
			while(!leftSee.empty() && (v[leftSee.top()].height <= v[i].height)){
				leftSee.pop();
			}
		}
		v[i].ans += leftSee.size();
		if(!leftSee.empty()){
			v[i].leftTop = leftSee.top();
		}
	}

	// 오른쪽에 볼 수 있는 경우 
	for(int i = n-1;  i >= 1; i--){
		// 현재 빌딩이 오른쪽 빌딩 보다 작은 경우
		if(v[i].height < v[i+1].height){
			rightSee.push(i+1);
		} else{
			// 현재 빌딩이 오른쪽 빌딩 보다 큰 경우
			// 이전에 보이던 것 중 현재보다 작거나 같은것 제외 
			while(!rightSee.empty()&&(v[rightSee.top()].height <= v[i].height)){
				rightSee.pop();
			}
		}
		v[i].ans += rightSee.size();
		if(!rightSee.empty()){
			v[i].rightTop = rightSee.top();
		}
	}
	
}

void getRes(vector<tower> &v){
	for(int i=1; i<=n; i++){
		if(v[i].ans == 0){
			cout << 0 << "\n";
		}else{
			if(v[i].leftTop == -1){
				cout << v[i].ans << " " << v[i].rightTop << "\n";
			}else if(v[i].rightTop == -1){
				cout << v[i].ans << " " << v[i].leftTop << "\n";
			}else{
				if(abs(i-v[i].leftTop) <= abs(i-v[i].rightTop)){
					cout << v[i].ans << " " << v[i].leftTop << "\n";
				}else{
					cout << v[i].ans << " " << v[i].rightTop << "\n";
				}
			}
		}
	}
}


int main() {
	cin >> n;
	vector<tower> v(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i].height;
	}

	// 왼쪽으로 보이는 빌딩, 오른쪽으로 보이는 빌딩 
	stack<int> leftSee;
	stack<int> rightSee;
	
	move(v, leftSee, rightSee);
	
	getRes(v);
	
	return 0;
}