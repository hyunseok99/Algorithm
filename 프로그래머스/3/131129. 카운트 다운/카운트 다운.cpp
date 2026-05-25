#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// 1~20

vector<int> solution(int target) {
    vector<int> answer;
    // O(n^2)
    // dp[val] = {turn, s or bull cnt} :  idx <= target, cnt <= target
    // dp[target] -> dp[0]
    int max_val = target+1;
    vector<pair<int,int>> dp(target+1, {max_val,-1});
    
    // dp init (while <= 60)
    for(int i=1; i<=60; i++){
        if(i > target) break;

    }
    
    // dp[i] = max(dp[j] + dp[i-j]) 
    for(int i = 1; i <= target; i++){
        if(i <= 20){
            dp[i] = {1,1};
        }else if(i == 50){
            dp[i] = {1,1};
        }else if(i % 2 == 0 && i <= 40){
            dp[i] = {1,0};
        }else if(i % 3 == 0 && i <= 60){
            dp[i] = {1,0};
        }else{
            for(int j = 1; j <= 60; j++){
                if(i < j) break;
                int turn = dp[j].first + dp[i-j].first;
                int cnt = dp[j].second + dp[i-j].second;

                // 기존 턴보다 적거나, 턴 동일에 b,single cnt 합이 크면 갱신
                if(turn < dp[i].first){
                    dp[i] = {turn, cnt};
                }else if(turn == dp[i].first && cnt > dp[i].second){
                    dp[i] = {turn, cnt};
                }
            }
        }
    }
    
    // answer 
    answer.push_back(dp[target].first);
    answer.push_back(dp[target].second);
    
    return answer;
}