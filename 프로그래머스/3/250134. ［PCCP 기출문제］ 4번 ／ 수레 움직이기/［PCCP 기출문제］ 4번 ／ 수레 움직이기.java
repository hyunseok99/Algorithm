import java.util.*;

// maze : y,x,val

// 최대 가능 턴: m*n ~= 16 
// 특정 턴 x에 가능한 위치들을 이용해서 판독 
// 특정 턴 x에 가능 -> x~max , 불가능 -> 0 ~ x 
// 만약 같은 위치로 이동하는 경우를 제외하고 연산 
// 모든 경우 고려는 에바 -> 4^16 ~= 2^32

// 조건: 1. 동시에 완료, 2. 다른 타이밍에 완료: 먼저 완료된 시점 이후에 해당 도착 위치를 이용 불가능 
// 동시에 이동하면서 모두 도착 최소 동선이 답 -> 바로 종료 
class Pos{
    public int y,x;
    public Pos(int y, int x){
        this.y = y;
        this.x = x;
    }
    
    public boolean compPos(Pos a){
        if(this.y == a.y && this.x == a.x){
            return true;
        }
        return false;
    }
}

class Solution {
    public int max_y;
    public int max_x;
    public int[] dy = {-1, 1, 0, 0}; // 상 하 좌 우
    public int[] dx = {0, 0, -1, 1};
    public int start_r_y, start_r_x,start_b_y,start_b_x,dest_r_y,dest_r_x,dest_b_y,dest_b_x;
    public boolean[][] flag_r;
    public boolean[][] flag_b; 
    public int answer;
    // red: 1,3  blue: 2,4  wall: 5
    public int solution(int[][] maze) {
        
        max_y = maze.length;
        max_x = maze[0].length;
        answer = max_y * max_x;
            
        flag_r = new boolean[max_y][max_x];
        flag_b = new boolean[max_y][max_x];

        
        for(int y = 0; y<max_y; y++){
            for(int x=0; x<max_x; x++){
                if(maze[y][x] == 1){
                    start_r_y = y;
                    start_r_x = x;
                }
                if(maze[y][x] == 2){
                    start_b_y = y;
                    start_b_x = x;
                }
                if(maze[y][x] == 3){
                    dest_r_y = y;
                    dest_r_x = x;
                }
                if(maze[y][x] == 4){
                    dest_b_y = y;
                    dest_b_x = x;
                }
            }
        }
        
        // 출발 위치 flag 체크 
        flag_r[start_r_y][start_r_x] = true;
        flag_b[start_b_y][start_b_x] = true;
        
        // dfs 수행 
        dfs(0, maze, new Pos(start_r_y, start_r_x), new Pos(start_b_y, start_b_x));
        
        if(answer == max_y * max_x){
            answer = 0;
        }
        return answer;
    }
    
    // 목적지까지 도달하는 경우의 경로들 저장, 길이가 턴 -> dfs 
    public void dfs(int lev, int[][] maze, Pos cur_r, Pos cur_b){
        // 1.이미 최소 정답보다 더 이동시 종료
        if(lev >= answer){
            return;
        }
        
        // 2. 도착 여부 체크 후 둘다 도착하면 종료
        boolean is_r_arrived = flag_r[dest_r_y][dest_r_x];
        boolean is_b_arrived = flag_b[dest_b_y][dest_b_x];
        
        if(is_r_arrived && is_b_arrived){
            answer = Math.min(answer, lev);
            return;
        }
        
        ArrayList<Pos> rNexts = getNextPos(cur_r, maze, flag_r, is_r_arrived);
        ArrayList<Pos> bNexts = getNextPos(cur_b, maze, flag_b, is_b_arrived);
        
        for(Pos rNext: rNexts){
            for(Pos bNext: bNexts){
                // 둘이 같은 칸 이동하는 경우
                if(rNext.compPos(bNext)){
                    continue;
                }
                // 서로의 위치가 바뀌는 경우
                // 예외 케이스 -> 같이 이동한 경우 a,b,c위치에서 a,b -> b,c 이동하는 경우는 가능 
                if( rNext.compPos(cur_b) && bNext.compPos(cur_r)){
                    continue;
                }
                
                // 만약 도착한 경우가 아니라면 flag 갱신
                if(!is_r_arrived){
                    flag_r[rNext.y][rNext.x] = true;
                }
                
                if(!is_b_arrived){
                    flag_b[bNext.y][bNext.x] = true;
                }
                // depth + 1 
                dfs(lev+1, maze, rNext, bNext);
                
                if(!is_r_arrived){
                    flag_r[rNext.y][rNext.x] = false;
                }
                
                if(!is_b_arrived){
                    flag_b[bNext.y][bNext.x] = false;
                }
                
            }
        }
        
    }
    // 경로의 최대 = m*n-1
    // 다음 이동 경로 리스트 return 
    // 만약 도착 상태면 마지막 위치만 
    public ArrayList<Pos> getNextPos(Pos cur, int[][] maze, boolean[][] flag, boolean isArrived){
        ArrayList<Pos> arr = new ArrayList<>();
        
        if(isArrived){
            arr.add(cur);
            return arr;
        }
        
        for(int dir=0; dir<4; dir++){
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            if(ny < 0 || nx < 0 || ny >= max_y || nx >= max_x || maze[ny][nx] == 5 || flag[ny][nx]){
                continue;
            }
            Pos next = new Pos(ny,nx);
            arr.add(next);
        }
        
        return arr;
    }
}