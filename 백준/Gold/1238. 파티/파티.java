import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n,m,x;
	int answer;
	int max_val = 10000001;
	class Node implements Comparable<Node> {
		int v, spot; // v: 누적 time
        public Node(){}
		public Node(int v, int spot){
			this.v = v;
			this.spot = spot;
		}
		@Override
		public int compareTo(Node o){
			return this.v - o.v; // 비용 작은게 먼저 나옴 
		}
	}
	
	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");  
		// 최대 가능 길이 n
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);
		x = Integer.parseInt(input[2]);
		ArrayList<Node>[] adj = new ArrayList[n+1]; // 정방향 (X에서 집으로)
		ArrayList<Node>[] rev_adj = new ArrayList[n+1]; // 역방향 (집에서 X로)
		
		for(int i=0; i<adj.length; i++){
			adj[i] = new ArrayList<>();
			rev_adj[i] = new ArrayList<>();
		}	
		
		for(int i=0; i<m; i++){
			input = br.readLine().split(" ");
			int u = Integer.parseInt(input[0]);
			int v = Integer.parseInt(input[1]);
			int t = Integer.parseInt(input[2]);
			adj[u].add(new Node(t,v));
			rev_adj[v].add(new Node(t,u));
		}
		
		// X에서 각 집으로 이동하는 최단 거리
		int[] fromX_list = dijkstra(x, adj);
		// 각 집에서 x까지 : 역방향 리스트를 이용해서 x에서 다른집까지의 최소가 해당 집에서 x까지 거리임 
		int[] toX_list = dijkstra(x, rev_adj);
		
		for(int i=1; i<=n; i++){
			if(fromX_list[i] != max_val && toX_list[i] != max_val){
				int time_sum = fromX_list[i] + toX_list[i];
				answer = Math.max(time_sum, answer);
			}
		}
		
		
		bw.write(answer + "");  
		bw.flush();
	}
	
	public int[] dijkstra(int start, ArrayList<Node>[] adj_list){
		PriorityQueue<Node> pq = new PriorityQueue<>();
		int[] dist = new int[n+1];
		for(int i=0; i<=n; i++){
			dist[i] = max_val;
		}
		pq.add(new Node(0,start));
		dist[start] = 0;
		
		while(!pq.isEmpty()){
			Node cur = pq.poll();
			int cur_spot = cur.spot;
			int val = cur.v;
			if(val > dist[cur_spot]) continue;
			
			// next
			for(Node next: adj_list[cur_spot]){
				int next_spot = next.spot;
				int next_val = next.v;
				if(dist[next_spot] > dist[cur_spot] + next_val){
					dist[next_spot] = dist[cur_spot] + next_val;
					pq.add(new Node(dist[next_spot], next_spot));
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