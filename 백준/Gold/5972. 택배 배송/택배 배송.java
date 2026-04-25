import java.util.*;
import java.io.*;
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n,m;
	int ans;
	ArrayList<Edge>[] adj;

	public class Edge implements Comparable<Edge>{
		int weight, v;
		public Edge(int weight, int v){
			this.weight = weight;
			this.v = v;
		}

		@Override
		public int compareTo(Edge e){
			// 오름차순 -> min-heap
			return Integer.compare(this.weight, e.weight);
		}

	}

	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);
		adj = new ArrayList[n+1];
		for(int i=0; i<=n; i++){
			adj[i] = new ArrayList<>();
		}

		for(int i=0; i<m; i++){
			input = br.readLine().split(" ");
			int a = Integer.parseInt(input[0]);
			int b = Integer.parseInt(input[1]);
			int w = Integer.parseInt(input[2]);
			adj[a].add(new Edge(w,b));
			adj[b].add(new Edge(w,a));
		}
		ans = dijkstra(n);
		bw.write(ans + " ");
		bw.flush();
	}

	// start = 6, find min 6 to 1
	public int dijkstra(int start){

		int[] dist = new int[n+1];
		for(int i=0; i<=n; i++){
			dist[i] = Integer.MAX_VALUE;
		}
		PriorityQueue<Edge> pq = new PriorityQueue<>();
		pq.add(new Edge(0,start));
		dist[start] = 0;

		while(!pq.isEmpty()){
			Edge cur = pq.poll();
			int cur_w = cur.weight;
			int cur_v = cur.v;
			if(dist[cur_v] < cur_w) continue;
			for(Edge next: adj[cur_v]){
				int next_w = next.weight;
				int next_v = next.v;
				if(dist[next_v] > dist[cur_v] + next_w){
					dist[next_v] = dist[cur_v] + next_w;
					pq.add(new Edge(dist[next_v], next_v));
				}
			}
		}

		// 방문불가면 그냥 -1
		return dist[1] != Integer.MAX_VALUE ? dist[1] : -1;
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}