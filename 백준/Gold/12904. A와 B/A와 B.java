import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n,m;
	int answer;
	public void solution() throws IOException{
		String S = br.readLine();
		String T = br.readLine();
		m = S.length();
		n = T.length();

		// 결국 뒤에 A 또는 B가 붙는게 한가지임
		while(T.length() > S.length()){
			if(T.charAt(T.length()-1) == 'A'){
				// A 제거
				T = T.substring(0, T.length()-1);
			}else{
				// B 제거 후 reverse
				T = new StringBuilder(T.substring(0, T.length()-1)).reverse().toString();
			}
		}
		if(T.equals(S)){
			answer = 1;
		}
		bw.write(answer + "");
		bw.flush();
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}
