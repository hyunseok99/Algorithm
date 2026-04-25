import java.util.*;
import java.io.*;
class Main{
	class Log{
		int y, x, state;// 중심점 좌표, 상태[0,1]: 가로,세로
		public Log(int y, int x, int state){
			this.y = y;
			this.x = x;
			this.state = state;
		}

		@Override
		public boolean equals(Object o){
			if(this == o) return true;
			if(o == null || getClass() != o.getClass()) return false;
			Log tmp = (Log) o;
			return y == tmp.y && x == tmp.x && Objects.equals(state, tmp.state);
		}

		@Override
		public int hashCode(){
			return Objects.hash(y, x, state);
		}
	}

	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	int n;
	String[][] arr;
	Set<Log> visited = new HashSet<>();
	int ans = 0;
	// 최대 n * 50 = 20 * 50
	public void solution() throws IOException{
		String input = br.readLine();
		n = Integer.parseInt(input);
		arr = new String[n][n];
		Log start = new Log(0,0,0); // 시작 통나무
		Log target = new Log(0,0,0); // 통나무가 도착할 경우
		// 두번째로 탐지되는 B가 통나무 중심
		int first_x = 0, cnt = 0, last_x = 0, cnt2 = 0; // 각각 출발, 도착 통나무
		for(int i=0; i<n; i++){
			input = br.readLine();
			for(int j=0; j<n; j++){
				arr[i][j] = input.charAt(j)+"";
				if(arr[i][j].equals("B")){ // 통나무 시작 정보
					cnt++;
					arr[i][j] = "0";
					if(cnt == 1){
						first_x = j;
					}
					if(cnt == 2){
						// 가로 세로 여부 (default 가로)
						if(first_x == j){
							start.state = 1;
						}
						start.y = i;
						start.x = j;
					}
				}
				if(arr[i][j].equals("E")){ // 통나무 도착 정보
					cnt2++;
					arr[i][j] = "0";
					if(cnt2 == 1){
						last_x = j;
					}
					if(cnt2 == 2){
						// 가로 세로 여부 (default 가로)
						if(last_x == j){
							target.state = 1;
						}
						target.y = i;
						target.x = j;
					}
				}
			}
		}

		// bfs 탐색
		Queue<Log> q = new LinkedList<>();
		Queue<Integer> lev_q = new LinkedList<>();
		q.add(start);
		lev_q.add(0);
        visited.add(start);
		while(!q.isEmpty()){
			Log cur = q.poll();
			int lev = lev_q.poll();
			// 정답 여부 확인
			if(cur.equals(target)){
				ans = lev;
				break;
			}
			// 5가지 방법 수행
			move(q, lev_q, cur, lev);
		}

		bw.write(ans + "");
		bw.flush();
	}

	// 5가지 방향의 움직임 수행
	public void move(Queue<Log> q, Queue<Integer> lev_q, Log cur, int lev){
		for(int type=0; type < 5; type++){
			// 상,하,좌,우,회전
			if(type == 0){ // 상
				// 가로 세로
				int ny =cur.y -1;
				int nx = cur.x;
				if(cur.state == 0){
					// 고려 좌표: 좌,중심,우
					if(1<=nx && nx < n-1 && 0<=ny && ny < n){
						if(arr[ny][nx].equals("0") && arr[ny][nx-1].equals("0") && arr[ny][nx+1].equals("0")){
							Log next = new Log(ny, nx, cur.state);
							if(!visited.contains(next)){
								q.add(next);
								lev_q.add(lev+1);
			                    visited.add(next);
                                
							}
						}
					}
				}else{
					// 고려 좌표: 상,중심,하
					if(0<= nx && nx < n && 1<= ny && ny < n-1){
						if(arr[ny-1][nx].equals("0") && arr[ny][nx].equals("0") && arr[ny+1][nx].equals("0")){
							Log next = new Log(ny, nx, cur.state);
							if(!visited.contains(next)){
								q.add(next);
								lev_q.add(lev+1);
			                    visited.add(next);

							}
						}
					}
				}
			}
			if(type == 1){ // 하
				int ny = cur.y + 1;
				int nx = cur.x;
				if(cur.state == 0){
					// 고려 좌표: 좌,중심,우
					if(1<=nx && nx < n-1 && 0<=ny && ny < n){
						if(arr[ny][nx].equals("0") && arr[ny][nx-1].equals("0") && arr[ny][nx+1].equals("0")){
							Log next = new Log(ny, nx, cur.state);
							if(!visited.contains(next)){
								q.add(next);
								lev_q.add(lev+1);
			                    visited.add(next);

							}
						}
					}
				}else{
					// 고려 좌표: 상,중심,하
					if(0<= nx && nx < n && 1<= ny && ny < n-1){
						if(arr[ny-1][nx].equals("0") && arr[ny][nx].equals("0") && arr[ny+1][nx].equals("0")){
							Log next = new Log(ny, nx, cur.state);
							if(!visited.contains(next)){
								q.add(next);
								lev_q.add(lev+1);
			                    visited.add(next);

							}
						}
					}
				}
			}
			if(type == 2){ // 좌
				int ny = cur.y;
				int nx = cur.x -1;
				if(cur.state == 0){
					// 가로
					if(1<=nx && nx < n-1 && 0 <= ny && ny < n){
						if(arr[ny][nx].equals("0") && arr[ny][nx-1].equals("0") && arr[ny][nx+1].equals("0")){
							Log next = new Log(ny, nx, cur.state);
							if(!visited.contains(next)){
								q.add(next);
								lev_q.add(lev+1);
			                    visited.add(next);

							}
						}
					}
				}else{
					// 세로
					if(0<= nx && nx < n && 1<= ny && ny < n-1){
						if(arr[ny-1][nx].equals("0") && arr[ny][nx].equals("0") && arr[ny+1][nx].equals("0")){
							Log next = new Log(ny, nx, cur.state);
							if(!visited.contains(next)){
								q.add(next);
								lev_q.add(lev+1);
			                    visited.add(next);

							}
						}
					}
				}
			}
			if(type == 3){ // 우
				int ny = cur.y;
				int nx = cur.x + 1;
				if(cur.state == 0){
					// 가로
					if(1<=nx && nx < n-1 && 0 <= ny && ny < n){
						if(arr[ny][nx].equals("0") && arr[ny][nx-1].equals("0") && arr[ny][nx+1].equals("0")){
							Log next = new Log(ny, nx, cur.state);
							if(!visited.contains(next)){
								q.add(next);
								lev_q.add(lev+1);
			                    visited.add(next);

							}
						}
					}
				}else{
					// 세로
					if(0<= nx && nx < n && 1<= ny && ny < n-1){
						if(arr[ny-1][nx].equals("0") && arr[ny][nx].equals("0") && arr[ny+1][nx].equals("0")){
							Log next = new Log(ny, nx, cur.state);
							if(!visited.contains(next)){
								q.add(next);
								lev_q.add(lev+1);
			                    visited.add(next);

							}
						}
					}
				}
			}
			if(type == 4){
				int ny = cur.y;
				int nx = cur.x;
				if(cur.state == 0){
					// 가로 -> 위 세칸, 아래 세칸 확인
					if(1<= nx && nx < n-1 && 1<= ny && ny < n-1){
						if(arr[ny-1][nx].equals("0") && arr[ny-1][nx-1].equals("0") && arr[ny-1][nx+1].equals("0") && arr[ny+1][nx].equals("0") && arr[ny+1][nx-1].equals("0") && arr[ny+1][nx+1].equals("0")){
							Log next = new Log(ny, nx, 1);
							if(!visited.contains(next)){
								q.add(next);
								lev_q.add(lev+1);
			                    visited.add(next);

							}
						}
					}
				}else{
					// 세로 -> 좌 세칸, 우 세칸 확인
					if(1<= nx && nx < n-1 && 1<= ny && ny < n-1){
						if(arr[ny][nx-1].equals("0") && arr[ny-1][nx-1].equals("0") && arr[ny+1][nx-1].equals("0") && arr[ny][nx+1].equals("0") && arr[ny-1][nx+1].equals("0") && arr[ny+1][nx+1].equals("0")){
							Log next = new Log(ny, nx, 0);
							if(!visited.contains(next)){
								q.add(next);
								lev_q.add(lev+1);
			                    visited.add(next);

							}
						}
					}
				}
			}
		}
	}


	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}
