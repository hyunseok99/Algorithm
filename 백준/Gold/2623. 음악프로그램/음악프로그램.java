import java.util.*;
import java.io.*;

class Main{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	static int N,M;
	
	// ex) arr[3] = {1,4,5} : 3앞에 1,4,5 나와야 함  
	static ArrayList<Integer>[] arr;
	
	public static void main(String[] args) throws IOException{  
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new ArrayList[N+1];
		for(int i=0; i<=N; i++){
			arr[i] = new ArrayList<>();
		}
		int[] inDegree = new int[N+1]; // 조건 차수
		
		for(int i=0; i<M; i++){
			st = new StringTokenizer(br.readLine());
			int size = Integer.parseInt(st.nextToken());
			int start = Integer.parseInt(st.nextToken());
			for(int j = 1; j < size; j++){
				int next = Integer.parseInt(st.nextToken());
				arr[start].add(next);
				inDegree[next]++; // 차수 증가 // 1 3 -> 3 앞에 1 필요 
				start = next;
			}
		}
		
		// 진입 차수가 0인 경우 부터 시작 
		Deque<Integer> q = new ArrayDeque<>();
		for(int i=1; i<=N; i++){
			if(inDegree[i] == 0){
				q.add(i);
			}
		}
		ArrayList<Integer> res = new ArrayList<>();
		
		while(!q.isEmpty()){
			int cur = q.poll();
			res.add(cur);
			
			// 현재 노드와 연결된 다음 노드들의 차수를 -1 
			for(int next: arr[cur]){
				inDegree[next]--;
				if(inDegree[next] == 0){
					q.add(next);
				}
			} 
		}
		// 모순 존재
		if(res.size() != N){
			bw.write("0");
		}else{
			for(int v: res){
				bw.write(v + "\n");
			}
		}
		bw.flush();
		return;
	}  
}