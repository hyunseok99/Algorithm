import java.util.*;
import java.io.*;
// 알아야 하는 정보: 계단수 여부 + N자리까지 구성된 수
// 길이가 N인 계단수 -> 길이가 N-1인 계단수
// dp\[현재 누적 자리]\[끝 자릿값]\[현재까지 포함되어 있는 조건]
// N자리까지 계단수를 찾으면서 -> 0~9까지를 포함하는 경우의 답을 구해
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	int n;
	long [][][] dp;
	int divisor = 1000000000; // 10억
	long answer = 0;
	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		// 0~9가 포함되어 있음을 어떻게? 2^0 , 2^1 , 2^2 지수로 & 연산
		// dp[0~n][0~9][0~2^10-1] ->
		int condition = (int)Math.pow(2,10)-1;
		dp = new long[n+1][10][condition+1];
		// 12
		// 10 2+1
		// dp init: 처음 시작은 1~9 가능
		for(int i=1; i<=9; i++){
			dp[1][i][1 << i] = 1;
		}
		// O(n * 10 * 2^10) ~= 100만
		for(int i=1; i<n; i++){
			for(int j=0; j<=9; j++){
				for(int k=0; k<= condition; k++){
					if(dp[i][j][k] != 0){
						// 다음 계단수 만들기
						dp[i][j][k] %= divisor;
						int next = j+1;
						int bef = j-1;
						if(next <= 9){
							if((k & (1 << next)) == 0) {
								// 이미 해당 자리의 수가 포함x 경우
								dp[i+1][j+1][k+(1 << next)] += dp[i][j][k];
							}else{
								dp[i+1][j+1][k] += dp[i][j][k];

							}
						}
						if(bef >= 0){
							if((k & (1 << bef)) == 0){
								dp[i+1][j-1][k+(1 << bef)] += dp[i][j][k];
							}else{
								dp[i+1][j-1][k] += dp[i][j][k];
							}
						}
					}
				}
			}
		}
		// 9876543210
		// 자릿수가 n이며 0~9 모두 포함
		for(int i=0; i<=9; i++){
			answer += (dp[n][i][condition] % divisor);
			answer %= divisor;
		}
		//  9 8 7 6 5 4 3 2 1 0
		// 1
		bw.write(answer+ " ");
		bw.flush();
	}


	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}

