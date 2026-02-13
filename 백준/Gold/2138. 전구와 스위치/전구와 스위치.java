import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n;
	int ans = -1;
	int[] arr;
	int[] arr2;
	int[] target;
	public void solution() throws IOException{
		String input = br.readLine();
		n = Integer.parseInt(input);
		arr = new int[n]; // 0번을 누르지 않은 경우
		arr2 = new int[n]; // 0번을 누른경우
		target = new int[n];
		for(int i=0; i<2; i++){
			input = br.readLine();
			for(int j=0; j<n; j++){
				if(i == 0){
					arr[j] = input.charAt(j) - '0';
					arr2[j] = arr[j];
				}else{
					target[j] = input.charAt(j) - '0';
				}
			}

		}
		swap(arr2, 0);
		// i번 스위치를 누르거나 누르지 않거나 -> i-1에 영향
		// 0번을 누른경우, 누르지 않은 경우 -> 0번에 영향을 끼치는 스위치는 1번뿐
		// 즉 정해진다 -> 2번 하면 끝
		// ex) 0000 -> 0010 :  xxxo -> 0011 -> 불가
		// 0번을 누르지 않은 경우

		int cnt = 0;
		for(int i=1; i<n; i++){
			// 이전과 다르다면 무조건 눌러야 함
			if(arr[i-1] != target[i-1]){
				swap(arr, i);
				cnt++;
			}
			if(i == n-1){
				// 마지막 누르고 나서 마지막 부분이 target과 다르면 못만듬
				if(arr[i] != target[i]) continue;
				ans = cnt;
			}
		}

		// 0번을 누른경우
		cnt = 1;
		for(int i=1; i<n; i++){
			// 이전과 다르다면 무조건 눌러야 함
			if(arr2[i-1] != target[i-1]){
				swap(arr2, i);
				cnt++;
			}
			if(i == n-1){
				// 마지막 누르고 나서 마지막 부분이 target과 다르면 못만듬
				if(arr2[i] != target[i]) continue;
				ans = ans != -1 ? Math.min(ans, cnt) : cnt;
			}
		}

		bw.write(ans + "");
		bw.flush();

	}

	// x번 누른경우
	public void swap(int[] arr, int x){
		if(x-1 >= 0){
			arr[x-1] = 1 - arr[x-1];
		}
		arr[x] = 1 - arr[x];
		if(x+1 < n ){
			arr[x+1] = 1 -arr[x+1];
		}
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}
