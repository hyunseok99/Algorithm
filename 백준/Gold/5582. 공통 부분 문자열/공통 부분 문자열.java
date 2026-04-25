import java.util.*;
import java.io.*;

class Main{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException{
		String input = br.readLine();
		String input2 = br.readLine();
		int n = input.length();
		int m = input2.length();

		int[][] dp = new int[n + 1][m + 1];
		int ans = 0; // empty인 경우

		for(int i=1; i<= n; i++){
			for(int j=1; j<=m; j++){
				// 문자가 같으면 -> j+1, 다르면 i+
				if(input.charAt(i-1) == input2.charAt(j-1)){
					dp[i][j] = dp[i-1][j-1] + 1;
					ans = Math.max(ans, dp[i][j]);
				}
			}
		}
		bw.write(ans + "");
		bw.flush();
	}

}