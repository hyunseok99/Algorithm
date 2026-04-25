import java.util.*;
import java.io.*;

class Main{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	static int T,N,M,K;
	public static class Node{
		int v,c,t; // v: node, c: cost. t: time
		public Node(int v, int c, int t){
			this.v = v;
			this.c = c;
			this.t = t;
		}
	}	
	public static void main(String[] args) throws IOException{  
		T = Integer.parseInt(br.readLine());
		//String[] inputs = br.readLine().split(" ");
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		// 기존 다익스트라 -> log N -> 코스트 고려 필요 -> log N*M
		// O( N * M  + K * logN)
		ArrayList<Node>[] adj = new ArrayList[N+1];
		for(int i=0; i<=N; i++){
			adj[i] = new ArrayList<>();
		}
		for(int i=0; i<K; i++){
			//inputs = br.readLine().split(" ");
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			adj[u].add(new Node(v,c,d));
		}
		// adj리스트를 cost 기준으로 정렬한다면 -> pq 정렬 필요 없음
		for(int i=0; i<=N; i++){
			Collections.sort(adj[i], (Node a, Node b) -> {return a.c - b.c;});
		}
		
		// 그냥 2차원 dp로 해결 가능 
		int[][] dp = new int[N+1][M+1];
		for(int i=0; i<=N; i++){
			Arrays.fill(dp[i], Integer.MAX_VALUE);
		}
		dp[1][0] = 0;
		for(int i=0; i<=M; i++){
			for(int u=1; u<=N; u++){
				if(dp[u][i] == Integer.MAX_VALUE) continue;
				
				for(Node next: adj[u]){
					int c_sum = i + next.c;
					int t_sum = dp[u][i] + next.t;
					
					if(c_sum <= M && dp[next.v][c_sum] > t_sum){
						dp[next.v][c_sum] = t_sum;
					}
				}
			}
		}
		
		int res = Integer.MAX_VALUE;
		for(int val: dp[N]){
			res = Math.min(res, val);
		}
		
		//int res = dijkstra(adj);
		if(res == Integer.MAX_VALUE){
			bw.write("Poor KCM");
		}else{
			bw.write(res + "");
		}
		bw.flush();
		
		return;
	} 
}