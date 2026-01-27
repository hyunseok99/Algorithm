import java.util.*;
import java.io.*;

// ex) 7 3 3  : case1) a+b <= n
// 1 2 3 2 3 2 1
// 1 2 1 3 3 2 1  <- 사전적으로 이게 더 작음
// 1 1 2 2 3 2 1  <- 이건 더 작음, 즉 a+b <= n 이면 앞에서 최대한 n - (a+b) 채워야 함

// case2) a+b > n
// ex) 2 1 2
// 2 1

// ex) 3 3 2
// 1 2 3 // 불가
class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int n, a, b;
	// b는 최대한 빨리 처리하고 a는 최대한 늦게 처리 필요
	// O(a+b) ~= O(2n)
	public void solution() throws IOException{
		String[] input = br.readLine().split(" ");
		n = Integer.parseInt(input[0]);
		a = Integer.parseInt(input[1]);
		b = Integer.parseInt(input[2]);
		Deque<Integer> answer = getAnswer();
		if(answer.isEmpty()){
			bw.write(-1 + "");
		}else{
			while(!answer.isEmpty()){
				bw.write(answer.pop() + " ");
			}
		}
		bw.flush();
	}

	// case1) a + b = n
	// case2) a + b > n  -> a + b >= n+2면 불가능 죽, a+b=n+1인 경우만 존재재
	// case3) a + b < n
	// left의 마지막과 right의 시작을 동일하게 만들어주고
	// a+b > n 이라면 left 제거 : 차이가 2 이상이면 불가
	// a+b < n 이라면 동일하게 만들고 left 제거 후 1 앞에 추가
	// 결국 불가능한 경우는 a + b >= n+2 인 경우 뿐
	// 정답 stack 리턴 : 빈 스택 리턴이면 정답 -1 출력
	public Deque<Integer> getAnswer(){
		if(a+b-n >= 2){
			// 불가능한 경우
			return new ArrayDeque<>();
		}


		Deque<Integer> left = new ArrayDeque<>();
		Deque<Integer> right = new ArrayDeque<>();
		for(int i=1; i<=a; i++){
			left.push(i);
		}
		for(int j=1; j<=b; j++){
			right.push(j);
		}

		// n = a + b) 6, 4 + 2
		// : 1 2 3 4 + 2 1 -> 1 2 3 4 + 4 1 -> 1 1 2 3 + 4 1
		// : 1 2 3 + 4 1 -> 1 1 2 3 4 1
		// 7, 4 + 3
		// : 1 2 3 4 + 3 2 1 -> 1 2 3 + 4 2 1 -> 1 1 2 3 + 4 2 1
		// 7, 2 + 5
		// : 1 2 + 5 4 3 2 1 -> 1 + 5 4 3 2 1 -> 1 1 + 54321
		// n < a + b) 5, 5 + 1 : right 시작을 left 끝과 동일하게 만들고 제거
		// : 1 2 3 4 5 + 1 -> 1 2 3 4 5 + 5 -> 1 2 3 4 5
		// 5, 5 + 2
		// : 1 2 3 4 5 + 2 1 -> 1 2 3 4 5 1 ->
		// 5, 1 + 5
		// : 1 + 5 4 3 2 1 -> 5 + 5 4 3 2 1 -> 5 4 3 2 1
		// n > a + b) 4, 2 + 1
		// 1 2 + 1 -> 1 2 + 2 -> 1 1 + 2 -> 1 1 1 + 2
		// : 9, 4 + 3 -> 부족한 만큼  left에 1 추가
		// 1 2 3 4 + 3 2 1 -> 1 2 3 4 + 4 2 1 -> 1 1 1 1 2 3 + 4 2 1
		// : 9, 3 + 4 : left 끝, right 시작을 동일하게 만드는건 필수
		// 1 2 3 + 4 3 2 1 -> 1 2 4 + 4 3 2 1 -> 1 2 + 4 3 2 1 -> 1 1 1 1 2 + 4321
		// 7, 2 + 1
		// : 1 2 + 1 -> 1 2 + 2 -> 1 + 2 -> 111111 + 2

		// 일단 left top, right start중 큰값으로 변환
		if(!left.isEmpty() && !right.isEmpty()){
			int max_val = Math.max(left.pop(), right.pop());
			right.push(max_val);
		}
		// 만약 이 작업 후 left가 empty라면 right의 시작과 나머지 right 사이에 값을 추가 해야 함
		if(left.isEmpty()){
			// 바뀐 right의 시작이 left의 시작이 되어야 함
			int last_idx = right.size();
			int start_val = right.pop(); // 부족한 만큼 1 추가
			for(int i=0; i< n-last_idx; i++){
				right.push(1);
			}
			right.push(start_val); // 시작 값 추가
		}else{
			// left가 비어있지 않은 경우는 n이 될 때까지 앞에 1 추가
			while(!left.isEmpty()){
				right.push(left.pop());
			}
			int last_idx = right.size();
			for(int i=0; i<n-last_idx; i++){
				right.push(1);
			}
		}
		return right;
	}


	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}
