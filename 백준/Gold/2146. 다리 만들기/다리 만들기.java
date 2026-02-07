import java.util.*;
import java.io.*;
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n;
	int[] dy = {-1,1,0,0};
	int[] dx = {0,0,-1,1};
	int[][] arr;
	int min_len = 10001;
	public class Pos{
		int y,x;
		public Pos(int y, int x){
			this.y = y;
			this.x = x;
		}
	}
	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		arr = new int[n][n];
		for(int i=0; i<n; i++){
			input = br.readLine().split(" ");
			for(int j=0; j<n; j++){
				arr[i][j] = Integer.parseInt(input[j]);
			}
		}
		// 섬들을 정의 + 섬들간의 거리 차이가 최소 + 해당 거리를 잇는 구도에 다른 섬 있으면 안된다.
		// 1. 섬들을 구분 -> 2. 섬들끼리 비교 -> 3. 실제 설치 가능한지 여부 + 최소
		// 2번 섬부터 ~ 설정해서 바로 확인하기 쉽게 구성
		// O(n^2)
		boolean[][] flags = new boolean[n][n];
		int island_idx = 2; // 바꿀 섬들 idx
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(arr[i][j] == 1 && !flags[i][j]){
					Deque<Pos> q = new ArrayDeque<>();

					flags[i][j] = true;
					arr[i][j] = island_idx;
					q.add(new Pos(i,j));
					while(!q.isEmpty()){
						Pos cur = q.poll();
						for(int dir=0; dir<4; dir++){
							int ny = cur.y + dy[dir];
							int nx = cur.x + dx[dir];
							if(ny < 0 || nx < 0 || ny>=n || nx >= n ||
							 flags[ny][nx] || arr[ny][nx] == 0) continue;
							q.add(new Pos(ny,nx));
							flags[ny][nx] = true;
							arr[ny][nx] = island_idx;
						}
					}
					island_idx++;
				}
			}
		}
		// 총 섬의 idx 2 ~ island_idx
		// 섬들간의 조합 -> O(10000 * 10000) ~= 1억
		for(int i=2; i<island_idx; i++){
			judgeMake(i);
		}

		bw.write(min_len + " ");
		bw.flush();
	}

	// 이미 설치 가능한 다리보다 짧고 설치 가능하고 길이 더 작아지면 길이 갱신
	public void judgeMake(int island_idx){
		Deque<Pos> q = new ArrayDeque<>();
		Deque<Integer> bridge_len = new ArrayDeque<>(); // 누적 설치 다리길이

		boolean[][] flags = new boolean[n][n]; // 방문 체크
		// init 해당 island_idx 섬들을 q에 삽입
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(arr[i][j] == island_idx){
					q.add(new Pos(i,j));
					flags[i][j] = true;
					bridge_len.add(0);
				}
			}
		}
		while(!q.isEmpty()){
			Pos cur_pos = q.poll();
			int cur_len = bridge_len.poll();
			if(cur_len >= min_len) continue;

			for(int dir=0; dir<4; dir++){
				int ny = cur_pos.y + dy[dir];
				int nx = cur_pos.x + dx[dir];
				if(ny < 0 || nx < 0 || ny >= n || nx >= n ){
					continue;
				}
				// 만약 바다를 만난다면 다리길이 + 1
				if(arr[ny][nx] == 0 && !flags[ny][nx]){
					flags[ny][nx] = true;
					q.add(new Pos(ny, nx));
					bridge_len.add(cur_len + 1);
				}
				// 만약 다른 섬의 육지라면 종료
				if(arr[ny][nx] != 0 && arr[ny][nx] != island_idx){
					min_len = Math.min(min_len, cur_len);
					return;
				}

			}
		}
		return;
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}
