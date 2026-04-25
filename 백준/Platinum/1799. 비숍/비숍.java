import java.util.*;
import java.io.*;
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	int n;
	int max_cnt;
	int[][] arr;
	int[] flags1, flags2;

	int[] dy ={-1, 1, 0, 0};
	int[] dx ={0, 0, -1, 1};

	int[] answer = {0, 0};
	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		arr = new int[n][n];
		for(int i=0; i<n; i++){
			input = br.readLine().split(" ");
			for(int j=0; j<n; j++){
				arr[i][j] = Integer.parseInt(input[j]); 
				if(arr[i][j] == 1){
					max_cnt++;
				}
			}
		}
		flags1 = new int[2*n]; // 좌하단 대각선
		flags2 = new int[2*n]; // 우상향 대각선
		
		// 짝수라인 백트래킹 후 홀수 라인 백트래킹
		backTracking(0,0,0,0);
		backTracking(0,1,0,1);
		
		// 결과 연산 
		bw.write(answer[0] + answer[1] + "");
		bw.flush();
	}

	public void backTracking(int y, int x, int lev, int type){
		// type: 홀수 라인 or 짝수라인
		if(x >= n){
			// 다음 라인 이동
			y++;
			x=0;
		}

		// 탐색 끝
		if(y >= n){
			answer[type] = Math.max(answer[type], lev);
			return;
		}

		// 담당 type 아니면 스킵
		if((x+y) % 2 != type){
			backTracking(y, x+1, lev, type);
			return;
		}
		// 현재 위치에 비숍 추가
		if(arr[y][x] == 1 && flags1[x-y+n-1] == 0 && flags2[x+y] == 0){
			flags1[x-y+n-1] = 1;
			flags2[x+y] = 1;
			backTracking(y, x+1, lev+1, type);

			flags1[x-y+n-1] = 0;
			flags2[x+y] = 0;

		}

		// 현재 위치에 추가 안하는 경우
		backTracking(y, x+1, lev, type);
	}
	

	public static void main(String[] args) throws IOException{  
	   Main ans = new Main();
	   ans.solution();
	}  
}