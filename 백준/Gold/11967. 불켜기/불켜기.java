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
		arr[1][1] = 1; // 불 켜짐
		visit[1][1] = 1; // 방문 가능 여부
		flag[1][1] = true; // 방문함
		Queue<Pos> q = new LinkedList<>();
		q.add(new Pos(1,1));
		answer++;
		// 불 키고 -> 새로 킨 곳이 기존에 이동 가능한 곳 옆이면 추가 
        // O(n^2 + m)
		while(!q.isEmpty()){
			Pos cur = q.poll();
			// turn on
			for(Pos room: rooms[cur.y][cur.x]){
				// 꺼져있던 방이면 불을 켠다
				if(arr[room.y][room.x] == 0){
					arr[room.y][room.x] = 1;
					answer++;

					// 또한 만약 이 방이 다음에 도달 가능하고 아직 방문을 안했었다면 추가
					if(!flag[room.y][room.x] && visit[room.y][room.x] == 1){
						flag[room.y][room.x] = true;
						q.add(room);
					}
				}
			}
			// can move //
			for(int dir=0; dir < 4; dir++){
				int ny = cur.y + dy[dir];
				int nx = cur.x + dx[dir];
				if(nx <= 0 || nx > n || ny <=0 || ny > n) continue;
				// 이동 가능 체크
				visit[ny][nx] = 1;
				// 만약 불이 켜져있고 아직 방문을 하지 않았다면 추가
				if(arr[ny][nx] == 1 && flag[ny][nx] == false){
					flag[ny][nx] = true;
					q.add(new Pos(ny, nx));
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
