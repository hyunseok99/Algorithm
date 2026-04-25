import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n,m;
	long answer;
	class Node implements Comparable<Node>{
		int v;
		long weight;
		public Node(int v, long weight){
			this.v = v;
			this.weight = weight;
		}
		@Override
		public int compareTo(Node o){
			// 중량이 큰것 pop

			return Long.compare(o.weight, this.weight);
		}
	}

	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		// 최대 가능 길이 n
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);
		ArrayList<Node>[] adj = new ArrayList[n+1];
		for(int i=0; i<=n; i++){
			adj[i] = new ArrayList<>();
		}

		for(int i=0; i<m; i++){
			input = br.readLine().split(" ");
			int a = Integer.parseInt(input[0]);
			int b = Integer.parseInt(input[1]);
			long c = Long.parseLong(input[2]);
			
			adj[a].add(new Node(b,c));
            adj[b].add(new Node(a,c));
		}

		input = br.readLine().split(" ");
		int start = Integer.parseInt(input[0]);
		int end = Integer.parseInt(input[1]);

		// 다익스트라 -> O(mlogn) 100000 * 17
		long[] dist = dijkstra(start, adj);
		answer = dist[end];
		bw.write(answer + "");
		bw.flush();
	}

	public long[] dijkstra(int start, ArrayList<Node>[] adj){
		long[] dist = new long[n+1];
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(start, Long.MAX_VALUE));
		dist[start] = Long.MAX_VALUE;
		while(!pq.isEmpty()){
			Node cur = pq.poll();
			int cur_v = cur.v;
			long cur_weight = cur.weight;
			if(dist[cur_v] > cur_weight) continue;

			for(Node next: adj[cur_v]){
				int next_v = next.v;
				long next_weight = next.weight;
				if(dist[next_v] < Math.min(dist[cur_v],  next_weight)){
					dist[next_v] = Math.min(dist[cur_v], next_weight);
					pq.add(new Node(next_v, dist[next_v]));
				}
			}
		}
		return dist;
	}


	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}

