import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n,m;
	int ans = 1;
	int[] dp;
	int[] set_seat;

	public void solution() throws IOException{
		String input = br.readLine();
		n = Integer.parseInt(input);
		input = br.readLine();
		m = Integer.parseInt(input);

		dp = new int[n+1];

		set_seat = new int[n+1];
		for(int i=0; i<m; i++){
			int vip = Integer.parseInt(br.readLine());
			set_seat[vip] = 1;
		}

		// init
		dp[0] = 1;
		dp[1] = 1;
		if(n >= 2){
			dp[2] = 2; // 12, 21
		}
		// dp[x]: x개의 좌석으로 가능한 조건 만족 순열 1 2 3, 1 3 2, 2 1 3
		// dp[x] = dp[x-1] + dp[x-2]
		// 1 -> 12,21 -> 123,213,132 -> 1234,1243, 2134, 2143 ,1324
		for(int i=3; i<=n; i++){
			dp[i] = dp[i-1] + dp[i-2];
		}


		// ex) 1 3  9 -> dp[0] * dp[1] * dp[5]
		int prev = 0;
		for(int i=1; i<=n; i++){
			if(set_seat[i] == 1){
				ans*=dp[i-prev-1];
				prev = i;
			}
		}
		ans *= dp[n-prev];
		bw.write(ans + " ");
		bw.flush();
	}


	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}