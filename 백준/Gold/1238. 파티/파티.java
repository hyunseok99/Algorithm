import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n,m,x;
	int answer;
	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		// 최대 가능 길이 n
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);
		x = Integer.parseInt(input[2]);
		int[][] adj = new int[n+1][n+1];

		for(int i=0; i<m; i++){
			input = br.readLine().split(" ");
			adj[Integer.parseInt(input[0])][Integer.parseInt(input[1])] = Integer.parseInt(input[2]);
		}

		int[][] time = new int[n+1][n+1]; // a -> b 최단 시간
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i == j){
					time[i][j] = 0;
				}else{
					time[i][j] = 1000001;
				}
			}
		}

		// O(n * m)
		for(int i=1; i<=n; i++){
			Queue<Integer> q = new LinkedList<>();
			q.add(i);
			while(!q.isEmpty()){
				int cur = q.poll();

				for(int next=1; next<=n; next++){
					if(adj[cur][next] == 0) continue;
					int n_val = time[i][cur] + adj[cur][next];
					if(time[i][next] > n_val){
						time[i][next] = n_val;
						q.add(next);
					}
				}
			}
		}

		// 정답 계산
		for(int i=1; i<=n; i++){
			int tot = time[i][x] + time[x][i];
			answer = Math.max(answer, tot);
		}

		bw.write(answer + "");
		bw.flush();
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}