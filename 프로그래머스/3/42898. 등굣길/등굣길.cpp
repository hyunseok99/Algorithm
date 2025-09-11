#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

// 현재 위치에 도달하는 방법: 이전의 위치에서 오른쪽 이동 or 이전 위치에서 아래쪽 이동 

// dp[n][m] = ans 

int divisor = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    // 초기화
    dp[1][1] = 1;
    for(int i=0; i<puddles.size(); i++){
        dp[puddles[i][1]][puddles[i][0]] = -2;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(dp[i][j] == -2) continue;
            if(dp[i-1][j] != -2){
                dp[i][j] += dp[i-1][j];
            }
            if(dp[i][j-1] != -2){
                dp[i][j] += dp[i][j-1];
            }
            dp[i][j] %= divisor;
        }
    }
    
    int answer = dp[n][m];
    return answer;
}