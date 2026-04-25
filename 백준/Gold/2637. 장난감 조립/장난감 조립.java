import java.util.*;
import java.io.*;
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n, m;
	int[][] mem;
	ArrayList<Integer>[] target;
	Map<Pair, Integer> my_map = new HashMap<>();
	public class Pair{
		int target, material;
		public Pair(int target, int material){
			this.target = target;
			this.material = material;
		}

		@Override
		public boolean equals(Object o){
			if(o instanceof Pair){
				Pair tmp = (Pair)o;
				return (this.target == tmp.target && this.material == tmp.material);
			}
			return false;
		}

		@Override
		public int hashCode(){
			return Objects.hash(this.target, this.material);
		}
	}

	public void solution() throws IOException{
		String input = br.readLine();
		n = Integer.parseInt(input);
		mem = new int[n+1][n+1]; // 부품 x를 만드는데 필요한 부품y의 갯수
		input = br.readLine();
		m = Integer.parseInt(input);
		target = new ArrayList[n+1];
		for(int i=0; i<=n; i++){
			target[i] = new ArrayList<>();
		}

		for(int i=0; i<m; i++){
			String[] inputs = br.readLine().split(" ");
			int x = Integer.parseInt(inputs[0]);
			int y = Integer.parseInt(inputs[1]);
			int k = Integer.parseInt(inputs[2]);
			target[x].add(y);
			my_map.put(new Pair(x,y), k);
		}

		// 하나의 중간 부품을 만드는데 필요 재료가 여러개 가능
		// ex) x만드는데 1 2개, 5 1개  (target, material)은 유일
		// arr[x] = {1, 5} -> map에 (x,1) -> 2, (x,5) -> 1
		// + 더 이상 down이 없으면 기본 부품

		// topDown(n, visit); -> O(n+m)
		boolean[] visit = new boolean[n+1]; // memoization 계산 되어 있는지 여부
		topDownMemo(n, visit);

		for(int i=1; i<=n; i++){
			if(mem[n][i] != 0){
				bw.write(i + " " + mem[n][i] + "\n");
			}
		}
		bw.flush();
	}

	public void topDownMemo(int x, boolean[] visit){
		if(visit[x] == true){
			// 이미 기본 부품 계산 완료인 경우
			return;
		}

		// 기본 부품이면 정답 갱신 및종료
		if(target[x].isEmpty()){
			mem[x][x] = 1; // 자기 자신 1개
			visit[x] = true;
			return;
		}

		// 하위 재료 계산
		for(int y: target[x]){
			topDownMemo(y, visit); // 자식 memoization 수행 하고
			// {x, y} -> k
			int val = my_map.get(new Pair(x, y));
			for(int i=1; i<=n; i++){
				// mem이 갱신 되어 있으면 추가
				if(mem[y][i] > 0){
					mem[x][i] += mem[y][i] * val;
				}
			}
		}

		visit[x] = true;
		return;
	}


	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}
