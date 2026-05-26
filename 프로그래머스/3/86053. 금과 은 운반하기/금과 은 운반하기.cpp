#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;

// 최적을 생각해야 함 
// 병렬적으로 작업 가능을 고려 + 왕복 vs 편도 비교 필요 
// time 기준으로 max 운송을 선택하는 방식 
// 특정 t 시간안에 목표 달성 가능한지를 log t 
// 처음 이용: 편도만 고려 이후에는 왕복 -> 해당 마을 이용 이미 했는지 여부 고려 필요 10^5
bool isAns(ll time, int n, int a, int b, vector<int> &g, vector<int> &s, vector<int> &w, vector<int> &t);

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    int n = g.size();  // 도시 수 [0, n)
    // worst case: 2*10^5*10^9 ~= 2*10^14
    ll left = 0; 
    ll right = pow(10,15);
    answer = right;
    
    while(left <= right){
        ll mid = (left+right)/2;
        if(isAns(mid, n, a, b, g, s, w, t)){
            answer = min(answer, mid);
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    
    return answer;
}

// ll time: mid, int n: size of city  
bool isAns(ll time, int n, int a, int b, vector<int> &g, vector<int> &s, vector<int> &w, vector<int> &t){
    // time 시간 안에 a,b 달성 가능 여부 
    // t[i] + 2*t[i]*y <= time 
    // 최대 gold , 최대 silver 사이에서 가능 
    ll tot_g = 0;
    ll tot_s = 0;
    ll tot_w = 0;
    for(int i=0; i<n; i++){
        ll cnt = time / (2*t[i]);
        ll remain = time % (2*t[i]);
        if(remain >= t[i]){
            cnt++; // 첫 편도 이동 추가 
        }
        ll max_w = w[i] * cnt;
        tot_g += min((ll)g[i], max_w); // 금만 옮기는 경우 
        tot_s += min((ll)s[i], max_w); // 은만 옮기는 경우
        tot_w += min((ll)(g[i] + s[i]), max_w); // 금+은 최대 옮기는 경우
    }
    if(a <= tot_g && b <= tot_s && tot_w >= (a+b)){
        return true;
    }
    return false;
}