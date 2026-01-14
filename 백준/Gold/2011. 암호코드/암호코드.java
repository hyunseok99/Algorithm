import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n;
	int answer;
	long[] dp;
	int divisor = 1000000;
	public void solution() throws IOException{
		String str = br.readLine();
		// 최대 가능 길이 n
		n = str.length();

		// x번까지 고려했을 떄 가능한 글자 여부
		dp = new long[n+1]; // a ~ z
        
        // 해석 불가
		if(str.charAt(0) == '0'){
			bw.write(answer + "");
			bw.flush();
			return;
		}
		// init
		dp[0] = 1;
		dp[1] = 1;

		// O(n^2)
		for(int i=2; i<=n; i++){
			char cur = str.charAt(i-1);
			int val = Integer.parseInt(cur + "");
			// 그대로 이어 붙이는 경우 + 만약 cur = 0 이면 무조건 이전과 결합
			if(val >=1 && val <= 9){
				dp[i] = (dp[i] + dp[i-1]) % divisor;
			}
			// 이전 값과 새로운 문자로 구성되는 경우
			char bef = str.charAt(i-2);
			String next = bef + "" + cur;
			int next_val = Integer.parseInt(next);
			if((next_val) >= 10 && (next_val) <= 26){
				dp[i] =  (dp[i] + dp[i-2]) % divisor;
			}
		}

		answer = (int)(dp[n] % divisor);

		bw.write(answer + "");
		bw.flush();
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}

