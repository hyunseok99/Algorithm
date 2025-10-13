import java.util.*;
import java.math.*;

class Pair {
    int y, x;
    public Pair(int y, int x){
        this.y = y;
        this.x = x;
    } 
}

class Solution {
    // 싱 하 좌 우
    int[] dy = {-1, 1, 0, 0};
    int[] dx = {0, 0, -1, 1};
    Pair goal = new Pair(0,0);
    
    public int solution(int[][] maps) {
        goal.y = maps.length;
        goal.x = maps[0].length;
        int[][] flag = new int[goal.y][goal.x];
        
        int answer = getAnswerWithBFS(maps, flag);

        return answer;
    }
    
    int getAnswerWithBFS(int [][] maps, int[][] flag) {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(0,0));
        flag[0][0] = 1;
        
        while(!q.isEmpty()){
            Pair cur = q.poll();    
            for(int dir=0; dir<4; dir++){
                int ny = cur.y + dy[dir];
                int nx = cur.x + dx[dir];
                if(nx >= 0 && ny >= 0 && nx < goal.x && ny < goal.y && maps[ny][nx] == 1 && flag[ny][nx] == 0){
                    q.add(new Pair(ny, nx));
                    flag[ny][nx] = flag[cur.y][cur.x] + 1;
                }
            }
        }
        
        return flag[goal.y-1][goal.x-1] != 0 ? flag[goal.y-1][goal.x-1] : -1;
       
    }
}