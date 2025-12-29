import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	int n, m;
	
	// 음의 간선 x 
	// n <= 100
	// O(n^3)
	int[][] cost; // x -> y 최저 코스트   
	int max_cost = 100000000;
	int answer = 0;
	public void solution() throws IOException{
		// br.readLine(); bw.write();
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		input = br.readLine().split(" ");
		m = Integer.parseInt(input[0]);
		
		cost = new int[n+1][n+1];
		for(int i=0; i<=n; i++){
			for(int j=0; j<=n; j++){
				cost[i][j] = max_cost;
				if(i == j){
					cost[i][j] = 0;
				}
			}
		}
		for(int i=0; i<m; i++){
			input = br.readLine().split(" ");
			int a = Integer.parseInt(input[0]);
			int b = Integer.parseInt(input[1]);
			int c = Integer.parseInt(input[2]);
			cost[a][b] = Math.min(cost[a][b], c);
		}
		
		// 1~n 노드까지 최단 거리 계산
		// k노드 경유
		for(int k=1; k<=n; k++){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					if(cost[i][j] > cost[i][k] + cost[k][j]){
						cost[i][j] = cost[i][k] + cost[k][j];
					}
				}	
			}
		}
		
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(cost[i][j] == max_cost){
					bw.write("0 ");
				}else{
					bw.write(cost[i][j] + " ");
				}
			}
			bw.write("\n");
		}
		
		bw.flush();
	}
	
	
	public static void main(String[] args) throws IOException{  
	   Main ans = new Main();
	   ans.solution();
	}  
}
