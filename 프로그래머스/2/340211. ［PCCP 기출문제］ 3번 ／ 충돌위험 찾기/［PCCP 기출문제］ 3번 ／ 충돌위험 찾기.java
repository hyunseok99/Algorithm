import java.util.*;

// r 좌표 먼저 맞추고 c 좌표 

class Pair{
    int y,x;
    public Pair(int y, int x){
        this.y = y;
        this.x = x;
    }
}

class Solution {
    // 상 하 좌 우 
    int[] dy = {-1, 1, 0, 0};
    int[] dx = {0, 0, -1, 1};
    int res = 0;
    public int solution(int[][] points, int[][] routes) {
        // 처음 위치 충돌 초기화
        getMove(points, routes);
        int answer = res;
        return answer;
    }
    
    public void getMove(int[][] points, int[][] routes) {
        // 각각의 로봇들의 경로를 저장 
        ArrayList<Pair>[] pos = new ArrayList[routes.length];
        for(int i =0; i<pos.length; i++){
            pos[i] = new ArrayList<Pair>();
        } 
        
        // i번 로봇의 이동 좌표 
        for(int i=0; i<routes.length; i++){
            for(int j=0; j<routes[i].length-1; j++){
                int y = points[routes[i][j]-1][0];
                int x = points[routes[i][j]-1][1];
                int dest_y = points[routes[i][j+1]-1][0];
                int dest_x = points[routes[i][j+1]-1][1];
                while(!(y== dest_y && x == dest_x)){
                    pos[i].add(new Pair(y, x)); 
                    int ny = y;
                    int nx = x;
                    if(y != dest_y){
                        if(y > dest_y){
                            ny = y + dy[0];
                        }else{
                            ny = y + dy[1];
                        }
                    }else if(x != dest_x){
                        if(x > dest_x){
                            nx = x + dx[2];
                        }else{
                            nx = x + dx[3];
                        }
                    }
                    
                    // 좌표 갱신
                    y = ny;
                    x = nx;
                }
            }
            // 맨 마지막 도착 위치 추가 
            int last_point = routes[i][routes[i].length-1]-1;
            pos[i].add(new Pair(points[last_point][0], points[last_point][1]));
        }
        
        // 충돌 횟수 갱신
        res = getCollisionCnt(pos);
        
    }
    
    // 총 충돌 횟수 리턴 
    public int getCollisionCnt(ArrayList<Pair>[] pos){
        int max_move = 0;
        for(ArrayList<Pair> list: pos){
            int cur_size = list.size();
            max_move = Math.max(max_move, cur_size);
        }
        
        int cnt = 0;
        for(int i=0; i< max_move; i++){
            int[][] collision = new int[101][101];
            for(int j=0; j<pos.length; j++){
                if(i < pos[j].size()){
                    Pair tmp = pos[j].get(i); 
                    collision[tmp.y][tmp.x] += 1;                    
                }
            }
            
            for(int y=1; y<=100; y++){
                for(int x=1; x<=100; x++){
                    if(collision[y][x] >= 2){
                      cnt += 1;  
                    }    
                }
            }
        }

        return cnt;
    }
    
}