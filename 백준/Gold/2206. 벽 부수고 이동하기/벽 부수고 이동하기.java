import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	int n, m;

	int[][] arr;
	boolean[][][] flags;
	int answer = Integer.MAX_VALUE;
	int[] dy = {-1, 1, 0, 0};
	int[] dx = {0, 0, -1, 1};
	public class Pos{
		int y,x;
		int lev,broken;
		public Pos(int y, int x, int lev, int broken){
			this.y = y;
			this.x = x;
			this.lev = lev;
			this.broken = broken;
		}
	}
	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);
		arr = new int[n+1][m+1];
		flags = new boolean[n+1][m+1][2];
		for(int i=1; i<=n; i++){
			String str = br.readLine();
			for(int j=1; j<=m; j++){
				arr[i][j] = Integer.parseInt(str.charAt(j-1)+"");
			}
		}

		Deque<Pos> q = new ArrayDeque<>();
		// start init (1,1) -> (n,m)
		q.add(new Pos(1,1,1,0));
		flags[1][1][0] = true;
		while(!q.isEmpty()){
			Pos cur = q.poll();
			if(cur.broken >= 2) continue;
			if(cur.y == n && cur.x == m){
				answer = cur.lev;
				break;
			}
			for(int dir=0; dir<4; dir++){
				int ny = cur.y + dy[dir];
				int nx = cur.x + dx[dir];
				if(nx >= 1 && ny >= 1 && nx <= m && ny <= n){
					if(cur.broken == 1 && !flags[ny][nx][1]){
						if(arr[ny][nx] == 0){
							flags[ny][nx][1] = true;
							q.add(new Pos(ny,nx,cur.lev+1, cur.broken));
						}
					}
					if(cur.broken == 0 && !flags[ny][nx][0]){
						if(arr[ny][nx] == 1){
							flags[ny][nx][1] = true;
							q.add(new Pos(ny,nx,cur.lev+1, cur.broken+1));
						}
						if(arr[ny][nx] == 0){
							flags[ny][nx][0] = true;
							q.add(new Pos(ny,nx,cur.lev+1, cur.broken));
						}
					}
				}
			}
		}

		answer = answer == Integer.MAX_VALUE ? -1 : answer;
		bw.write(answer + " ");
		bw.flush();
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}
