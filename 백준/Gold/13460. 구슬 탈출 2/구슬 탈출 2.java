import java.util.*;
import java.io.*;

class Main{
	class Node{
		int y,x,lev;
        public Node(){
            this.y=0;
            this.x=0;
            this.lev=0;
        }
		public Node(int y, int x, int lev){
			this.y = y;
			this.x = x;
			this.lev = lev;
		}

		public boolean isEqualPos(Node b){
			if(this.y == b. y && this.x == b.x){
				return true;
			}
			return false;
		}

		public boolean isArrived(){
			if(this.y == target_y && this.x == target_x){
				return true;
			}
			return false;
		}
	}

	class Pair{
		Node red, blue;
		public Pair(Node red, Node blue){
			this.red = red;
			this.blue = blue;
		}
	}


	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	int n, m;

	String[][] arr;
	int[][][][] visited;
	int[] dy = {-1,1,0,0}; // 상 하 좌 우
	int[] dx = {0,0,-1,1};
	int target_y, target_x;
	int r_y, r_x, b_y, b_x;
	int answer = 12;

	public void solution() throws IOException{
		// br.readLine(); bw.write();
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);
		arr = new String[n][m];
		for(int i=0; i<n; i++){
			String str = br.readLine();
			for(int j=0; j<m; j++){
				arr[i][j] = str.charAt(j)+"";
				if(arr[i][j].equals("R")){
					r_y = i;
					r_x = j;
					arr[i][j] = ".";
				}
				if(arr[i][j].equals("B")){
					b_y = i;
					b_x = j;
					arr[i][j] = ".";

				}
				if(arr[i][j].equals("O")){
					target_y = i;
					target_x = j;
				}
			}
		}
		visited = new int[n][m][n][m];
		doBFS(visited);
		if(answer == 12){
			answer = -1;
		}
		bw.write(answer + "");
		bw.flush();
	}

	// int[2] y, x   [0]: R, [1]: B
	public void doBFS(int[][][][] visited){
		// Queue로
		Queue<Pair> q = new LinkedList<>();

		q.add(new Pair(new Node(r_y, r_x, 0), new Node(b_y, b_x, 0)));
		visited[r_y][r_x][b_y][b_x] = 1;


		while(!q.isEmpty()){
			Pair cur = q.poll();
			Node r = cur.red;
			Node b = cur.blue;
			if(r.lev > 10) break;
			// r이 도착했는지 체크해서 정답 갱신
			if(r.isArrived()){
				answer = r.lev;
				break;
			}
			// 4방향에 대한 기울이기 수행
			doLean(r, b, q, visited);
		}
	}

	public void doLean(Node r, Node b, Queue<Pair> q, int[][][][] visited){
		// 원본
		String origin_r = arr[r.y][r.x];
		String origin_b = arr[b.y][b.x];

		for(int dir=0; dir<4; dir ++){
			// 기존의 r,b 위치를 수정
			arr[r.y][r.x] = "R";
			arr[b.y][b.x] = "B";
			if(dir == 0){
				// left
				if(r.y == b.y){
					// 만약 이동 시킨 좌표가 같다면 순서 고려
					int moveX = 0;
					int moveY = r.y;
					Node n_r = new Node(), n_b = new Node();
					for(int i=1; i<m; i++){
						if(arr[moveY][i].equals("#")){
							moveX = i;
						}
						if(arr[moveY][i].equals("O")){
							moveX = i-1;
						}
						if(arr[moveY][i].equals("R")){
                            n_r = new Node(moveY, moveX+1, r.lev+1);
						}
						if(arr[moveY][i].equals("B")){
                            n_b = new Node(moveY, moveX+1, b.lev+1);
						}
					}
					// 만약 n_r, n_b 좌표가 동일하다면 작업
					if(n_r.isEqualPos(n_b)){
						if(r.x <= b.x){
							n_b.x = n_r.x+1;
						}else{
							n_r.x = n_b.x+1;
						}
					}

					// 조건 만족하면 q에 추가(빨강만 목적지 도달 or 둘다 도달 x)
					if(!n_b.isArrived() && visited[n_r.y][n_r.x][n_b.y][n_b.x] == 0){
						if(n_r.isArrived()){
							//만약 빨강 이후 파랑이 들어가는 경우라면 스킵
							if(n_b.x != n_r.x+1){
								// 빨강만 들어가는 경우 -> 종료는 call function에서
								q.add(new Pair(n_r, n_b));
								visited[n_r.y][n_r.x][n_b.y][n_b.x] = 1;

							}
						}else{
							// 모두 도착 x
							q.add(new Pair(n_r, n_b));
							visited[n_r.y][n_r.x][n_b.y][n_b.x] = 1;


						}
					}
				}else{
					// 따로 이동
					int move_r_x=0, move_b_x=0;
					Node n_r = new Node(), n_b = new Node();
					for(int i=1; i<m; i++){
						if(arr[r.y][i].equals("#")){
							move_r_x = i;
						}
						if(arr[r.y][i].equals("O")){
							move_r_x = i-1;
						}
						if(arr[b.y][i].equals("#")){
							move_b_x = i;
						}
						if(arr[b.y][i].equals("O")){
							move_b_x = i-1;
						}
						if(arr[r.y][i].equals("R")){
                            n_r = new Node(r.y, move_r_x+1, r.lev+1);
						}
						if(arr[b.y][i].equals("B")){
							n_b = new Node(b.y, move_b_x+1, b.lev+1);
						}
					}
					// 파랑이 목적지에 도달하는 경우는 제와
					if(!n_b.isArrived() && visited[n_r.y][n_r.x][n_b.y][n_b.x] == 0){
						visited[n_r.y][n_r.x][n_b.y][n_b.x] =1;
						q.add(new Pair(n_r, n_b));

					}
				}
			}

			if(dir == 1){
				// right
				if(r.y == b.y){
					// 만약 이동 시킨 좌표가 같다면 순서 고려
					int moveX = m-1;
					int moveY = r.y;
					Node n_r = new Node();
					Node n_b = new Node();
					for(int i=m-2; i>=0; i--){
						if(arr[moveY][i].equals("#")){
							moveX = i;
						}
						if(arr[moveY][i].equals("O")){
							moveX = i+1;
						}
						if(arr[moveY][i].equals("R")){
							n_r = new Node(moveY, moveX-1, r.lev+1);
						}
						if(arr[moveY][i].equals("B")){
							n_b = new Node(moveY, moveX-1, b.lev+1);
						}
					}
					// 만약 n_r, n_b 좌표가 동일하다면 작업
					if(n_r.isEqualPos(n_b)){
						if(r.x <= b.x){
							n_r.x = n_b.x-1;
						}else{
							n_b.x = n_r.x-1;
						}
					}

					// 조건 만족하면 q에 추가(빨강만 목적지 도달 or 둘다 도달 x)
					if(!n_b.isArrived() && visited[n_r.y][n_r.x][n_b.y][n_b.x] == 0){
						if(n_r.isArrived()){
							//만약 빨강 이후 파랑이 들어가는 경우라면 스킵
							if(n_b.x != n_r.x-1){
								// 빨강만 들어가는 경우 -> 종료는 call function에서
								q.add(new Pair(n_r, n_b));
								visited[n_r.y][n_r.x][n_b.y][n_b.x] = 1;

							}
						}else{
							// 모두 도착 x
							q.add(new Pair(n_r, n_b));
							visited[n_r.y][n_r.x][n_b.y][n_b.x] =1;
						}
					}
				}else{
					// 따로 이동
					int move_r_x = m-1, move_b_x=m-1;
					Node n_r = new Node(), n_b = new Node();
					for(int i=m-2; i>=0; i--){
						if(arr[r.y][i].equals("#")){
							move_r_x = i;
						}
						if(arr[r.y][i].equals("O")){
							move_r_x = i+1;
						}
						if(arr[b.y][i].equals("#")){
							move_b_x = i;
						}
						if( arr[b.y][i].equals("O")){
							move_b_x = i+1;
						}
						if(arr[r.y][i].equals("R")){
							n_r = new Node(r.y, move_r_x-1, r.lev+1);
						}
						if(arr[b.y][i].equals("B")){
							n_b = new Node(b.y, move_b_x-1, b.lev+1);
						}
					}
					// 파랑이 목적지에 도달하는 경우는 제와
					if(!n_b.isArrived() && visited[n_r.y][n_r.x][n_b.y][n_b.x] == 0){
						visited[n_r.y][n_r.x][n_b.y][n_b.x] = 1;
						q.add(new Pair(n_r, n_b));

					}
				}
			}

			if(dir == 2){
				// up
				if(r.x == b.x){
					// 만약 이동 시킨 좌표가 같다면 순서 고려
					int moveX = r.x;
					int moveY = 0;
					Node n_r = new Node(), n_b = new Node();
					for(int i=1; i<n; i++){
						if(arr[i][moveX].equals("#")){
							moveY = i;
						}
						if(arr[i][moveX].equals("O")){
							moveY = i-1;
						}
						if(arr[i][moveX].equals("R")){
							n_r = new Node(moveY+1, moveX, r.lev+1);
						}
						if(arr[i][moveX].equals("B")){
							n_b = new Node(moveY+1, moveX, b.lev+1);
						}
					}
					// 만약 n_r, n_b 좌표가 동일하다면 작업
					if(n_r.isEqualPos(n_b)){
						if(r.y <= b.y){
							n_b.y = n_r.y+1;
						}else{
							n_r.y = n_b.y+1;
						}
					}

					// 조건 만족하면 q에 추가(빨강만 목적지 도달 or 둘다 도달 x)
					if(!n_b.isArrived() && visited[n_r.y][n_r.x][n_b.y][n_b.x] == 0){
						if(n_r.isArrived()){
							//만약 빨강 이후 파랑이 들어가는 경우라면 스킵
							if(n_b.y != n_r.y+1){
								// 빨강만 들어가는 경우 -> 종료는 call function에서
								q.add(new Pair(n_r, n_b));

								visited[n_r.y][n_r.x][n_b.y][n_b.x] = 1;
							}
						}else{
							// 모두 도착 x
							q.add(new Pair(n_r, n_b));

							visited[n_r.y][n_r.x][n_b.y][n_b.x] = 1;
						}
					}
				}else{
					// 따로 이동
					int move_r_y=0, move_b_y=0;
					Node n_r = new Node(), n_b = new Node();
					for(int i=1; i<n; i++){
						if(arr[i][r.x].equals("#")){
							move_r_y = i;
						}
						if(arr[i][r.x].equals("O")){
							move_r_y = i-1;
						}
						if(arr[i][b.x].equals("#")){
							move_b_y = i;
						}
						if( arr[i][b.x].equals("O")){
							move_b_y = i-1;
						}
						if(arr[i][r.x].equals("R")){
							n_r = new Node(move_r_y+1, r.x, r.lev+1);
						}
						if(arr[i][b.x].equals("B")){
							n_b = new Node(move_b_y+1, b.x, b.lev+1);
						}
					}
					// 파랑이 목적지에 도달하는 경우는 제와
					if(!n_b.isArrived() && visited[n_r.y][n_r.x][n_b.y][n_b.x] == 0){
						q.add(new Pair(n_r, n_b));

						visited[n_r.y][n_r.x][n_b.y][n_b.x] = 1;
					}

				}
			}

			if(dir == 3){
				// down
				if(r.x == b.x){
					// 만약 이동 시킨 좌표가 같다면 순서 고려
					int moveX = r.x;
					int moveY = n-1;
					Node n_r = new Node(), n_b = new Node();
					for(int i=n-2; i>=0; i--){
						if(arr[i][moveX].equals("#")){
							moveY = i;
						}
						if(arr[i][moveX].equals("O")){
							moveY = i+1;
						}
						if(arr[i][moveX].equals("R")){
							n_r = new Node(moveY-1, moveX, r.lev+1);
						}
						if(arr[i][moveX].equals("B")){
							n_b = new Node(moveY-1, moveX, b.lev+1);
						}
					}
					// 만약 n_r, n_b 좌표가 동일하다면 작업
					if(n_r.isEqualPos(n_b)){
						if(r.y <= b.y){
							n_r.y = n_b.y-1;
						}else{
							n_b.y = n_r.y-1;
						}
					}

					// 조건 만족하면 q에 추가(빨강만 목적지 도달 or 둘다 도달 x)
					if(!n_b.isArrived() && visited[n_r.y][n_r.x][n_b.y][n_b.x] == 0){
						if(n_r.isArrived()){
							//만약 빨강 이후 파랑이 들어가는 경우라면 스킵
							if(n_b.y != n_r.y-1){
								// 빨강만 들어가는 경우 -> 종료는 call function에서
								q.add(new Pair(n_r, n_b));
								visited[n_r.y][n_r.x][n_b.y][n_b.x] = 1;


							}
						}else{
							// 모두 도착 x
							q.add(new Pair(n_r, n_b));
							visited[n_r.y][n_r.x][n_b.y][n_b.x] = 1;

						}
					}
				}else{
					// 따로 이동
					int move_r_y=n-1, move_b_y=n-1;
					Node n_r = new Node(), n_b = new Node();
					for(int i=n-2; i>=0; i--){
						if(arr[i][r.x].equals("#")){
							move_r_y = i;
						}
						if(arr[i][r.x].equals("O")){
							move_r_y = i+1;
						}
						if(arr[i][b.x].equals("#")){
							move_b_y = i;
						}
						if(arr[i][b.x].equals("O")){
							move_b_y = i+1;
						}
						if(arr[i][r.x].equals("R")){
							n_r = new Node(move_r_y-1, r.x, r.lev+1);
						}
						if(arr[i][b.x].equals("B")){
							n_b = new Node(move_b_y-1, b.x, b.lev+1);
						}
					}
					// 파랑이 목적지에 도달하는 경우는 제와
					if(!n_b.isArrived() && visited[n_r.y][n_r.x][n_b.y][n_b.x] == 0){
						q.add(new Pair(n_r, n_b));
						visited[n_r.y][n_r.x][n_b.y][n_b.x] = 1;

					}
				}
			}
		}
		// 작업 후 위치 초기화
		arr[r.y][r.x] = origin_r;
		arr[b.y][b.x] = origin_b;

	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}