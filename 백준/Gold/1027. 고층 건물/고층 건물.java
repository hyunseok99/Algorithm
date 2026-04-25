import java.util.*;
import java.io.*;
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n;
	int[] arr;
	int[] arr_see;
	int ans = 0;

	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		arr = new int[n+1];
		arr_see = new int[n+1];

		input = br.readLine().split(" ");
		for(int i=1; i<=n; i++){
			arr[i] = Integer.parseInt(input[i-1]);
		}
		// 왼쪽으로 보이는 것 -> 높이 차이가 이전보다 작아야 함
		// 오른쪽으로 보이는 것 -> 높이 차이가 이전보다 커야 함
		// O(n * 2n) -> O(n^2)
		for(int i=1; i<=n; i++){
			// 왼쪽으로 보이는 갯수 = 높이 차이가 이전보다 작아야 함
			// ex) 2 5 3 7 -> 2개, 2 4 5 7 -> 2개
			int cnt = 0;
			// 왼쪽 탐색
			double min_ratio = Double.MAX_VALUE;
			for(int j=i-1; j >= 1; j--){
				double ratio = calc(i,j);
				if(min_ratio > ratio){
					min_ratio = ratio;
					cnt++;
				}
			}

			// 오른쪽 탐색 -> 높이 차이(기울기)가 이전보다 커저야 함
			double max_ratio = -Double.MAX_VALUE;
			for(int j=i+1; j<=n; j++){
				double ratio = calc(i,j);
				if(max_ratio < ratio){
					max_ratio = ratio;
					cnt++;
				}
			}

			// 볼 수 있는 숫자
			arr_see[i] = cnt;
			ans = Math.max(ans, cnt);
		}
		bw.write(ans + " ");
		bw.flush();
	}

	public double calc(int a, int b){
		return (double)(arr[b]-arr[a])/(b-a);
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}