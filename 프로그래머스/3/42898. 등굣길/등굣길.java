import java.util.*;

// java modular 연산 음수 가능한거 인지 
// (1,1) -> (n,m)
class Solution {
    int divisor = 1000000007;
    int[][] memo;
    int max_y, max_x;
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        memo = new int[n+1][m+1];
        max_y = n;
        max_x = m;
        // init -1, puddles 0, 
        for(int[] x: memo){
            for(int i=0; i<x.length; i++){
                x[i] = -1;
            }
        }
        memo[1][1] = 1; // 출발지점 1가지 
        for(int[] puddle: puddles){
            memo[puddle[1]][puddle[0]] = 0; // puddle 0가지 
        }
        answer = getMem(n, m);
        return answer;
    }
    
    // y,x 좌표 , memo[y][x] = memo[y-1][x] + memo[y][x-1] 
    // x좌표 증가 or y좌표 증가로만 이동함 
    public int getMem(int y, int x){
        if(y <= 0 || y > max_y || x <= 0 || x > max_x){
            return 0;
        }
        if(memo[y][x] != -1){
            return memo[y][x];
        }
        
        int tot = (getMem(y-1, x) % divisor) + (getMem(y,x-1) % divisor);
        tot %= divisor;
        memo[y][x] = tot;
        return memo[y][x];
    }
}