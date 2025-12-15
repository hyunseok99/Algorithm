import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	int n, m;
	int[] memo; // degree저장: 특정 문제를 풀기위해서 선행되어야 하는 문제의 수 ex) memo[3] = {1,4} , 3번 문제를 풀기위해서 1,4번 문제 선행되어야 함
	Map<Integer, Set<Integer>> my_map; // my_map[x]: x에 선행되어야하는 문제들 정렬o
	ArrayList<Integer>[] list; // list[x] = {y, z} : x를 풀면 -> y,z를 풀어도 된다. 즉 선행되는게 x
	int[] dy = {-1, 1, 0, 0};
	int[] dx = {0, 0, -1, 1};
	public void solution() throws IOException{
		// br.readLine(); bw.write();
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);
		memo = new int[n+1];
		my_map = new HashMap<>();
		list = new ArrayList[n+1];
		for(int i=0; i< list.length; i++){
			list[i] = new ArrayList<>();
		}

		for(int i=1; i<=m; i++){
			String[] str = br.readLine().split(" ");
			int first_element = Integer.parseInt(str[0]); // 선행 조건
			int second_element = Integer.parseInt(str[1]); // 이후 풀 수 있음
			list[first_element].add(second_element);
			memo[second_element]++; // 차수 증가
		}

		// 차수를 통해서 가장 작은 차수의 문제 순으로 해결
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		for (int i=1; i<=n; i++){
			if(memo[i] == 0){
				pq.add(i);
			}
		}

		// 선행 조건 달성 해결하며 순서대로 문제 풀기
		while(!pq.isEmpty()){
			int cur = pq.poll();
			bw.write(cur +" ");
			for(int next: list[cur]){
				memo[next] -= 1;
				if(memo[next] == 0){
					// 선행 조건 만족하면 대기열에 추가
					pq.add(next);
				}
			}
		}

		bw.flush();
	}


	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}

