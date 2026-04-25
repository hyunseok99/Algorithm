import java.util.*;
import java.io.*;
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n;
	int ans = 1;
	int[] dp;
	int[] path; // 경로 복구용
	int max_val = 1000001;

	public void solution() throws IOException{
		String input = br.readLine();
		n = Integer.parseInt(input);
		dp = new int[n+1];
		path = new int[n+1];
		// 최대 n번 -> 1 -> n 도달
		// 1 3 5
		// init
		for(int i=0; i<=n; i++){
			dp[i] = max_val;
		}
		dp[1] = 0;
		path[1] = 0;
		for(int i=2; i<=n; i++){
			dp[i] = dp[i-1] + 1; // case1
			path[i] = i-1;
			// case2,3
			if(i%2 == 0 && dp[i] > dp[i/2] + 1){
				dp[i] = dp[i/2] + 1;
				path[i] = i/2;
			}
			if(i%3 == 0 && dp[i] > dp[i/3] + 1){
				dp[i] = dp[i/3] + 1;
				path[i] = i/3;
			}
		}

		bw.write(dp[n] + "\n");
		while(n > 1){
			bw.write(n + " ");
			n = path[n];
		}

		bw.write(ans + " ");
		bw.flush();
	}


	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}
