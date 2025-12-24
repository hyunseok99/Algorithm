import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	int n;
	int[] arr;
	int[][] cost;
	int[][][] dp; // dp[turn][idx][visite] : turn은 최대 n+1
	// m개의 구간이 필요
	public void solution() throws IOException{
		// br.readLine(); bw.write();
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		// n개의 섬 모두 방문했다면 2^n -1
		int max_visited = (int)Math.pow(2,n) - 1;  // ~= 6만

		cost = new int[n+1][n+1];

		// 섬이 5개 -> turn 0~5   ->  0,5는 1번 섬
		dp = new int[n+1][n+1][max_visited+1];
		for(int i=1; i<=n; i++){
			input = br.readLine().split(" ");
			for(int j=1; j<=input.length; j++){
				cost[i][j] = Integer.parseInt(input[j-1]);
			}
		}

		// dp init
		for(int i=0; i<=n; i++){
			for(int j=0; j<=n; j++){
				for(int k=0; k<dp[i][j].length; k++){
					dp[i][j][k] = Integer.MAX_VALUE;
				}
			}
		}
		dp[0][1][0] = 0; // 처음 시작위치 + 마지막에 다시 돌아와야 함

		// 마지막은 1로 이동 -> dp[n-1][][] 에서 1번으로 이동해야면 dp[n]
		// O(n * n * 2^n * n)
		for(int i=0; i<n; i++){
			// 현재 위치한 섬
			for(int j=1; j<=n; j++){
				// 가능한 방문체크
				for(int k=0; k<=max_visited; k++){
					if(dp[i][j][k] != Integer.MAX_VALUE){
						// 이동 가능한 섬
						for(int to=1; to<=n; to++){
							// 이미 방문을 한 곳이거나 방문 불가하면 스킵
							if(cost[j][to] == 0 ) continue;
							if((1 << (to-1) & k) != 0) continue;

							// 이동 가능하다면 갱신
							// 7 = 0111
							// 9 = 1001
							// 10 = 1010
							int add = 1 << (to-1);
							dp[i+1][to][k+add] = Math.min(dp[i+1][to][k+add],
								dp[i][j][k] + cost[j][to]);
						}
					}
				}
			}
		}



		bw.write(dp[n][1][max_visited] + " ");
		bw.flush();
	}


	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}

