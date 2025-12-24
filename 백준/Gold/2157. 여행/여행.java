import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	int n, m, k;
	
	// dp[i][j] -> j번째에 i 도시 도착 했을 때의 최대 기내식 점수 
	// 1. i번 도시보다 작은 도시에서 -> i로 가능한 경로 있으면 연산  
	// O(n*m*n) -> n^3 
	int[][] dp;   
	int[][] score; // a -> b 이동시 기내식 점수: 최댓값으로 갱신  
	int answer = 0;
	public void solution() throws IOException{
		// br.readLine(); bw.write();
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);
		k = Integer.parseInt(input[2]);
		dp = new int[n+1][m+1];
		score = new int[n+1][n+1];
		
		for(int i=0; i<k; i++){
			input = br.readLine().split(" ");
			int a = Integer.parseInt(input[0]);
			int b = Integer.parseInt(input[1]);
			int c = Integer.parseInt(input[2]);
			score[a][b] = Math.max(score[a][b], c);
		}
		
		// dp init
		for(int i=0; i<dp.length; i++){
			for(int j=0; j<dp[i].length; j++){
				dp[i][j] = Integer.MIN_VALUE;
			}
		}
		
		// init -> 처음 1번 시작 = 0 
		dp[1][1] = 0; 
		for(int turn=1; turn < m; turn++){
			for(int city = 1; city < n; city++){
				if(dp[city][turn] != Integer.MIN_VALUE){
					for(int target=city+1; target <=n; target++){
						if(score[city][target] != 0){
							int val = dp[city][turn] + score[city][target];
							dp[target][turn+1] = Math.max(dp[target][turn+1], val);
						}
					}
				}
			}
		}
		
		for(int i=1; i<=m; i++){
			answer = Math.max(answer, dp[n][i]);
		}
		
		bw.write(answer + " ");
		bw.flush();
	}
	
	
	public static void main(String[] args) throws IOException{  
	   Main ans = new Main();
	   ans.solution();
	}  
}