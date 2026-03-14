import java.util.*;
import java.io.*;
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n, m;
	int[] arr; // arr[y] = -1 -> 안가도 되는 날
	int[][] mem; // 날짜, 쿠폰

	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		m = Integer.parseInt(input[1]);

		mem = new int[n+6][n+6];

		for(int i=0; i<=n; i++){
			Arrays.fill(mem[i], -1);
		}

		arr = new int[n+1];
		if(m > 0){
			input = br.readLine().split(" ");
		}

		for(int i=0; i<m; i++){
			// 해당 날짜 이용 x
			int day = Integer.parseInt(input[i]);
			arr[day] = -1;
		}

		// x일권 구매 -> 이전 구매가 z 구매일 경우 min
		int answer = getMem(1, 0);

		bw.write(answer + "");
		bw.flush();
		return;
	}

	// return min memoization
	public int getMem(int target, int coupons){
		if(target > n) return 0;

		if(mem[target][coupons] != -1){
			return mem[target][coupons];
		}

		int res = 10000000;

		// 만약 쿠폰이 2개 이상이면 1일권 대체 가능

		// 예약 필요 x면 안사고 다음날 가능
		if(arr[target] == -1){
			// 안사고 다음날
			res = Math.min(res, getMem(target+1, coupons));
		}
		if(coupons >= 3){
			res = Math.min(res, getMem(target+1, coupons-3));
		}

		// 1,3,5일권 구매의 경우
		res = Math.min(res, getMem(target+1, coupons) + 10000);
		res = Math.min(res, getMem(target+3, coupons+1) + 25000);
		res = Math.min(res, getMem(target+5, coupons+2) + 37000);


		mem[target][coupons] = res;
		return mem[target][coupons];
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}
