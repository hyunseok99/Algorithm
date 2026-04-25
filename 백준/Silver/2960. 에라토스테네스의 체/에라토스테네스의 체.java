import java.util.*;
import java.io.*;
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	int n, k;
	int[] arr; // 소수 check 여부 
	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		k = Integer.parseInt(input[1]);
		arr = new int[n+1];
		
		int removed_cnt = 0;
		for(int i=2; i<=n; i++){
			if(arr[i] == 0){
				for(int j=1; i*j <= n; j++){
					if(arr[i*j] == 0){
						arr[i*j] = 1;
						removed_cnt++;
						if(removed_cnt == k){
							bw.write(i*j + "");
							break;
						}
					}
				}
			}
		}
		bw.flush();  
	}

	
	public static void main(String[] args) throws IOException{  
	   Main ans = new Main();
	   ans.solution();
	}  
}