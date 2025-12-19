import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	int n, m;
	int[] dy = {-1, 1, 0, 0};
	int[] dx = {0, 0, -1, 1};
	int[][] arr; // 수영장 높이 배열
	boolean[][] flag; // 수영장 방문 체크
	int answer = 0;
	class Pair{
		int y,x;
		public Pair(int y, int x){
			this.y = y;
			this.x = x;
		}
	}

	public void solution() throws IOException{
		// br.readLine(); bw.write();
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);
		arr = new int[n][m]; //
		flag = new boolean[n][m];
		for(int i=0; i<n; i++){
			String line = br.readLine();
			for(int j=0; j<m; j++){
				arr[i][j] = Integer.parseInt(line.charAt(j)+"");
			}
		}

		while(true){
			boolean isFullFilled = false; // 더이상 물을 채울 수 없으면 false
			flag = new boolean[n][m]; // flag 초기화
			// 블럭들 좌표
			ArrayList<ArrayList<Pair>> blocks = new ArrayList<>();
			// 칸을 높이에 따라 구분해서 블럭단위로 -> 내부가 될 수 있는 블럭에 한해서
			for(int y=0; y<n; y++){
				for(int x=0; x<m; x++){
					if(flag[y][x]) continue;
					ArrayList<Pair> tmp = new ArrayList<>();
					Queue<Pair> q = new LinkedList<>();
					Pair p = new Pair(y,x);
					q.add(p);
					tmp.add(p);
					flag[y][x] = true;
					while(!q.isEmpty()){
						Pair cur = q.poll();
						int cur_y = cur.y;
						int cur_x = cur.x;
						for(int dir=0; dir<4; dir++){
							int ny = cur_y + dy[dir];
							int nx = cur_x + dx[dir];
							if(ny >= 0 && nx >= 0 && ny < n && nx < m){
								// 높이가 같다면 같은 블럭에 포함
								if(arr[ny][nx] == arr[cur_y][cur_x] && !flag[ny][nx]){
									flag[ny][nx] = true;
									Pair next = new Pair(ny, nx);
									q.add(next);
									tmp.add(next);
								}
							}
						}
					}
					blocks.add(tmp);
				}
			}

            // 높이가 변경되는 좌표들
            ArrayList<Pair> changed  = new ArrayList<>();
            ArrayList<Integer> changed_h = new ArrayList<>();
			// 블럭들을 가지고 이제 물을 채울 수 있는 경우가 존재하는지 연산
			for(ArrayList<Pair> block: blocks){
				if(isInside(block, changed, changed_h)){
					// 물을 채울 수 있는지 여부
					isFullFilled = true;

				}
			}

            // 물 높이 변경 반영
            for(int i=0; i<changed.size(); i++){
                Pair pos = changed.get(i);
                int n_height = changed_h.get(i);
                arr[pos.y][pos.x] = n_height;
            }

			if(!isFullFilled){
				break;
			}
		}
		bw.write(answer + "");
		bw.flush();
	}
	//  내부에 존재하는 경우 물 채우기
	public boolean isInside(ArrayList<Pair> block, ArrayList<Pair> changed, ArrayList<Integer> changed_h){
		// 블럭을 구성하는 좌표들이 둘러 쌓여 있는 경우에는 물을 채울 수 있다
		int target_h = Integer.MAX_VALUE;
		int h = arr[block.get(0).y][block.get(0).x];
		boolean isIn = true;
		for(Pair pos: block){
			int y = pos.y;
			int x = pos.x;
			int cur_h =  arr[y][x];
			// 상하좌우
			for(int dir=0; dir<4; dir++){
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				// 내부의 좌표이면서
				if(ny >= 0 && nx >= 0 && ny < n && nx < m ){
					if(cur_h == arr[ny][nx]){
						// 동일 블럭
						continue;
					}
					if(cur_h < arr[ny][nx]){
						// 바깥 블럭
						target_h = Math.min(target_h, arr[ny][nx]);
					}
					if( cur_h > arr[ny][nx]){
						isIn = false;
						break;
					}
				}else{
                    // 바깥쪽 블럭이 cur이면 내부 불가
                    isIn = false;
                    break;
                }
			}
		}
		if(isIn){
			// 채운 물을 정답에 추가하고 변할 칸의 좌표와 바뀔 높이 저장
			for(Pair pos: block){
				answer += target_h - h; 
                changed.add(pos);
                changed_h.add(target_h);
			}
		}
		return isIn;
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
       ans.solution();
	}
}
