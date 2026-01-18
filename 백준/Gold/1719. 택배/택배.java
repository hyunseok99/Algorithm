import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n,m;
	long answer;
	public class Node implements Comparable<Node>{
		int v, weight;
		public Node(int v, int weight){
			this.v = v;
			this.weight = weight;
		}

		@Override
		public int compareTo(Node o){
			// 누적 시간이 짧은게 우선해서 나와야 함 min-heap
			return Integer.compare(this.weight, o.weight);
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
			int c = Integer.parseInt(input[2]);
			adj[a].add(new Node(b,c));
			adj[b].add(new Node(a,c));
		}

		// n개 지점을 시작으로 다익스트라 -> O(n * m * logn)
		int[][] spots = new int[n+1][n+1];
		for(int i=1; i<=n; i++){
			spots[i] = dijkstra(i, adj);
		}

		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i == j){
					bw.write("-" + " ");
				}else{
					bw.write(spots[i][j] + " ");
				}
			}
			bw.write("\n");
		}

		bw.flush();
	}


	// start: 시작 지점, arrived:도착 지점, spot: 이전에 지나온 집하장
	public int getFirstSpot(int start, int arrived, int[]spot){
	    if(start == arrived) return 0;
		int cur = arrived;
		while(spot[cur] != start){
			cur = spot[cur];
		}
		return cur;
	}

	public int[] dijkstra(int start, ArrayList<Node>[] adj){
		int[] dist = new int[n+1];
		int[] spot = new int[n+1]; // 해당 spot 도착 이전 spot
		int[] first_spot = new int[n+1];
		first_spot[start] = start;
		for(int i=1; i<=n; i++){
			dist[i] = Integer.MAX_VALUE;
		}
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(start, 0));
		dist[start] = 0;
		while(!pq.isEmpty()){
			Node cur = pq.poll();
			int cur_v = cur.v;
			int cur_weight = cur.weight;
			if(dist[cur_v] < cur_weight) continue;

			for(Node next: adj[cur_v]){
				int next_v = next.v;
				int next_weight = next.weight;
				if(dist[next_v] > dist[cur_v] + next_weight){
					dist[next_v] = dist[cur_v] + next_weight;
					spot[next_v] = cur_v;
					pq.add(new Node(next_v, dist[next_v]));
				}
			}
		}
		for(int i=1; i<=n; i++){
			first_spot[i] = getFirstSpot(start, i, spot);
		}
		return first_spot;
	}



	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}

