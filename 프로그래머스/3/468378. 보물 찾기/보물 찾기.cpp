#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

extern int excavate(int);

// 이분탐색 worst: logN * 100000
// 이분탐색 + depth 고려 필요 -> ex) [1, 100000, 1] -> idx 0,2를 파는게 확실
// dp[i][j] = i~j 사이에 보물이 있을 때 필요한 worst case의 최소 비용 
int solution(vector<int> depth, int money) {
    // for(int i = 1; i <= depth.size(); i++) 
        // if (excavate(i) == 0) return i;
    int n = depth.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 20000001));
    vector<vector<int>> ans(n+1, vector<int>(n+1)); // 다음에 팔 최적 위치 
    
    // 보물 위치 k -> 총 발굴 비용: depth[k] + max(dp[i][k-1], dp[k+1][j])
    // x번을 파고 -> 좌, 우

    // dp[0][1] 차이가 1인 경우비용은 dp[0] + dp[1]
    // ex) dp[0][2] = 0번을 파고 나서 dp[1][2] or 1번을 파고 dp[0], dp[2] 중 작은 값, 2번을 파고 dp[0][1]
    // 0~w 까지 갱신 
    // ex)dp[0][3]: dp[0][0] + dp[1][3], dp[1][1] + max(dp[0][0], dp[2][3])
    for(int i=1; i<=n; i++){
        dp[i][i] = depth[i-1];
        ans[i][i] = i;
    }
    for(int len = 1; len < n; len++){
        for(int i=1; i+len<=n; i++){
            for(int pivot = i; pivot <= i+len; pivot++){
                int left = (pivot - 1 >= i) ? dp[i][pivot-1] : 0;
                int right = (pivot + 1 <= i+len) ? dp[pivot+1][i+len] : 0;
                int worst = depth[pivot-1] + max(left, right);
                
                if(worst < dp[i][i+len]){
                    dp[i][i+len] = worst;
                    ans[i][i+len] = pivot;
                }
            }
        }
    }
    
    // pivot을 통한 최적 이분 탐색 
    int left = 1;
    int right = n;
    while(left <= right){
        if(left == right){
            //answer
            excavate(left);
            return left;
        }
        int mid = ans[left][right];
        int res = excavate(mid);
        if(res == 0 ){
            return mid;
        }
        if(res == -1) {
            right = mid-1;
        }
        if(res == 1){
            left = mid + 1;
        }
    }
    return 0;
}