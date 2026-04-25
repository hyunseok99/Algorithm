#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <string>
#include <unordered_set>
#include <numeric>
#include <climits>
#include <stack>
#include <map>
#include <set>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
    stack<pair<int,int>> s; // 키, 같은 사람의 수
    long long ans = 0;

	for (int i = 0; i < n; i++) {
		int h;
        cin>>h;
        int cnt = 1; //  같은 사람의 수
        while(!s.empty() && s.top().first < h){
            // 뒤 사람과 짝꿍 가능 
            ans += s.top().second;
            s.pop();
        }
           
        if(!s.empty() && s.top().first == h){
            ans += s.top().second;
            cnt = s.top().second +=1;
            s.pop();
        }
        
        if(!s.empty()){
            // 키큰사람과 본인만 짝
            ans++;
        }
        
        s.push({h, cnt});
	}
	
	cout << ans;
	return 0;
}