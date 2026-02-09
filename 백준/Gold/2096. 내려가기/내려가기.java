import java.util.*;
import java.io.*;
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n;
	int[] dp_max;
	int[] dp_min;
    int[] prev_max;
	int[] prev_min;
	int max_val = 1000000;
	int min_val = -1;
	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		dp_max = new int[3];
		dp_min = new int[3];
		prev_max = new int[3];
		prev_min = new int[3];


        Arrays.fill(dp_max, min_val);
        Arrays.fill(dp_min, max_val);

		// 메모리 제한 256mb -> 2차원 배열 x
		for(int i=0; i<n; i++){
			// init 하면서 최대값이랑 최소값 갱신
			input = br.readLine().split(" ");
			// 처음 init
			if(i == 0){
				for(int j=0; j<3; j++){
					dp_max[j] = Integer.parseInt(input[j]);
					dp_min[j] = Integer.parseInt(input[j]);
				}
				continue;
			}

			// dp max, min 갱신
			for(int j=0; j<3; j++){
				prev_max[j] = dp_max[j];
				prev_min[j] = dp_min[j];
			}

			// 0번칸: 위, 오른쪽 위
			int[] val = new int[3];
			for(int j=0; j<3; j++){
				val[j] = Integer.parseInt(input[j]);
			}

			dp_max[0] = Math.max(prev_max[0], prev_max[1]) + val[0];
			dp_max[1] = Math.max(Math.max(prev_max[0], prev_max[1]), prev_max[2]) + val[1];
			dp_max[2] = Math.max(prev_max[1], prev_max[2]) + val[2];
			dp_min[0] = Math.min(prev_min[0],prev_min[1]) + val[0];
			dp_min[1] = Math.min(Math.min(prev_min[0], prev_min[1]), prev_min[2]) + val[1];
			dp_min[2] = Math.min(prev_min[1],prev_min[2]) + val[2];
		}

		// 최대 최소
		int min_ans = max_val;
		int max_ans = min_val;
		for(int j=0; j<3; j++){
			min_ans = Math.min(min_ans, dp_min[j]);
			max_ans = Math.max(max_ans, dp_max[j]);
		}

		bw.write(max_ans + " " + min_ans);
		bw.flush();
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}
