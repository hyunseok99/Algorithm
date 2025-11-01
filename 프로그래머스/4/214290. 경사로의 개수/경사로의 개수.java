import java.util.*;

// 8*8 
// d를 만족하는 시작 : 끝 동일한데 경로가 다른 경우가 존재? => 가능 
// 시작 -> 끝  = 시작 -> 끝 : a * b = total 가짓수 
// 시작과 끝지점으로 d를 만족하는 경로의 갯수들을 저장 
// ex)  y,x -> ny,nx
// 이걸 k번 반복이니 -> dp[idx] 이용해 최적화
// 특정 지점에서 이동가능한 경우의 경사들 
class Solution {
    // 상 하 좌 우
    int[] dy = {-1, 1, 0, 0};
    int[] dx = {0, 0, -1, 1};
    int d_size = 0;
    int max_y = 0;
    int max_x = 0;
    int start_y = 0;
    int start_x = 0;
    
    public int solution(int[][] grid, int[] d, int k) {
        int divisor = 1000000007;
        max_y = grid.length;
        max_x = grid[0].length;
        d_size = d.length;
        long answer = 0;
        // cnt[start][end] = 시작-> 끝지점 가능 가짓수  ->  d를 1번 반복했을 때의 cnt 
        // k번 반복하는 행렬곱 
        long[][] cnt = getCnt(grid, d);
    
        // 모든 시작 지점으로 부터 d를 만족하는 경우를 k번 반복하는 경우들의 합
        // 전부 순회는 무리 k ~= 10^9 -> log k 
        // k번 반복한 cnt 배열을 새로 만들고 -> 모든 배열의 합 =  answer 
        
        long[][] cnt_k = getAns(cnt, k);
        for(int i=0; i<max_x*max_y; i++){
            for(int j=0; j<max_x*max_y; j++){
                answer = (answer + cnt_k[i][j]) % divisor;
            }
        }        

        return (int)answer;
    }
    
    // d를 1번 만족하는 경우의 시작지점, 끝지점에 따른 가능 경로 가짓수 배열 리턴 
    public long[][] getCnt(int[][] grid, int[] d){
        long[][] cnt = new long[max_y * max_x][max_y * max_x];
        int divisor = 1000000007;
        
        // 시작 지점 
        for(int start_y=0; start_y< max_y; start_y++){
            for(int start_x=0; start_x<max_x; start_x++){
                int start = start_y*max_x + start_x;
                // 시작지점에 따른 d를 만족해서 -> (y,x)에 도달 가능한 경우의 수를 dp[lev][y][x] 
                // dp[cur_lev][ny][nx] -> dp[cur_lev][ny][nx] + dp[cur_lev-1][y][x]
                long[][][] dp =  new long[d_size+1][max_y][max_x];
                // init
                dp[0][start_y][start_x] = 1;
                for(int cur_lev = 0; cur_lev < d_size; cur_lev++){
                    for(int y=0; y<max_y; y++ ){
                        for(int x = 0; x<max_x; x++){
                            if(dp[cur_lev][y][x] == 0) continue;
                            for(int dir = 0; dir<4; dir++){
                                int ny = y + dy[dir];
                                int nx = x + dx[dir];
                                if(ny >= 0 && ny < max_y && nx >= 0 && nx < max_x){
                                    if(grid[ny][nx] - grid[y][x] == d[cur_lev]){
                                        dp[cur_lev+1][ny][nx] = (dp[cur_lev+1][ny][nx] + dp[cur_lev][y][x]) % divisor;
                                    }
                                }
                            }
                        }
                    }
                }
                // k=1 결과 저장 
                for(int y = 0; y<max_y; y++){
                    for(int x=0; x<max_x; x++){
                        // 시작지점에서 -> (y,x) 까지 가능한 경우의 수 저장
                        int end = y*max_x + x;
                        cnt[start][end] = dp[d_size][y][x];
                    }
                }
            }
        }
        return cnt;        
    }
    
    public long[][] getAns(long[][] cnt, int k){
        // cnt 배열을 k번 곱해야 함 
        // O(n^3 * k)는 무리 -> O(n^3 * log k) 이용해야 함 -> 곱해진 결과를 이용 
        // ex) k = 8 - > k*k ->  (k*k) * (k*k) -> (k^4) * (k^4) : 3번의 연산으로 끝 
        // ex) k = 7 -> 1 + 2 +3 + 1
        int n = max_y * max_x;
        long[][] res = new long[n][n];
        long[][] tmp = cnt;
        
        for(int i=0; i<n; i++){
            res[i][i] = 1;
        }
        
        while(k > 0){
            if(k % 2 != 0){
                // k가 홀수면 -> res * tmp = res
                res = getMulti(res, tmp);
            }
            // tmp 갱신 1 -> 2 -> 4
            tmp = getMulti(tmp, tmp);
            k /= 2;
        }
        return res;
    }
    
    // O(n^3)
    public long[][] getMulti(long[][] a, long[][] b){
        int n = max_x * max_y;
        int divisor = 1000000007;
        
        long[][] tmp = new long[n][n];
        
        // a, b 행렬 곱
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int l=0; l<n; l++){
                    tmp[i][j] = (tmp[i][j] + (a[i][l] * b[l][j])) % divisor;
                }
            }
        }
        return tmp;
    }
}