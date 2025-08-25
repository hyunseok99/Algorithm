import java.io.*;
import java.util.*;


class Main {
    // 문자열 입력
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static int n;
    public static int NOT_SELECTED = 0;
    public static int SELECTED = 1;
    public static void main(String args[]) throws IOException {
        n = Integer.parseInt(br.readLine());
        int[] people = new int [n+1];
        int[][] dp = new int[n+1][2];
        // 인접 리스트로 인접한 경우 체크
        ArrayList<Integer>[] adj = new ArrayList[n+1];

        String[] nums = br.readLine().split(" ");
        for(int i=1; i<=n; i++){
            people[i] = Integer.parseInt(nums[i-1]);
            adj[i] = new ArrayList<>();
        }

        for(int i=1; i<n; i++){
            int a,b;
            nums = br.readLine().split(" ");
            a = Integer.parseInt(nums[0]);
            b = Integer.parseInt(nums[1]);
            adj[a].add(b);
            adj[b].add(a);
        }
        // dfs를 통해서 dp 초기화
        dfs(1,-1, dp, people, adj);

        int res = Math.max(dp[1][SELECTED], dp[1][NOT_SELECTED]);
        bw.write(res + "");
        // 최종 출력
        bw.flush();
        bw.close();
    }
    /*
    '우수 마을'로 선정된 마을 주민 수의 총 합을 최대로 해야 한다.
    마을 사이의 충돌을 방지하기 위해서, 만일 두 마을이 인접해 있으면 두 마을을 모두 '우수 마을'로 선정할 수는 없다. 즉 '우수 마을'끼리는 서로 인접해 있을 수 없다.
    선정되지 못한 마을에 경각심을 불러일으키기 위해서, '우수 마을'로 선정되지 못한 마을은 적어도 하나의 '우수 마을'과는 인접해 있어야 한다.
    */

    // 인접 노드
    static void dfs(int cur, int par, int[][] dp, int[] people, ArrayList<Integer>[] adj){
        // dp 초기화, NOT_SELECTED = 0으로 초기화 되어 있음
        dp[cur][SELECTED] = people[cur];

        // 하향식
        for(int neighbor: adj[cur]){
            if(neighbor != par){
                // dfs 호출
                dfs(neighbor, cur, dp, people, adj);

                // 현재 마을을 선택한 경우 -> 인접한 자식을 선택 안한 경우들의 합
                dp[cur][SELECTED] += dp[neighbor][NOT_SELECTED];

                // 현재 마을을 선택하지 않은 경우 -> 자식 선택 or 선택 x 중 최대
                dp[cur][NOT_SELECTED]  += Math.max(dp[neighbor][NOT_SELECTED], dp[neighbor][SELECTED]);
            }
        }
    }
}
