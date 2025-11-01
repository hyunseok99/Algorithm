import java.util.*;

// 8*8 
// d를 만족하는 시작 : 끝 동일한데 경로가 다른 경우가 존재? => 가능 
// 시작 -> 끝  = 시작 -> 끝 : a * b = total 가짓수 
// 시작과 끝지점으로 d를 만족하는 경로의 갯수들을 저장 
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
    int answer = 0;
    
    public int solution(int[][] grid, int[] d, int k) {
        max_y = grid.length;
        max_x = grid[0].length;
        d_size = d.length;
        
        // cnt[start][end] = x 
        int[][] cnt = new int[max_y*max_x][max_y*max_x];
        // 시작지점에서 모든 가능한 경로며 d를 만족 할 때의 가짓수를 저장하자 -> dfs로 
        for(int i=0; i<max_y; i++){
            for(int j=0; j<max_x; j++){
                start_y = i;
                start_x = j;
                getDFS(0, i, j, grid, d, cnt);
            }
        }
        
        for(int i=0; i<max_y*max_x; i++){
            for(int j=0; j<max_y*max_x; j++){
                System.out.println("cnt[" + i + "]["+ j + "]: " + cnt[i][j]);
            }
        }
        
        // 모든 시작 지점으로 부터 d를 만족하는 경우를 k번 반복하는 경우들의 합 
        for(int i=0; i<max_y * max_x; i++){
            ArrayList<Integer> arr = new ArrayList<>();
            getAns(i, cnt, arr, k);
            
        }
        

        return answer;
    }
    
    public void getDFS(int lev, int y, int x, int[][] grid, int[] d, int[][] cnt){
        if(lev >= d_size){
            cnt[start_y*max_x + start_x][y*max_x + x] += 1;
            return;
        }
        // lev -> lev+1 
        for(int dir=0; dir<4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny >= 0 && ny < max_y && nx>=0 && nx < max_x){
                int degree = grid[ny][nx] - grid[y][x];
                if(degree == d[lev]){
                    getDFS(lev+1, ny, nx, grid, d, cnt);   
                }
            }
        }
    }
    
    public void getAns(int start, int[][] cnt, ArrayList<Integer> arr, int k){
        if(arr.size() >= k){
            int divisor = 1000000007;
            int tot = 1;
            for(int val: arr){
                // System.out.println("arr_val: "+ val);
                tot = (tot*val % divisor);
            }
            // arr 마지막 원소 제거 
            answer = (answer + tot) % divisor;
            // System.out.println("answer: "+ answer);
            
            return;
        }
        // 0 -> 0,1 ... y*x
        // 도착 지점 
        for(int end=0; end<max_y * max_x; end++){
            if(cnt[start][end] != 0){
                arr.add(cnt[start][end]);
                getAns(end, cnt, arr, k);
                arr.remove(arr.size()-1);
            }
        }
        // k번 반복 만족하는 가짓수 구하기
    }
    
}