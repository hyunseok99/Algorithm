#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

// 해당 스테이지 구매 , 구매 x -> + 누적 힌트 갯수 기록 필요 
int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    int n = cost.size();
    int max_val = 100000 * 17;
    int max_hint = (1 << 17) -1;
    int answer = max_val;
    
    // 스테이지 별 hint 구매시 이용 가능 map
    vector<unordered_map<int,int>> hint_m(n+1);
    for(int i=0; i<hint.size(); i++){
        for(int j=1; j < hint[i].size(); j++){
            hint_m[i+1][hint[i][j]]++;
        }
    }
 
    // dp[stage][binary_hint buy 여부] -> 스테이지 1 ~ 16 -> 2^17-1 
    // dp[stage][011] -> 2^16
    vector<vector<int>> dp(n+1, vector<int>(max_hint+1, max_val));
    
    // worst case: O(16 * 16 * 2^17 ~= 2^25)
    // init: dp[1][0] 초기에는 힌트권 x 
    dp[1][0] = cost[0][0];
    if(max_hint >= 1) {
        dp[1][1] = cost[0][0] + hint[0][0];
    }
    for(int i=2; i<= n; i++){
        // 이전 스테이지가 max_val이 아닌 경우
        for(int j=0; j<=max_hint; j++){
            if(dp[i-1][j] == max_val) continue;
            
            // 이전 스테이지에서 현재 스테이지에 
            int cnt = 0; // 사용 가능 쿠폰 수 
            for(int k=0; k<i-1; k++){ // 1~n-1 stage 구매 여부  
                if((j & (1 << k)) != 0){
                    // (k+1) 마을 힌트 보유중이고 i번 stage에 사용 가능한 힌트 갯수 
                    cnt += hint_m[k+1][i];
                } 
            }
            // case: 쿠폰 구매 x + 쿠폰 구매 o 
            // 할인 쿠폰이 이미 최대 사용 가능 횟수 넘어가면 고정 
            cnt = min(cnt, (int)cost[i-1].size()-1);
            dp[i][j] = min(dp[i][j], dp[i-1][j] + cost[i-1][cnt]);
            int buy_j = j | (1 << (i - 1));
            if(buy_j <= max_hint && !hint[i-1].empty() && i != n){
                // 아니 i==n 일때 hint없는거 대형사고네;;
                dp[i][buy_j] = min(dp[i][buy_j], dp[i-1][j] + cost[i-1][cnt] +hint[i-1][0]);
                
            }
        }
    }
    // dp[n][]중 최소 
    for(int i=0; i<=max_hint; i++){
        answer = min(answer, dp[n][i]);
    }
    return answer;
}

