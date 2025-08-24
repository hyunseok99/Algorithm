import java.util.*;
// 맞는 경우 무조건 넣는게 최대 
class pos{
  int y,x; 
  pos(int y, int x){
      this.y = y;
      this.x = x;
  }
};

class Solution {
    static int row;
    static int col;
    static int res;
    // 상 하 좌 우
    static int[] dy = {-1, 1, 0, 0};
    static int[] dx = {0,0, -1, 1};
    public int solution(int[][] game_board, int[][] table) {
        int answer = -1;
        row = game_board.length;
        col = row;
        
        // 게임 보드 빈 조각들 찾기
        ArrayList<ArrayList<pos>> empty_frag = getEmptyFragment(game_board);
        // 테이블 조각들 찾기
        ArrayList<ArrayList<pos>> frag = getFragment(table);
        
        // 게임보드 빈 공간과 비교 -> 남은 조각들 90도 회전
        for(int i=0; i<4; i++){
            if(i > 0){
                rotateQuarter(frag);
            }
            compEach(frag, empty_frag);
        }
        
        // 정답 출력 
        answer = res;
        return answer;
    }
    
    // 시계방향 90도 회전 함수
    static void rotateQuarter(ArrayList<ArrayList<pos>> frag){
        
        // 남은 조각들 90도 회전 기준점 설정 
        for (ArrayList<pos> piece: frag){
            for(pos p: piece){
                // 시계방향 90도 회전 -> (-1,2) -> (2,1) : (x,y) -> (y, -x)
                int tmp = p.y;
                p.y = -p.x;
                p.x = tmp;
            }
            // 0,0으로 정규화
            normalize(piece);
        }
        return;
    }
    
    static ArrayList<ArrayList<pos>> getEmptyFragment(int [][] game_board){
        int [][] empty_flag = new int [row][col];
        ArrayList<ArrayList<pos>> empty_arr = new ArrayList<>();
        // board의 빈공간과 조각을 비교해서 삽입 가능 여부 확인 
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(game_board[i][j] == 0 && empty_flag[i][j] == 0){
                    ArrayList<pos> tmp_list = new ArrayList<>();
                    getPos(i, j, 0, game_board, empty_flag, tmp_list);
                    // empty_arr.get(empty_idx) -> empty_idx는 빈 조각 번호
                    normalize(tmp_list);
                    empty_arr.add(tmp_list);
                }
            }
        }
        return empty_arr;
    }
    
    static ArrayList<ArrayList<pos>> getFragment(int[][] table){
        // table에서 조각 찾고 -> 삽입 가능한 조각이 board에 있는지 체크 -> 가능하면 삽입 -> rotate
        int [][] flag = new int [row][col];
        ArrayList<ArrayList<pos>> arr = new ArrayList<>();
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(table[i][j] == 1 && flag[i][j] == 0){
                    ArrayList<pos> tmp_list = new ArrayList<>();
                    getPos(i, j, 1,table, flag, tmp_list);
                    normalize(tmp_list);
                    arr.add(tmp_list);
                }
            }
        }
        return arr; 
    }
    
    // type = 1 -> table 조각 찾을 때, 0 -> game_bard 빈 조각 찾을 때 
    static void getPos(int y, int x, int type, int [][] board, int [][] flag, ArrayList<pos> arr){
        flag[y][x]++;
        arr.add(new pos(y,x));
        for(int i=0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >=0 && nx >= 0 && ny < row && nx < col && flag[ny][nx] == 0 && board[ny][nx] == type)
            {
                getPos(ny, nx, type, board, flag, arr);
            }
            
        }
    }
                   
    // 0,0 기준으로 정규화 정렬
    static void normalize(ArrayList<pos> piece){
        int minX = Integer.MAX_VALUE;
        int minY = Integer.MAX_VALUE;
        for (pos p : piece) {
            minX = Math.min(minX, p.x);
            minY = Math.min(minY, p.y);
        }
        for (pos p : piece) {
            p.x -= minX;
            p.y -= minY;
        }
        
        // 정렬을 통해 모양을 비교하기 쉽게 만듭니다.
        piece.sort(Comparator.comparingInt((pos p) -> p.y).thenComparingInt(p -> p.x));
    }
    
    static void compEach(ArrayList<ArrayList<pos>> frag, ArrayList<ArrayList<pos>> eFrag) {
        for (int i = frag.size() - 1; i >= 0; i--) {
            ArrayList<pos> piece = frag.get(i);

            for (int j = eFrag.size() - 1; j >= 0; j--) {
                ArrayList<pos> emptyPiece = eFrag.get(j);

                // 크기가 같을 경우에만 비교 시작
                if (piece.size() == emptyPiece.size()) {
                    boolean isMatch = true;
                    // 정렬된 좌표이므로 순서대로 비교
                    for (int k = 0; k < piece.size(); k++) {
                        if (piece.get(k).y != emptyPiece.get(k).y || piece.get(k).x != emptyPiece.get(k).x) {
                            isMatch = false;
                            break;
                        }
                    }

                    if (isMatch) {
                        res += piece.size();

                        // 매칭된 조각과 빈 공간을 모두 제거
                        frag.remove(i);
                        eFrag.remove(j);

                        // 하나의 빈 공간에 하나의 조각을 채웠으므로, 다음 조각으로 이동
                        break; 
                    }
                }
            }
        }
    }
}