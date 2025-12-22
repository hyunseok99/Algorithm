import java.util.*;
import java.io.*;

class Main{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	int T, n;
	int[][] node; // node[x][0,1] left, right
	int[] pre;
	int[] in;
	int[] post; //
	int root;
	int start_idx = 0;

	public void solution() throws IOException{
		// br.readLine(); bw.write();
		String[] pre_order = br.readLine().split(" ");
		String[] in_order = br.readLine().split(" ");
		node = new int[n+1][2];
		for(int i=0; i<node.length; i++){
			node[i][0] = -1;
			node[i][1] = -1;
		}
		pre = new int[n];
		in = new int[n];
		post = new int[n];
		start_idx = 0;
		for(int i=0; i<n; i++){
			pre[i] = Integer.parseInt(pre_order[i]);
			in[i] = Integer.parseInt(in_order[i]);
		}
		root = pre[0];

        // root기준으로 left, right -> 새로운 root 기준 left, right
		ArrayList<Integer> left_list = new ArrayList<>();
		ArrayList<Integer> right_list = new ArrayList<>();

		// 자식들 정보 갱신
		getInfoFromIn(pre[0], in);

		// 후위 순위 출력
		printPost(root);
        bw.write("\n");
		bw.flush();
	}
	public void printPost(int idx) throws IOException{
		if(node[idx][0] != 0){
			printPost(node[idx][0]);
		}
		if(node[idx][1] != 0){
			printPost(node[idx][1]);
		}
		bw.write(idx + " ");
	}

	// 특정 root 노드를 기준으로 left children, right children 설정
	// left children, right children 존재하면 -> 그 children들로 구성된 트리의 root는 전위 순회의 node
	// nodes: 시작 = pre_order
	public void getInfoFromIn(int root_node, int[] nodes){
		int root_idx= -1;
		for(int i=0; i<nodes.length; i++){
			if(nodes[i] == root_node){
				root_idx = i;
			}
		}

		// nodes에 root_node 포함 되어 있지 않으면 탐색 종료
		if(root_idx == -1) return;

		// 그렇지 안핟면 기존의 nodes를 다시 분할
		ArrayList<Integer> left_list = new ArrayList<>();
		ArrayList<Integer> right_list = new ArrayList<>();
		for(int i=0; i<nodes.length; i++){
			if(i < root_idx){
				left_list.add(nodes[i]);
			}
			if(i > root_idx){
				right_list.add(nodes[i]);
			}
		}
		// children이 존재한다면 -> 다은 pre_idx 를 기준으로 root
		if(!left_list.isEmpty()){
			int next_idx = ++start_idx;
			if(next_idx < n){
							int left_child = pre[next_idx];
				node[root_node][0] = left_child;
				getInfoFromIn(left_child, left_list.stream().mapToInt(i -> i).toArray());
			}
		}else{
			node[root_node][0] = 0;
		}
		if(!right_list.isEmpty()){
			int next_idx = ++start_idx;
			if(next_idx < n){
				int right_child = pre[next_idx];
				node[root_node][1] = right_child;
				getInfoFromIn(right_child, right_list.stream().mapToInt(i -> i).toArray());
			}
		}else{
			node[root_node][1] = 0;
		}

	}
	public static void main(String[] args) throws IOException{
	   Main ans = new Main();
	   ans.T = Integer.parseInt(ans.br.readLine());
	   while(ans.T > 0){
		   ans.n = Integer.parseInt(ans.br.readLine());
		   ans.solution();
		   ans.T--;
	   }
	}
}


