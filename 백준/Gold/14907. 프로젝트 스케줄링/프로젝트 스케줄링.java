import java.util.*;
import java.io.*;

class Main{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	// { job , pre_jobs}: map[job] = {job1, job2}
	static Map<Integer, String> my_map = new HashMap<>();
	// 작업에 걸리는 시간
	static int[] work_time = new int[26];

	// 특정 작업에 걸린 시간 memoization
	static int[] mem = new int[26];
	public static void main(String[] args) throws IOException{
		String input;
		Arrays.fill(mem, -1);
		while((input = br.readLine()) != null && !input.isEmpty()){
			StringTokenizer st = new StringTokenizer(input);
			if(st.countTokens() == 2){
				int idx = st.nextToken().charAt(0) - 'A';
				work_time[idx] = Integer.parseInt(st.nextToken());
				mem[idx] = work_time[idx];
			}else{
				int idx = st.nextToken().charAt(0) - 'A';
				work_time[idx] = Integer.parseInt(st.nextToken());
				String pre = st.nextToken();
				// 사전 필요 작업
				my_map.put(idx, pre);
			}
		}

		// 모든 memoization 완료하고 -> 걸리는 시간 최대 = 모든 작업 완료 시간
		// A~Z 까지 memoization 체크
		int ans = -1;
		for(int i=0; i<26; i++){
			if(work_time[i] == 0) continue; // 없는 작업은 스킵
			ans = Math.max(ans, getMem(i));
		}
		bw.write(ans + "");
		bw.flush();

		return;
	}

	public static int getMem(int cur){
		// 걸리는 시간 계산 완료시 return;
		// 처음에 선행작업 없는 경우 추가했으니 따로 체크 필요 x
		if(mem[cur] != -1){
			return mem[cur];
		}

		// 선행 작업이 필요한 경우
		String pre = my_map.get(cur);
		int max_time = -1;
		for(int i=0; i<pre.length(); i++){
			int idx = pre.charAt(i) - 'A';
			int sum_t = work_time[cur] + getMem(idx);
			max_time = Math.max(max_time, sum_t);
		}
		mem[cur] = max_time;
		return mem[cur];
	}
}
