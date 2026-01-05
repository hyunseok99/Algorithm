import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n,m;
	int answer;
	int[] dy = {-1, 1, 0, 0};
	int[] dx = {0, 0, -1, 1};
	int[][] arr;
	int[][] visit;
	boolean[][] flag;
	ArrayList<Pos>[][] rooms; // 특정 방에 있는 스위치
	// bfs를 통해서 depth별로 최대한 밝혀나가면 될 듯
	class Pos{
		int y,x;
		public Pos(int y, int x){
			this.y = y;
			this.x = x;
		}
	}

	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);
		arr = new int[n+1][n+1];
		visit = new int[n+1][n+1];
		flag = new boolean[n+1][n+1];
		rooms = new ArrayList[n+1][n+1];
		for(int i=0; i<=n; i++){
			for(int j=0; j<=n; j++){
				rooms[i][j] = new ArrayList<>();
			}
		}

		for(int i=0; i<m; i++){
            input = br.readLine().split(" ");
			rooms[Integer.parseInt(input[0])][Integer.parseInt(input[1])].add(new Pos(Integer.parseInt(input[2]), Integer.parseInt(input[3])));
		}

		// init
		arr[1][1] = 1;
		visit[1][1] = 1;
		flag[1][1] = true;
		Queue<Pos> q = new LinkedList<>();
		Queue<Pos> nq = new LinkedList<>();
		q.add(new Pos(1,1));
		while(true){
			// 불 키고 -> 새로 생긴 이동 가능한 곳 생기면 다시 작업
			while(!q.isEmpty()){
				Pos cur = q.poll();
				flag[cur.y][cur.x] = true; // 방문 체크
				// turn on
				for(Pos room: rooms[cur.y][cur.x]){
					arr[room.y][room.x] = 1;
				}

				// can move //
				for(int dir=0; dir < 4; dir++){
					int ny = cur.y + dy[dir];
					int nx = cur.x + dx[dir];
					if(nx >= 1 && nx <=n && ny>=1 && ny <=n){
						visit[ny][nx] = 1;
					}
				}
			}

			// 이동 가능하고 불이 켜져 있으며 방문하지 않았다면 q에 추가
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					if(arr[i][j] == 1 && visit[i][j] == 1 && !flag[i][j]){
						nq.add(new Pos(i,j));
					}
				}
			}

			// 더이상 방문 x면 종료
			if(nq.isEmpty()){
				break;
			}

			while(!nq.isEmpty()){
				q.add(nq.poll());
			}
		}

		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(arr[i][j] == 1) {
					answer++;
				}
			}
		}

		bw.write(answer + "");
		bw.flush();
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}
