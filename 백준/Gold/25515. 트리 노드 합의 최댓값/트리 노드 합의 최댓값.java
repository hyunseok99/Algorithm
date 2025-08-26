import java.io.*;
import java.util.ArrayList;


class Main {
    // 문자열 입력
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n;
    static int NOT_SELECTED = 0;
    static int SELECTED = 1;
    public static void main(String args[]) throws IOException {
        n = Integer.parseInt(br.readLine());
        int[] weight = new int[n];
        long[] dp = new long[n];
        // 인접 리스트 0~n-1 노드
        ArrayList<Integer>[] adj = new ArrayList[n];

        // 인접리스트 초기화
        for(int i=0; i<n; i++){
            adj[i] = new ArrayList<>();
        }

        // edge
        for(int i=1; i<n; i++){
            String[] edges = br.readLine().split(" ");
            int a,b;
            a = Integer.parseInt(edges[0]);
            b = Integer.parseInt(edges[1]);
            adj[a].add(b);
            adj[b].add(a);
        }

        String[] weights = br.readLine().split(" ");
        // weight
        for(int i=0; i<n; i++){
            weight[i] = Integer.parseInt(weights[i]);
        }
        // dfs를 통해서 dp 초기화 , 루트노드 0번은 반드시 지나야 함
        // 루트노드를 지나며 최대 => 루트의 자식들을 루트로 하는 노드의 합들의 최대가 최대
        dfs(0,-1, dp, weight, adj);

        long res = dp[0];
        bw.write(res + "");
        // 최종 출력
        bw.flush();
        bw.close();
    }


    // 인접 노드 방문
    static void dfs(int cur, int par, long[] dp, int[] weight, ArrayList<Integer>[] adj){
        // dp 초기화
        dp[cur] = weight[cur];

        // 하향식
        for(int neighbor: adj[cur]){
            if(neighbor != par){
                // dfs 호출
                dfs(neighbor, cur, dp, weight, adj);
                // ex) 2
                //   3   4     -> 모두 양수라면 3 -> 2 -> 4 -> 2 즉 모두 이동한 경우가 최대
                // 만약 4가 음수라면 -> 3->2 가 최대 따라서 자식들에 따라 최대값을 기록해서 그걸 누적해서 0번노드까지 더해야 함
                // 하향식으로 dp 돌면서 최대를 유지하면 끝
                dp[cur] = Math.max(dp[cur], dp[cur] + dp[neighbor]);
            }
        }
    }
}
