#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <set>
using namespace std;

// N을 사용해서 number를 만드는 최소 사용 갯수  +,-,*,/ 가능 

// dp[x] = {y1, y2, y3 .. } : N을 x번 사용해서 만들 수 있는 수 y집합 


int getDP(int N, int number){
    vector<set<int>> dp(9);
    // 처음에 N을 1~8번 사용한 경우 초기화
    int val = 0;
    for(int i=1; i<=8; i++){
        val = val*10 + N;
        dp[i].insert(val);
    }
    
    
    
    // dp값이 8이하인 경우들로 사칙연산을 통해서 새로운 값 연산
    // 
    for(int i=2; i<=8; i++){
        for(int j=1; j<i; j++){
            int k = i-j;
            for(int n1: dp[j]){
                for(int n2: dp[k]){
                    // + 연산
                    dp[i].insert(n1+n2);
                    // - 연산
                    if(n1 - n2 > 0){
                        dp[i].insert(n1-n2);
                    }
                    // * 연산
                    dp[i].insert(n1*n2);
                    // / 연산
                    if(n2 != 0 && n1/n2 > 0){
                        dp[i].insert(n1/n2);
                    }
                }
            }
        }
    }
    
    for(int i=1; i<=8; i++){
        if(dp[i].count(number)){
            return i;
        }
    }
    return -1;
}

int solution(int N, int number) {
    int answer = getDP(N, number);
    return answer;
}