import java.util.*;
import java.io.*;


class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	int n;
	// [x, y] -> x를 짓기위해 y 필요  
	Map<Integer, Set<Integer>> required = new HashMap<>();
	int[] dur; // 건물 짓는 시간
	int[] memo; // 최소 시간 메모이제이션 
	public void solution() throws IOException{
		// br.readLine(); bw.write();
		n = Integer.parseInt(br.readLine());
		dur = new int[n+1];
		memo = new int[n+1];
		for(int i=1; i<=n; i++){
			String[] str = br.readLine().split(" ");
			// str[] length가 3이면 -> 선행되는 건물 있음 
			if(str.length >= 3){
				Set<Integer> tmp = new HashSet<>();
 				for(int j=1; j<str.length-1; j++){
						tmp.add(Integer.parseInt(str[j]));
				}
				required.put(i, tmp);
			}else{
				memo[i] = Integer.parseInt(str[0]);
			}
			dur[i] = Integer.parseInt(str[0]);
		}
		
		// 1~n 까지 출력 
		for(int i=1; i<=n; i++){
			bw.write(getMemo(i) + "\n");
		}
		bw.flush();
	}
	// 건물 x를 짓는데 필요한 최소 시간  
	public int getMemo(int x){
		if(x > n){
			return 0;
		}
		if(memo[x] != 0){
			return memo[x];
		}
		
		// 선행되어야 하는 건물의 memoization 미갱신시 -> 탐색 
		int sum_t = dur[x];
		if(required.containsKey(x)){
			int max_v = 0;
			for(int element: required.get(x)){
				max_v = Math.max(max_v, getMemo(element));
			}
			sum_t += max_v;
		}
		memo[x] = sum_t;
		return memo[x];
	}

	public static void main(String[] args) throws IOException{
		Main tmp = new Main();
		tmp.solution();
	}
}

