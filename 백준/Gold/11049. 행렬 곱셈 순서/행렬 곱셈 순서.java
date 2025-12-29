import java.io.*;
import java.util.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	int n;

	// O(n^3) 가능
	// 마지막에 쪼개지는 부분들의 연속으로
	int[][]dp; // dp[i][k] + dp[k][j] + 연산 횟수 이용

	int[] row;
	int[] col;
	int answer = 0;
	public void solution() throws IOException{
		// br.readLine(); bw.write();
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		row = new int[n];
		col = new int[n];
		dp = new int[n][n];
		for(int i=0; i<n; i++){
			input = br.readLine().split(" ");
			int r = Integer.parseInt(input[0]);
			int c = Integer.parseInt(input[1]);
			row[i] = r;
			col[i] = c;
		}

		// 1~n 노드까지 분할해서 연산
		for(int len=1; len < n; len++){
			for(int i=0; i+len <n; i++){
				int j= i+len;
				dp[i][j] = Integer.MAX_VALUE; // 2^31 -1
				// 분할 지점 k
				for(int k=i; k < j; k++){
					// A B C D
					// AB CD
					// ABCD
					// 왼쪽 덩어리 + 오른쪽 덩어리 + 행*열*열
					// =  행*열*열 + 행*열*열
					int cost = dp[i][k] + dp[k+1][j] + row[i] * col[k] * col[j];
					dp[i][j] = Math.min(dp[i][j], cost);
				}
			}
		}

		bw.write(dp[0][n-1] + "");
		bw.flush();
	}


	public static void main(String[] args) throws IOException {
	   Main ans = new Main();
	   ans.solution();
	}
}