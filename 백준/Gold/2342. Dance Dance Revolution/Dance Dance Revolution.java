import java.util.*;
import java.io.*;

// 항상 에너지가 최소사용 되도록 이동한다면 -> 다음 이동이 최소가 되는가
// ex) 1 -> 3 -> 2 -> 4 -> 1 이면 처음 1을 유지?
// (1,0) (1,3) (1,2) (1,4) (1,4) -> 2 + 2 + 3 + 4 + 1 = 12
// 매 이동 최소 사용 이동이라면?
// (1,0) (1,3) (2,3) (2,4) (1,4) 2 + 2 +3 + 3 +3 = 13
// -> 다음 이동이 최소여도 전체 이동이 최소를 보장 x
// 따라서 dp 방식으로 x번째 이동의 왼발, 오른발 위치를 이용해서 마지막에 최소값 구하자
// O(25* 수열len)
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	int n; // 수열 길이

	int[] arr; // 밟아야 하는 순서
	int[][][] dp; // 3차원으로 dp[l][r][turn] 왼발, 오른발, 턴 : 최소를 유지하자

	public void solution() throws IOException{
		// br.readLine(); bw.write();
		String[] input = br.readLine().split(" ");
		n = input.length;
		arr = new int[n]; // n=5 -> 1~4
		for(int i=1; i<n; i++){
			arr[i] = Integer.parseInt(input[i-1]);
		}
		dp = new int[5][5][n];
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				for(int k=0; k<n; k++){
					dp[i][j][k] = Integer.MAX_VALUE;
				}
			}
		}
		// 처음 0번째 turn init
		dp[0][0][0] = 0;

		// 수열 길이가 5 -> 3턴 까지 계산 -> 4턴 까지 갱신
		for(int turn=0; turn<n-1; turn++){
			int next_turn = turn+1;
			for(int left=0; left<5; left++){
				for(int right=0; right<5; right++){
					if(dp[left][right][turn] != Integer.MAX_VALUE){
						int target = arr[next_turn];
						// 왼발을 이동하는 경우
						dp[target][right][next_turn] = Math.min(dp[target][right][next_turn], dp[left][right][turn] + getForce(left, target));
						// 오른발 이동하는 경우
						dp[left][target][next_turn] = Math.min(dp[left][target][next_turn], dp[left][right][turn] + getForce(right, target));
					}
				}
			}
		}
		// answer = min(왼발, 오른발)
		int goal = arr[n-1];
		int answer = Integer.MAX_VALUE;
		for(int i=0; i<5; i++){
			// 왼발,오른발
			answer = Math.min(answer, Math.min(dp[goal][i][n-1], dp[i][goal][n-1]));
		}
		bw.write(answer + " ");
		bw.flush();
	}
	public int getForce(int start, int target){
		if(start == 0){
			// 시작 위치에서 출발
			return 2;
		}else{
			int difference = Math.abs(start - target);
			if(difference == 0){
				// 그대로
				return 1;
			}
			if(difference == 2){
				// 정반대
				return 4;
			}

			// 아니면 인접
			return 3;
		}
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}
