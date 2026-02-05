import java.util.*;
import java.io.*;
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int h,w;
	int answer = 10001;
	int[] dy = {-1,1,0,0};
	int[] dx = {0,0,-1,1};
	char[][] arr;
	int[][][] arr_cnt; // 설치 거울 값 -> 계속 min 찾아나가야 함 + 방향에 따라서 갯수가 같아도 다르게 처리 피룡
	ArrayDeque<Pos> q;
	Pos start;
	Pos end;
	int max_val = 10001;
	public class Pos{
		int dir,cnt,y,x;
		public Pos(int dir, int cnt, int y, int x){
			this.dir = dir;
			this.cnt = cnt; // cnt: 사용 거울 갯수
			this.y = y;
			this.x = x;
		}
	}
	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		w = Integer.parseInt(input[0]);
		h = Integer.parseInt(input[1]);
		arr = new char[h][w];
		arr_cnt = new int[h][w][4];
		boolean isStart = true;
		for(int i=0; i<h; i++){
			String str = br.readLine();
			for(int j=0; j<w; j++){
				arr[i][j] = str.charAt(j);
				if(arr[i][j] == 'C'){
					if(isStart){
						start = new Pos(-1,0,i,j);
						isStart = false;
					}else{
						end = new Pos(-1,0,i,j);
					}
				}
				// 추가로 arr_cnt 초기화
				for(int k=0; k<4; k++){
					arr_cnt[i][j][k] = max_val;
				}
			}
		}

		// dir[4] 상,하,좌,우
 		// 거울 case0: /
		// 상 -> 우, 하 -> 좌, 좌 -> 상, 우-> 하
		// 거울 case1: \
		// 상 ->좌, 하 -> 우, 좌 -> 하, 우 -> 상
		// 결국 생각해보면 -> 직진하는 레이저가 거울을 만나면 방향이 90도로 바뀜
		// dir: 0 -> 2,3 : 1 -> 2,3  :  2 -> 0,1 : 3 -> 0,1
		// 상,하 -> 거울 설치시 좌우로 , 좌,우 -> 상하로
		// 해당 지역에 도달할 때 사용하는 거울의 갯수가 줄어드는 경우에는 -> q에 추가
		// 그렇지 않다면 무시
		// init start
		q = new ArrayDeque<>();
		for(int i=0; i<4; i++){
			q.add(new Pos(i,0, start.y, start.x));
		}

		while(!q.isEmpty()){
			Pos cur = q.poll();
			// ***목적지라면 정답 갱신후 break -> 이거 하면 안돼
			// why? 큐에 들어가는 순서가 방향 달라지는거 먼저 들어가는 경우 발생 가능

			for(int i=0; i<4; i++){
				if(!checkDir(cur.dir, i)) continue; // 진행방향의 반대 방향 스킵
				int ny = cur.y + dy[i];
				int nx = cur.x + dx[i];
				// 만약 방향이 진행방향과 다르다면 거울 갯수 +1
				int n_cnt = cur.dir == i ? cur.cnt : cur.cnt+1;
				// 방문 가능 여부
				if(!check(ny, nx)) continue;
				// 만약 전에 방문한 경우가 거울의 사용 갯수가 더 작거나 같다면 스킵 (방향 고려)
				if(arr_cnt[ny][nx][i] <= n_cnt){
					continue;
				}
				arr_cnt[ny][nx][i] = n_cnt;
				q.add(new Pos(i, n_cnt, ny, nx));
			}
		}
		for(int i=0; i<4; i++){
			answer = Math.min(answer, arr_cnt[end.y][end.x][i]);
		}
		bw.write(answer + " ");
		bw.flush();
	}

	public boolean checkDir(int d1, int d2){
		if((d1 == 0 && d2 == 1) || (d1 == 1 && d2 == 0)){
			return false;
		}
		if((d1 == 2 && d2 == 3) || (d1 == 3 && d2 == 2)){
			return false;
		}
		return true;
	}
	public boolean check(int y, int x){
		if( y<0 || x<0 || y>=h || x>= w || arr[y][x] == '*'){
			return false;
		}
		return true;
	}


	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}

