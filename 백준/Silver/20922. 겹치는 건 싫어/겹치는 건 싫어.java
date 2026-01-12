import java.util.*;
import java.io.*;

public class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n,k;
	int answer;
	int[] mem;
	int[] arr;
	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		k = Integer.parseInt(input[1]);
		arr = new int[n+1];
		mem = new int[100001];
		input = br.readLine().split(" ");
		for(int i=1; i<=n; i++){
			arr[i] = Integer.parseInt(input[i-1]);
		}

		int j=1;
		for(int i=1; i<=n; i++){
			mem[arr[i]]++;
			// k 초과하면 j--
			while(mem[arr[i]] > k){
				mem[arr[j]]--;
				j++;
			}
			answer = Math.max(answer, i-j+1);
		}
		bw.write(answer + "");
		bw.flush();
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}
