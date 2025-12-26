import java.util.*;
import java.io.*;
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	int n, m;
	int[][] arr;
	boolean[][] flag;
	int[][] block;
	int[] dy ={-1, 1, 0, 0};
	int[] dx ={0, 0, -1, 1};
	Map<Integer, Integer> block_size; // {block_number, size};
	int block_init = 0;
	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);
		arr = new int[n][m];
		block = new int[n][m];
		flag = new boolean[n][m];
		block_size = new HashMap<>();
		for(int i=0; i<n; i++){
			String str = br.readLine();
			for(int j=0; j<m; j++){
				arr[i][j] = Integer.parseInt(str.charAt(j)+"");
			}
		}

		// 0 블럭들 구분
		int block_number = 1;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(arr[i][j] == 0 && !flag[i][j]){
					block_init = 0;
					makeBlock(i, j, block_number);
					block_size.put(block_number, block_init);
					block_number++;
				}
			}
		}

		// 결과 연산
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(arr[i][j] == 0){
					bw.write("0");
				}else{
					// 상하좌우 0블럭들 합
					Set<Integer> my_set = new HashSet<>();
					for(int dir =0; dir<4; dir++){
						int ny = i + dy[dir];
						int nx = j + dx[dir];
						if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
						if(block[ny][nx] != 0){
							my_set.add(block[ny][nx]);
						}
					}
					int ans = 1;
					for(Integer val: my_set){
						ans += block_size.get(val);
					}
					ans %= 10;
					bw.write(ans+"");
				}
			}
			bw.write("\n");
		}
		bw.flush();
	}

	public void makeBlock(int y, int x, int num){
		if(!flag[y][x]){
			flag[y][x] = true;
			block[y][x] = num;
			block_init++;
			for(int dir=0; dir<4; dir++){
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if(nx >= 0 && ny >= 0 && nx < m && ny < n && !flag[ny][nx] && arr[ny][nx] == 0){
					makeBlock(ny, nx, num);
				}
			}
		}
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}

