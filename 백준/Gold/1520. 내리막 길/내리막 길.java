import java.io.*;
import java.util.*;

// (0,0) -> (m-1, n-1)
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	int n, m;
	int[][] arr; // 경로 높이 배열
	int[][] memo; // 가능 경로 갯수 메모이제이션
	int[] dy = {-1, 1, 0, 0};
	int[] dx = {0, 0, -1, 1};
	public void solution() throws IOException{
		// br.readLine(); bw.write();
		String[] input = br.readLine().split(" ");
		m = Integer.parseInt(input[0]);
		n = Integer.parseInt(input[1]);
		arr = new int[m][n];
		memo = new int[m][n];
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				memo[i][j] = -1;
			}
		}
		// 시작 위치 init
		memo[0][0] = 1;

		for(int i=0; i<m; i++){
			String[] str = br.readLine().split(" ");
			for(int j=0; j<n; j++){
				arr[i][j] = Integer.parseInt(str[j]);
			}
		}
		// 목적지까지 가능한 경우의 수 return
		bw.write(getMemo(m-1, n-1, -1) + " ");
		bw.flush();
	}
	// y,x 위치까지 이동하는데 가능한 경우의 수
	public int getMemo(int y, int x, int next_height){
		// 이동 불가능한 경우
		if(y < 0 || y >= m || x < 0 || x >= n){
			return 0;
		}
		// 높이 조건 만족 x
		if(arr[y][x] <= next_height){
			return 0;
		}
		// 높이조건을 만족하면서 가능한 경우
		if(memo[y][x] != -1 ){
			return memo[y][x];
		}

		// 해당 경우가 높이 조건을 만족하는지 여부
		int cnt = 0;

		// 해당 위치의 상하좌우에서 가능한경우
		for(int dir=0; dir<4; dir++){
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			cnt += getMemo(ny, nx, arr[y][x]);
		}
		memo[y][x] = cnt;
		return memo[y][x];
	}

    public static void main(String[] args) throws IOException{
        Main ans = new Main();
        ans.solution();
    }
}
