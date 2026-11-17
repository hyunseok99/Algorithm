import java.util.*;
import java.io.*;


public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
    // 투석전 -> 낙하: 던진 시점 + 날아갈 거리
    // 필요 정보: 던진 좌표, 던진 시점, 날아갈 거리, 무게

    public static class State implements Comparable<State> {
        int y, x, start, height, weight;
        public State(int y, int x, int start, int height, int weight){
            this.y = y;
            this.x = x;
            this.start = start;
            this.height = height;
            this.weight = weight;
        }
        @Override
        public int compareTo(State s){
            // min-heap: 던진 시점 
            return Integer.compare(this.start, s.start);
        }
    }

    static int[] dy = {-1,1,0,0}; // 상하좌우
    static int[] dx = {0,0,-1,1};

    public static void main(String[] args) throws Exception {
        int T = Integer.parseInt(br.readLine());
        for(int i=1; i<=T; i++){
            String[] str = br.readLine().split(" ");
            int n = Integer.parseInt(str[0]);
            int m = Integer.parseInt(str[1]);
            int k = Integer.parseInt(str[2]); // 투석기 수 
            ArrayList<int[]> info = new ArrayList<>(); // 투석기 info 
            for(int j=0; j<k; j++){
                str = br.readLine().split(" ");
                info.add(transStringToInt(str)); // c,s,d,a,h,p
            }
            bw.write("#" + i + " ");
            solution(n, m, info);
            bw.write("\n");
            bw.flush();
        } 
    }
    
    // String[] -> int[] 변환
    public static int[] transStringToInt(String[] str){
        int[] arr = new int[str.length];
        for(int i=0; i < str.length; i++){
            arr[i] = Integer.parseInt(str[i]);
        }
        return arr;
    }

    // 모든 돌을 다 넣어서 처리한다면 O(k * p) ~= 10*50
    // 투석 예정 돌을 담아 놓을 queue, 날아가는 중인 돌을 담아 놓을 queue 
    public static void solution(int n, int m, ArrayList<int[]> info) throws Exception{
        // 혼탁 matrix 
        int[][] matrix = new int[n][m];
        

        PriorityQueue<State> pq = new PriorityQueue<>();
        PriorityQueue<State> run_pq = new PriorityQueue<>(); // 던진 start = start + height;

        // info를 순회하며 state들 pq에 넣기 
        for(int[] i: info){
            addState(pq, n, i);
        }

        // t 관리하면서 투석 -> 날아가는 중인 투석 관리 
        // t > 50 이거나, 모든 작업 완료면 종료 
        int t = 1;
        while(t <= 50 && !(pq.isEmpty() && run_pq.isEmpty())){
            // 1.투석 및 이동
            while(!pq.isEmpty() && pq.peek().start <= t ){
                // 도착 좌표 작업 
                State cur = pq.poll();
                cur.y = cur.y - cur.height + 1;
                cur.start = cur.start + cur.height - 1; // dest 
                run_pq.add(cur);
            }
            // 2. 낙하
            int[][] pow_matrix = new int[n][m];  // 물결 세기 matrix
            while(!run_pq.isEmpty() && run_pq.peek().start <= t){
                // 맨하튼 연산 수행 
                State cur = run_pq.poll();
                
                // y, x, weight
                int init_weight = cur.weight * 3;

                for(int i=0; i<n; i++){
                    for(int j = 0; j < m; j++){
                        int dist = Math.abs(cur.y - i) + Math.abs(cur.x - j);
                        int power = init_weight - 5 * dist;
                        if(power > 0){
                            pow_matrix[i][j] += power; // 물결 세기 갱신 
                        }
                    }
                }
            }
            // 4단계: 점수 계산 및 answer 저장 
            int sum = 0;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    sum += Math.max(0, pow_matrix[i][j] - matrix[i][j]);
                }
            }
            bw.write(sum + " ");

            // 5,6단계: 흙탕물 가라앉기 작업 + 물살 
            int[][] after_matrix = new int[n][m];
            for(int i=0; i<n; i++){
                for(int j=1; j<m; j++){
                    if(matrix[i][j] != 0){
                        boolean isSurrounded = true; 
                        for(int dir=0; dir<4; dir++){
                            int ny = i + dy[dir];
                            int nx = j + dx[dir];
                            if(ny < 0 || nx < 0 || ny >= n || nx >= m || matrix[ny][nx] == 0){
                                isSurrounded = false;
                                break;
                            }
                        }
                        if(isSurrounded){
                            after_matrix[i][j-1] = Math.max(0, matrix[i][j] - 1);
                        }else{
                            after_matrix[i][j-1] = Math.max(0, matrix[i][j] - 2);
                        }
                    }
                }
                // 맨 오른쪽 열은 0
                after_matrix[i][m-1] = 0;
            }

            // 7단계: 흙탕물 일기 pow_matrix를 활용
            boolean[][] visited = new boolean[n][m];
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(pow_matrix[i][j] != 0 && !visited[i][j]){
                        int chaos_sum = pow_matrix[i][j];
                        ArrayList<int[]> pos_list = new ArrayList<>();
                        Queue<int[]> q = new ArrayDeque<>();
                        q.add(new int[]{i,j});
                        pos_list.add(new int[]{i,j});
                        visited[i][j] = true;
                        while(!q.isEmpty()){
                            int[] cur = q.poll();
                            for(int dir=0; dir<4; dir++){
                                int ny = cur[0] + dy[dir];
                                int nx = cur[1] + dx[dir];
                                if(ny < 0 || nx < 0 || ny >=n || nx >=m || visited[ny][nx] || (pow_matrix[ny][nx] == 0)) continue;
                                chaos_sum += pow_matrix[ny][nx];
                                q.add(new int[]{ny, nx});
                                pos_list.add(new int[]{ny, nx});
                                visited[ny][nx] = true;
                            }
                        }

                        for(int[] pos: pos_list){
                            after_matrix[pos[0]][pos[1]] += (chaos_sum / pos_list.size());
                        }
                    }
                }
            }
            matrix = after_matrix; // matrix 갱신 
            t++;
        }
    }

    // cur: 날릴 투석기
    public static void addState(PriorityQueue<State> pq, int n, int[] cur){
        // 투석기 y,x 좌표: n, cur[0];
        int y = n-1;
        int x = cur[0];
        int start = cur[1];
        int d = cur[2];
        int w = cur[3];
        int h = cur[4];
        for(int i=0; i<cur[5]; i++){
            pq.add(new State(y, x, start, h, w));
            start += d;
        }
    }

    // 
}