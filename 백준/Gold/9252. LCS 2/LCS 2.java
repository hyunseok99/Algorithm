import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int[][] dp; // str1, str2 의 y,x idx까지 고려했을 때 최장 길이
	ArrayList<String> ans = new ArrayList<>();
	// 만약 더 긴 lcs 만들 수 있으면 추가 없으면 이동
	public void solution() throws IOException{
		// br.readLine(); bw.write();
		String str1 = br.readLine();
		String str2 = br.readLine();

		dp = new int[str1.length()+1][str2.length()+1];

		// lcs 길이에 따른 갱신
		// 문자가 같으면 추가 -> 다르면 기존의 수열 중 긴것으로 유지
		for(int i=1; i<=str1.length(); i++){
			for(int j=1; j<=str2.length(); j++){
				// 문자가 같으면 이전 최장 수열의 길이+1
				if(str1.charAt(i-1) == str2.charAt(j-1)){
					dp[i][j] = dp[i-1][j-1] + 1;
				}else{
					// 기존 수열중 긴 것
					dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		// 경로 저장
		backTracking(str1.length(), str2.length(), str1);
		// 최장 길이 = dp[str1][str2];
		bw.write(dp[str1.length()][str2.length()] + "\n");
		// 경로 역추적해서 출력
		if(ans.size() != 0){
			for(int i=ans.size()-1; i>=0; i--){
				bw.write(ans.get(i));
			}
		}
		bw.flush();
	}

	// 뒤부터 추적해서 lcs 정답 추가
	public void backTracking(int i, int j, String str1){
		while(i > 0 && j > 0){
			if(dp[i][j] == dp[i-1][j]){
				i--;
			}else if(dp[i][j] == dp[i][j-1]){
				j--;
			}else{
				ans.add(str1.charAt(i-1)+"");
				i--;
				j--;
			}
		}
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}