import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	int n,k;
	int answer;
	int[] mem;
	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");  
		n = Integer.parseInt(input[0]);  
		k = Integer.parseInt(input[1]);  
		
		// 동생이 수빈보다 뒤면 무조건 -1 밖에 없음 
		mem = new int[100001]; // 동생의 위치에 따른 시간  
		for(int i=0; i<=100000; i++){
			mem[i] = -1;
		}
		answer = getMem(k); // O(log k)
		bw.write(answer + "");  
		bw.flush();
	}
	// top-down 
	public int getMem(int pos){
		if(n >= pos){
			return n-pos;
		}
		if(mem[pos] != -1){
			return mem[pos];
		}
		if(pos == 1){
			mem[pos] = 1 + getMem(0);
		}else if((pos%2) == 0){
			// even   
			mem[pos] = Math.min(pos-n, getMem(pos/2));
		}else{
			// odd
			int min_val = Integer.MAX_VALUE;
			if(pos+1 <= 1000000){
				min_val = Math.min(min_val, getMem(pos+1));
			}
			if(pos-1 >= 0){
				min_val = Math.min(min_val, getMem(pos-1));
			}
			mem[pos] = min_val + 1;
		}
		return mem[pos];
	}
	public static void main(String[] args) throws IOException{  
	   Main ans = new Main();
	   ans.solution();
	}  
}