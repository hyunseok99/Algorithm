import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int T, n, k;

	// 뒤에서 지운 경우, 지우지 않은 경우를 다시 q에 삽입해서 k번 다 지운 경우 정답 갱신
	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
 		n = Integer.parseInt(input[0]);
 		k = Integer.parseInt(input[1]);

 		String str = br.readLine();
 		int del = 0;

		Deque<Character> d = new ArrayDeque<>();
		for(int i=0; i<n; i++){
			char s = str.charAt(i);
			// d.peek < s : pop
			while( (del < k) && !d.isEmpty() && d.peek() < s){
				d.pop();
				del++;
			}
			d.push(s);
		}

 		// ex) 5421  -> k:2
 		while(del < k){
	 		d.pop();
	 		del++;
 		}

 		StringBuilder sb = new StringBuilder();

		// d: 54
 		while(!d.isEmpty()){
             // sb에 추가 후 reverse
             sb.append(d.pop());
        }

		bw.write(sb.reverse().toString());
		bw.flush();
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}