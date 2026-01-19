import java.util.*;
import java.io.*;


class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int T,n,m;
	String answer;
	boolean isHappy;
	Pos target; // 목적지
	public class State{
		int y, x; // 현재 위치
		int beer; // 남은 맥주
		int move; // 가능한 걸음 수
		public State(){}
		public State(int y, int x, int n){
			this.y = y;
			this.x = x;
			this.beer = 20;
			this.move = 0;
		}
	}

	public class Pos{
		int y,x;
		public Pos(int y, int x){
			this.y = y;
			this.x = x;
		}
	}

	public void solution() throws IOException{
		n = Integer.parseInt(br.readLine());
		isHappy = false;
		answer = "sad"; //init
		// 결국 선택해야 하는 행동: 편의점 가기 or 페타포트 가기
		Queue<State> q = new LinkedList<>();
		ArrayList<Pos> list = new ArrayList<>();
		boolean[] flag = new boolean[n+1];
		// -32768~32768
		for(int i=1; i<=n+2; i++){
			String[] input = br.readLine().split(" ");
			int y = Integer.parseInt(input[0]);
			int x = Integer.parseInt(input[1]);
			if(i == 1){
				// 시작 위치
				q.add(new State(y,x,n));
			}else if(i == n+2){
				// 도착 위치
                target = new Pos(y,x);
			}else{
				// 편의점
				list.add(new Pos(y,x));
			}
		}

		while(!q.isEmpty()){
			if(isHappy) break;
			State cur = q.poll();
			Queue<State> next_q = getBfs(cur, list, flag);
			while(!next_q.isEmpty()){
				State next = next_q.poll();
				q.add(next);
			}
		}

		if(isHappy){
			answer = "happy";
		}
		bw.write(answer+"\n");
		bw.flush();
	}

	// 방문 가능 bfs 탐색
	public Queue<State> getBfs(State cur, ArrayList<Pos> list, boolean[] flag){
		Queue<State> next_q = new LinkedList<>();
		// 편의점 혹은 도착지 도착 가능 여부 판단
		int max_move = cur.beer * 50 + cur.move;

		// 목적지 도달 가능 판단
		if(max_move >= (Math.abs(target.y-cur.y) + Math.abs(target.x-cur.x))){
			isHappy = true;
			return next_q;
		}
		for(int i=0; i<n; i++){
			if(flag[i]) continue;
			// 편의점 도달 가능 여부 판단
			Pos conv = list.get(i);
			State next_state = new State();
			int move_to = (Math.abs(cur.y-conv.y) + Math.abs(cur.x - conv.x));
			if(max_move >= move_to){
				// 가능한 맥주 모두 마시고 next_q에 추가
				next_state.y = conv.y;
				next_state.x = conv.x;
				int quotient = (move_to) / 50;
				int remain = move_to % 50;
				if(remain != 0){
					quotient++;
				}
				next_state.beer = 20;
//				next_state.move = (50-remain);
				next_state.move = 0; // 문제가 무조건 편의점 나설때 move 0으로 초기화해야하네요;;
				flag[i] = true;
				next_q.add(next_state);
			}
		}

		return next_q;
	}


	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.T = Integer.parseInt(ans.br.readLine());
	   while(ans.T-- > 0){
		   ans.solution();
	   }
	}
}
