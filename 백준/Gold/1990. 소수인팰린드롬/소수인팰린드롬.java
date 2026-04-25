import java.util.*;
import java.io.*;
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int a, b;
	boolean[] arr; // 소수 여부 메모리 <- 256MB라 boolean 
	int max_val = 100000000;
	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		a = Integer.parseInt(input[0]);
		b = Integer.parseInt(input[1]);
		arr = new boolean[max_val+1];
		// 550 -> 055 : 어차피 소수 x

		// i*i <= max_val -> O(n log log n)
		for(int i=2; i*i<=max_val; i++){
			if(!arr[i]){
				for(int j=i*i; j <= max_val; j+=i){
					arr[j] = true;
				}
			}
		}

		// check palindrome O(n * log n)
		while(a <= b){
			if(!arr[a]){
				boolean flag = true;
				String str_a = a + "";
				int end = str_a.length()-1;
				for(int start= 0; start<=end; start++, end--){
					if(str_a.charAt(start) != str_a.charAt(end)){
						flag = false;
						break;
					}
				}
				if(flag){
					bw.write(a + "\n");
				}
			}
			a++;
		}
		bw.write("-1");
		bw.flush();
	}


	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}

