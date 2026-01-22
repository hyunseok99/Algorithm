import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n, m;
	int empty_cnt = 0; // 채워야 할 칸
	int[][] arr; // 0 빈칸, 1벽, 2 비활성 바이러스
	int[] dy = {-1,1,0,0};
	int[] dx = {0,0,-1,1};
	ArrayList<Virus> virus_list = new ArrayList<>();
	int answer = Integer.MAX_VALUE;
	public class Virus{
		int y,x;
		public Virus(int y, int x){
			this.y = y;
			this.x = x;
		}
	}
	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
 		n = Integer.parseInt(input[0]);
 		m = Integer.parseInt(input[1]);
 		arr = new int[n][n];
 		for(int i=0; i<n; i++){
	 		input = br.readLine().split(" ");
	 		for(int j=0; j<n; j++){
		 		arr[i][j] = Integer.parseInt(input[j]);
				if(arr[i][j] == 0){
					empty_cnt++;
				}

		 		if(arr[i][j] == 2){
			 		virus_list.add(new Virus(i,j));
		 		}
	 		}
 		}
		// 시작부터 다 채운 경우
		if(empty_cnt == 0){
			bw.write(0 + "");
			bw.flush();
			return;
		}

 		// 조합을 통한 결과 도출
 		getComb(0, 0, new int[m]);
		answer = (answer == Integer.MAX_VALUE) ? -1 : answer;
		bw.write(answer +"");
		bw.flush();
	}

	// 특정 바이러스 활성화 시켰을때의 시간에 따른 감염 배열 : 0이상이면 감염
	public void activateVirus(int[] selected){
		int[][] n_arr = new int[n][n];
		boolean[][] flag = new boolean[n][n];
		Queue<Virus> q = new LinkedList<>();
		for(int v: selected){
			Virus tmp = virus_list.get(v);
			q.add(tmp);
			flag[tmp.y][tmp.x] = true;
		}
		int max_t = 0;
		int cnt = 0;
		while(!q.isEmpty()){
			Virus cur = q.poll();
			int t = n_arr[cur.y][cur.x];
			if(t >= answer){
				return; // 이미 정답 시간을 넘었으면 탐색 종료
			}
			for(int dir=0; dir<4; dir++){
				int ny = cur.y + dy[dir];
				int nx = cur.x + dx[dir];
				if(nx >=0 && ny >=0 && nx < n && ny < n && arr[ny][nx] != 1 && !flag[ny][nx]){
					flag[ny][nx] = true;
					q.add(new Virus(ny,nx));
					n_arr[ny][nx] = t+1;
					// 빈칸인 경우만 시간 갱신 + 카운트
					if(arr[ny][nx] == 0){
						cnt++;
						max_t = Math.max(max_t, t+1);
                        if(cnt == empty_cnt){
			                answer = Math.min(max_t, answer);
                            return;
		                }
					}
				}
			}
		}
		return;
	}

	// kCm
	public void getComb(int start, int depth, int[] selected){
		if(depth == m){
			activateVirus(selected); // virus idx
			return;
		}
		for(int i=start; i<virus_list.size(); i++){
			selected[depth] = i;
			getComb(i+1, depth+1, selected);
		}
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}
