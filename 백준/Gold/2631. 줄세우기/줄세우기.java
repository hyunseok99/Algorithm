import java.util.*;
import java.io.*;
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n;
	int[] arr;
	int[]dp;

	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		arr = new int[n+1];
		dp = new int[n+1];
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<n; i++){
			arr[i] = Integer.parseInt(br.readLine());
		}
		// target은 1,2,3 .. n을 만드는 것
		// 옮긴 경우는 순서대로 맞추기 제외 -> 남은 아이들의 seq 여부 -> 오름차순이면 끝
		// ex) dp[0][0] = "3752614" -> dp[1][1] = "752614"
		// 가능한 종류들 -> 연속찾기 -> 불가능하면 하나 제거 반복
		// 10 -> 10*9 -> 10*9*8 ... -> O(n!) 불가
		// 결국 -> 증가하는 최장수열을 찾고 나머지 갯수가 정답
		// dp[n]으로 끝  -> dp[i] : i번째를 마지막으로하는 LIS 길이

		// find LIS
		int lis_len = 0;
		for(int i = 0; i<n; i++){
			dp[i] = 1; // 처음 자기 자신만 있는 경우 1
			for(int j=0; j<i; j++){
				if(arr[j] < arr[i]){
					dp[i] = Math.max(dp[j] + 1, dp[i]);
				}
			}
			lis_len = Math.max(lis_len, dp[i]);
		}
		int answer = n - lis_len;
		bw.write(answer + " ");
		bw.flush();
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}