import java.util.*;
import java.io.*;

class Main{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	static int N,M;

	static class Pair{
		String first, second;
		public Pair(String a, String b){
			this.first = a;
			this.second = b;
		}
	}


	// {name, parent}: map[x] = {parent pair}

	static String owner;
	static Map<String, Pair> my_map = new HashMap<>();

	// owner부터 순회해서 -> owner로부터 떨어진 정도 저장 -> 반환
	// O(n * M*2)
	static Map<String, Double> depth_map = new HashMap<>();

	public static void main(String[] args) throws IOException{
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		owner = st.nextToken();

		for(int i=0; i<N; i++){
			st = new StringTokenizer(br.readLine());
			String name = st.nextToken();
			Pair parents = new Pair(st.nextToken(), st.nextToken());
			my_map.put(name, parents);
		}
		// 왕 추가
		depth_map.put(owner, 1.0);


		// memoization 하면서 -> 정답 연산
		double ans = -1;
		String ans_name = "";

		for(int i=0; i<M; i++){
			st = new StringTokenizer(br.readLine());
			String cur_name = st.nextToken();
			double depth_val = setDepth(cur_name);
			if(ans < depth_val){
				ans = depth_val;
				ans_name = cur_name;
			}
		}

		bw.write(ans_name);
		bw.flush();
		return;
	}

	// depth를 저장하고 저장되어 있으면 반환
	// parent가 없으면 0
	// owner 본인이면 1,
	public static double setDepth(String cur){
		// depth맵에 존재하면 return
		if(depth_map.containsKey(cur)){
			return depth_map.get(cur);
		}
		// 부모의 depth
		if(!my_map.containsKey(cur)){
			// 부모 없으면 -> 왕족 x
			depth_map.put(cur, 0D);
			return 0D;
		}

		// 부모들의 혈통을 통해 값 저장

		Pair parents = my_map.get(cur);

		String father = parents.first;
		String mother = parents.second;
		double f_depth;
		double m_depth;

		if(!depth_map.containsKey(father)){
			f_depth = setDepth(father);
		}else{
			f_depth = depth_map.get(father);
		}

		if(!depth_map.containsKey(mother)){
			m_depth = setDepth(mother);
		}else{
			m_depth = depth_map.get(mother);
		}
		double c_depth = ((f_depth + m_depth) / 2);
		depth_map.put(cur, c_depth);
		return c_depth;
	}
}