import java.util.*;
import java.io.*;
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n;
	int[] arr;
	StringBuilder sb = new StringBuilder();
	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		arr = new int[n];
		input = br.readLine().split(" ");
		for(int i=0; i<n; i++){
			arr[i] = Integer.parseInt(input[i]);
		}

		Deque<Integer> s = new ArrayDeque<>();
		Deque<Integer> s_idx = new ArrayDeque<>();

		for(int i=0; i<n; i++){
			int height = Integer.parseInt(input[i]);
			// cur <= next -> 신호 못받음
			while(!s.isEmpty() && s.peek() < height){
				s.pop();
				s_idx.pop();
			}
			// 스택이 비었으면 왼쪽에 현재보다 높은 탑 x
			if(s.isEmpty()){
				sb.append("0 ");
			}else{
				// 스택에 남아 있는 탑이 가장 가깝고 나보다 큰 왼쪽에 있는 탑
				sb.append(s_idx.peek()).append(" ");
			}
			// 현재 탑을 스택에 추가
			s.push(height);
			s_idx.push(i+1);
		}

		bw.write(sb.toString());
		bw.flush();
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}
