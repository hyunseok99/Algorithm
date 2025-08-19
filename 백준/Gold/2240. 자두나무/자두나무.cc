#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t, w;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> t >> w;
	vector<vector<int>> dp(t+1, vector<int>(w+1));


	// 현재 위치에 자두가 떨어지는 경우 , 떨어지지 않는 경우
	// dp[t][w] = dp[t-1][w] + 1 , dp[t-1][w]
	// 이동 횟수를 추가로 고려해야함
	// dp[t][w] = max(dp[t-1][w], dp[t-1][w-1] )

	// dp[0][0] = 0;
	// dp[1][0] = dp[0][0] +1 or dp[0][0]
	// dp[i][0]은 움직이지 않는 경우
	// 이동 횟수가 짝수이면 위치 1번, 홀수면 2번 
	// 
	for(int i=1; i<=t; i++){
		int tree;
		cin >> tree;
		
		// 움직이지 않는 경우
		if(tree == 1){
			dp[i][0] = dp[i-1][0] + 1;
		}else{
			dp[i][0] = dp[i-1][0];
		}

		// 움직이는 경우
		for(int j=1; j <= w; j++){
			// 현재 나의 위치
			int pos;
			if(j % 2 == 0){
				pos = 1;
			}else{
				pos = 2;
			}
			// i초에 자두를 얻는 경우
			if(tree == pos){
				// i-1초에 1번위치 or i-1초에 2번 위치에서 이동 
				dp[i][j] = max(dp[i-1][j] + 1, dp[i-1][j-1]+1);
			}else{
				// 자두를 못 얻는경우 
				// i초에 2번 위치에 있는 경우
				// i-1초에 1번위치에서 이동 or i-1초에 2번위치에 존재
				dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);
			}
		}

	}

	int res = 0;
	for(int i=0; i<=w; i++){
		res = max(dp[t][i], res);
	}

	cout << res;
	return 0;
}