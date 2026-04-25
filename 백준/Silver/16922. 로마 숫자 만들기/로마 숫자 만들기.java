
import java.util.*;
import java.io.*;
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	int n;
	int[][] dp;
	int[] val = {1, 5, 10, 50};
	int ans = 0;
	// 최대 n * 50 = 20 * 50
	public void solution() throws IOException{
		String input = br.readLine();
		int n = Integer.parseInt(input);
		dp = new int[n+1][1001];

		// dp init
		dp[1][1] = 1;
		dp[1][5] = 1;
		dp[1][10] = 1;
		dp[1][50] = 1;

		for(int i=1; i<n; i++){
			for(int j=1; j<=1000; j++){
				if(dp[i][j] != 0){
					for(int k=0; k<4; k++){
						if(j+val[k] <= 1000){
							dp[i+1][j+val[k]]++;
						}
					}
				}
			}
		}
		for(int i=1; i<=1000; i++){
			if(dp[n][i] != 0){
				ans++;
			}
		}
		bw.write(ans + "");
		bw.flush();
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}