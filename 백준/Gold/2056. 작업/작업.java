import java.util.*;
import java.io.*;
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n;
	int[] arr;
	int[] mem; // 총 누적 걸리는 시간
	ArrayList<Integer>[] target; // target 수행에 선행되어야 하는 x번 작업

	public void solution() throws IOException{
		String input = br.readLine();
		n = Integer.parseInt(input);
		arr = new int[n+1];
		mem = new int[n+1];
		target = new ArrayList[n+1];
		for(int i=0; i<=n; i++){
			target[i] = new ArrayList<>();
		}

		for(int i=1; i<=n; i++){
			String[] str = br.readLine().split(" ");
			arr[i] = Integer.parseInt(str[0]);
			if(str.length <= 2){
				// basic work
				mem[i] = arr[i];
			}else{
				int need_cnt = Integer.parseInt(str[1]);
				for(int j=2; j<(2+need_cnt); j++){
					target[i].add(Integer.parseInt(str[j]));
				}
			}
		}
		// 모든 작업 top-down으로 완료시 최댓값이 답 O(n+m)
		int answer = 0;
		for(int i=1; i<=n; i++){
			answer = Math.max(answer, getTopDown(i));
		}
		bw.write(answer + "");
		bw.flush();
	}

	// 작업이 선행되어야 하는 경우 -> 병렬적으로 작업 x
	public int getTopDown(int t){
		// 이미 누적 시간이 계산된 경우 그대로 return
		if(mem[t] != 0){
			return mem[t];
		}

		// 선행되는 작업이 있는 경우 -> 누적 필요 시간 최대 + 본인 작업 시간
		int max_t = 0;
		for(int bef: target[t]){
			max_t = Math.max(max_t, getTopDown(bef));
		}
		max_t += arr[t];
		// mem 갱신하고 return
		mem[t] = max_t;
		return mem[t];
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}