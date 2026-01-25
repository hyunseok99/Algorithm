import java.util.*;
import java.io.*;


class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	int n, m, k;

	int[][] arr;
	ArrayList<Pos> list;
	int answer = 0;
	public class Pos{
		int y,x;
		int type;
		int sum; // 가중치 합
		public Pos(int y, int x, int type, int sum){
			this.y = y;
			this.x = x;
			this.type = type;
			this.sum = sum;
		}
	}
	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);
		arr = new int[n][m];
		// 만들 수 있는 최대 부매랑 갯수: n*m / 3
		// 1 1 1      -> 1 + 2 + 100 + 1 + 2 + 1 =107
		// 1 100 1    -> 2*100 + 1 + 1 = 202

		// 무조건 최대의 부메랑을 만드는게 최대가 아님
		// 가능한 경우의 0 ~ 최대 가능 경우까지 고려 필요

		list = new ArrayList<>();

		// 만들 수 있는 부메랑 모든 경우 + 강도가 최대가 되는 경우
		for(int i=0; i<n; i++){
			input = br.readLine().split(" ");
			for(int j=0; j<m; j++){
				arr[i][j] = Integer.parseInt(input[j]);
			}
		}

		// 부메랑 1개로 만드는 경우 초기화
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				addBoom(i,j);
			}
		}

		// 만들 수 있는 부메랑들의 모든 조합 중 강도 최대
		getTrack(0, 0, 0, new boolean [n][m]);
		bw.write(answer + " ");
		bw.flush();
	}
	// 백트래킹을 통해 가능한 최대 강도 뽑기
	public void getTrack(int depth, int sum, int idx, boolean[][] flags){

		for(int i=idx; i<list.size(); i++){
			// 추가 가능하면 추가하고 다음 depth
			Pos tmp = list.get(i);
			int y = tmp.y;
			int x = tmp.x;
			int left = x-1;
			int right = x+1;
			int up = y-1;
			int down = y+1;

			if(!flags[y][x] && tmp.type == 0){
				if(left >= 0 && down < n && !flags[y][left] && !flags[down][x]){
					flags[y][x] = true;
					flags[y][left] = true;
					flags[down][x] = true;
					sum += tmp.sum;
					getTrack(depth+1, sum, i, flags); // rec
					sum -= tmp.sum;
					flags[y][x] = false;
					flags[y][left] = false;
					flags[down][x] = false;
				}
			}

			if(!flags[y][x] && tmp.type == 1){
				if(left >= 0 && up >= 0 && !flags[y][left] && !flags[up][x]){
					flags[y][x] = true;
					flags[y][left] = true;
					flags[up][x] = true;
					sum += tmp.sum;
					getTrack(depth+1, sum, i, flags); // rec
					sum -= tmp.sum;
					flags[y][x] = false;
					flags[y][left] = false;
					flags[up][x] = false;
				}
			}

			if(!flags[y][x] && tmp.type == 2){
				if(up >= 0 && right < m && !flags[y][right] && !flags[up][x]){
					flags[y][x] = true;
					flags[y][right] = true;
					flags[up][x] = true;
					sum += tmp.sum;
					getTrack(depth+1, sum, i, flags);
					sum -= tmp.sum;
					flags[y][x] = false;
					flags[y][right] = false;
					flags[up][x] = false;
				}
			}

			if(!flags[y][x] && tmp.type == 3){
				if(down < n && right < m && !flags[y][right] && !flags[down][x]){
					flags[y][x] = true;
					flags[y][right] = true;
					flags[down][x] = true;
					sum += tmp.sum;
					getTrack(depth+1, sum, i, flags);
					sum -= tmp.sum;
					flags[y][x] = false;
					flags[y][right] = false;
					flags[down][x] = false;
				}
			}
		}
		// 더 이상 추가 불가하면 정답 갱신 후 return
		answer = Math.max(answer, sum);
		return;
	}
	// 초기 부메랑 형성
	public void addBoom(int y, int x){
		int left = x-1;
		int right = x+1;
		int up = y-1;
		int down = y+1;

		// type 0
		if(left >= 0 && down < n){
			int val = arr[y][x] * 2 + arr[y][left] + arr[down][x];
			list.add(new Pos(y, x, 0, val));
		}

		if(left >= 0 && up >= 0){
			int val = arr[y][x] * 2 + arr[y][left] + arr[up][x];
			list.add(new Pos(y, x, 1, val));
		}

		if(up >= 0 && right < m){
			int val = arr[y][x] * 2 + arr[y][right] + arr[up][x];
			list.add(new Pos(y, x, 2, val));
		}

		if(down < n && right < m){
			int val = arr[y][x] * 2 + arr[y][right] + arr[down][x];
			list.add(new Pos(y, x, 3, val));
		}
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}