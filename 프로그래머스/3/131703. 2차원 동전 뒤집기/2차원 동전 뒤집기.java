import java.util.*;

// 최대 2^20 
class Solution {
    int max_y;
    int max_x;
    int answer;  
    public int solution(int[][] beginning, int[][] target) {
        max_y = beginning.length;
        max_x = beginning[0].length;
        answer = max_y * max_x + 1; // 최대 뒤집은 횟수 
        
        int[][] turned = new int[max_y][max_x];
        for(int i=0; i<max_y; i++){
            for(int j=0; j<max_x; j++){
                turned[i][j] = beginning[i][j] == 0 ? 1 : 0;
            }
        }
        // 뒤집으면 1 그대로면 0 
        // ex) 3 -> 11  -> row 0,1 뒤집은 상태 
        // 행을 뒤집고 -> 열을 뒤집어 
        // row,col & 연산으로 0,1 -> sum % 2 -> 짝: 그대로, 홀: 반전 
        for(int row = 0; row < Math.pow(2, max_y); row++){
            getTurn(row, beginning, turned, target);
        }
        
        if(answer == max_y * max_x + 1){
            answer = -1;
        }
        return answer;
    }
    
    // bit & 연산으로 row, col 뒤집
    public void getTurn(int r, int[][] beginning, int[][] turned, int[][] target){
        // 0, 1 
        // 뒤집은 행, 열의 합 반영 
        // r = 2^3 + 1 -> 1001
        // ex) 3 -> 011  
        
        int flip_cnt = 0;
        for(int i=0; i< max_y; i++){
            if((r & (1 << i)) != 0) flip_cnt++;
        }
        
        // 행이 결정되어 있으니 열을 결정 
        for(int col=0; col < max_x; col++){
            int same_cnt = 0;
            for(int row=0; row < max_y; row++){
                int r_flip = (r & (1 << row)) != 0 ? 1:0;
                
                // ex) 1 -> flip = 2  -> % 2 = 0
                //     0 -> filp = 1 -> % 2 = 1
                int cur_val;
                if(r_flip % 2 == 0){
                    cur_val = beginning[row][col];
                }else{
                    cur_val = turned[row][col];
                }
                
                if(cur_val == target[row][col]) same_cnt++;
            }
            if(same_cnt == max_y){
                // 열의 갯수가 모두 동일 -> 뒤집을 필요 없음
                continue;
            }else if(same_cnt == 0){
                // 정반대 -> 해당 열 뒤집어야 함 
                flip_cnt++;
            }else{
                // 만들기 불가 
                return;
            }
        }
        
        answer = Math.min(answer, flip_cnt);
    }
}