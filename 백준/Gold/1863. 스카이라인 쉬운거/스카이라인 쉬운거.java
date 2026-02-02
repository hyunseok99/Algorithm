import java.util.*;
import java.io.*;
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	// 높이가 달라지면 -> 새로운 빌딩 
	// 높이가 0이 생기면 -> 새로운 빌딩 시작 
	// 왼쪽 건물과 높이가 같은지 여부가 핵심 
	int n;
	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		Deque<Integer> s = new ArrayDeque<>(); 
		 
		// 건물+ 가 되는 경우 -> 높이 변동 -> 기존 높이보다 작아지면 이전것은 1개   
		// 이전 높이보다 높이가 낮아진다면 -> 이전거 pop, 건물+
		// 이전 높이와 같다면 -> 하나 ex) 3 -> 5 -> 3  
		int cnt = 0;
		for(int i=0; i<n; i++){
			input = br.readLine().split(" ");
			int y = Integer.parseInt(input[1]);
			
			// 건물이 높이가 내려가는 경우 현재 높이보다 높은 경우 모두 pop
			while(!s.isEmpty() && y < s.peek()){
				cnt++;
				s.pop();
			}
			// 높이가 만약 같다면 같은 건물 
			if(!s.isEmpty() && y == s.peek()){
				s.pop();
			}
			// 새로운 스타트 
			if(y > 0){
				s.push(y);
			}		
		}
		
		// stack에 남은 건물들도 정산 
		// ex) 7 -> 8 -> 9 : +3 
		while(!s.isEmpty()){
			cnt++;
			s.pop();
		}
		  
		bw.write(cnt + " ");  
		bw.flush();
	}

	public static void main(String[] args) throws IOException{  
	   Main ans = new Main();
	   ans.solution();
	}  
}