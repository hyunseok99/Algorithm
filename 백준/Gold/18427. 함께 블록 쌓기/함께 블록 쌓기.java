import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n,m,h;
	int answer;
	int[][] dp;
	ArrayList<Integer>[] blocks;
	int divisor = 10007;
	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		// 최대 가능 길이 n
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);
		h = Integer.parseInt(input[2]);
		blocks = new ArrayList[n];
		dp = new int[n][h+1];

		for(int i=0; i<n; i++){
			blocks[i] = new ArrayList<>();
		}

		for(int i=0; i<n; i++){
			String[] str = br.readLine().split(" ");
			for(int j=0; j<str.length; j++){
				blocks[i].add(Integer.parseInt(str[j]));
			}
		}

		// dp init
		dp[0][0] = 1;
		for(int i=0; i<blocks[0].size(); i++){
			if(blocks[0].get(i) <= h){
				dp[0][blocks[0].get(i)] = 1;
			}
		}

		// dp init

		// dp[][] -> x번까지 고려했을 때 구현 가능한 높이
		// O(n * h * m )
		for(int i=1; i<n; i++){
			for(int j=0; j<= h; j++){
                    dp[i][j] = dp[i-1][j];
			}
			for(int val: blocks[i]){
				for(int j=0; j<=h; j++){
					if(dp[i-1][j] != 0 && j+val <= h){
						dp[i][j+val] = (dp[i][j+val] + dp[i-1][j]) % divisor;
					}

				}
			}
		}

		answer = dp[n-1][h];
		bw.write(answer + "");
		bw.flush();
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}
