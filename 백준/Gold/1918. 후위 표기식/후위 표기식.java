import java.util.*;
import java.io.*;


class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	int T,n,m;

	public void solution() throws IOException{
		String input = br.readLine();

 		// 처음에 괄호작업 해서 연산 순서 확정
		// 뒤부터 탐색
		// ')' 괄호가 나오면 '(' 나올때 까지, 연산자 나오면 이전에 나온 문자들 뒤로
		// 후위로 변환한 덩어리를 하나의 operand로

		// 입력받은 string에 우선순위에 따른 괄호 추가
		input = stringWithPriority(input);

		Deque<String> s1 = new ArrayDeque<>();

		// 순서가 추가된 중위표기식을 후위로 변환
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<input.length(); i++){
			String s = input.charAt(i) + "";
			if(getType(s) == 3){
				// 문자 -> 비로 추가
				sb.append(s);
			}else if(getType(s) == 0){
				// "("
				s1.push(s);
			}else if(getType(s) == 1){
				// ")"  -> 여는 괄호 나올때까지 pop
				while(!s1.isEmpty() && getType(s1.peek()) != 0){
					sb.append(s1.pop());
				}
				s1.pop();
			}else {
				// 연산자의 현재 우선순위 더 높거나 같으면 추가
				while(!s1.isEmpty() && getType(s1.peek()) != 0 && (getPriority(s) >= getPriority(s1.peek()))){
					sb.append(s1.pop());
				}
				s1.push(s);
			}
		}

		while(!s1.isEmpty()){
			sb.append(s1.pop());
		}
		bw.write(sb.toString());
		bw.flush();
	}

	public String stringWithPriority(String input){
		Deque<String> operands = new ArrayDeque<>();
		Deque<String> operators = new ArrayDeque<>();

		for(int i=0; i<input.length(); i++){
			String s = input.charAt(i)+"";
			if(getType(s) == 3){
				operands.push(s);
			}else if(getType(s) == 0){
				// "("
				operators.push(s);
			}else if(getType(s) == 1){
				// ")" -> "(" 만날때까지 process
				while(!operators.isEmpty() && getType(operators.peek()) != 0){
					getProcess(operands, operators);
				}
				// "(" 제거
				operators.pop();
			}else{
				// 연산자의 경우 -> "(" 아니고, 우선순위 낮은 operator 나올때까지
				while(!operators.isEmpty() && getType(operators.peek()) != 0  &&(getPriority(s) <= getPriority(operators.peek())) ){
					getProcess(operands, operators);
				}
				operators.push(s);
			}
		}

		// 남은 연산자 추가
		while(!operators.isEmpty()){
			getProcess(operands, operators);
		}
		return operands.peek(); // string 1개
	}

	// 중위표기식들의 우선순위
	public int getPriority(String x){
		if(x.equals("*") || x.equals("/")){
			return 2;
		}
		if(x.equals("+") || x.equals("-")){
			return 1;
		}
		return -1; // '('
	}

	public void getProcess(Deque<String> operands, Deque<String> operators){
		String b = operands.pop();
		String a = operands.pop();
		String reg = operators.pop();
		operands.push("(" + a + reg + b + ")");
	}

	public int getType(String x){
		if(x.equals("(")){
			return 0;
		}else if(x.equals(")")){
			return 1;
		}else if(x.equals("+") || x.equals("-") || x.equals("/")|| x.equals("*")){
			return 2;
		}
		return 3; // 문자
	}

	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.solution();
	}
}
