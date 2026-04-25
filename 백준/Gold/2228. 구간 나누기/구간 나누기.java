import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	int n, m;
	int[] arr;
	int[] sum; // 연산에 사용할 누적합  
	// dp[i][j] -> i번째 원소를 고려했을 때 j개의 구간을 선택했을 때의 최대 합
	// 1. i번째 수를 구간에 포함시키기 vs j번 구간의 마지막 원소로 포함 
	// dp[i][j] = dp[i-1][j] or dp[k-2][j-1] + k~i까지의 합 
	int[][] dp;   
    int min_value = -32768*101;

	// m개의 구간이 필요 
	public void solution() throws IOException{
		// br.readLine(); bw.write();
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);
		arr = new int[n+1];
		sum = new int[n+1];
		dp = new int[n+1][m+1]; // dp[i][j]: idx, 구간
		for(int i=1; i<arr.length; i++){
			String str = br.readLine();
			arr[i] = Integer.parseInt(str); // 배열값
			sum[i] = sum[i-1] + arr[i]; // 누적합 
		}
		
		// dp init
		for(int i=0; i<dp.length; i++){
			for(int j=0; j<dp[i].length; j++){
				dp[i][j] = min_value;
			}
    		dp[i][0] = 0; // 0개 구간 = 0
        }
		for(int i=1; i <= n; i++){
			for(int j=1; j<=m; j++){
				// i번 원소를 포함하지 않는 경우
				dp[i][j] = dp[i-1][j];
				// i번 원소를 j번 구간의 마지막 원소로 설정
				for(int k=1; k<=i; k++){
					// k~i까지의 합 
					int cur_sum = sum[i] - sum[k-1];
					
					// 이전 상태: k-2번 idx까지 j-1개의 구간을 만들어 놓은 상태  
					if(k >= 2 && dp[k-2][j-1] != min_value){
						dp[i][j] = Math.max(dp[i][j], dp[k-2][j-1] + cur_sum);
					}
					if(k == 1 && j == 1){
						// init
						dp[i][j] = Math.max(dp[i][j], cur_sum);
					}
				}
			}
		}
		
		bw.write(dp[n][m] + " ");
		bw.flush();
	}
	
	
	public static void main(String[] args) throws IOException{  
	   Main ans = new Main();
	   ans.solution();
	}  
}