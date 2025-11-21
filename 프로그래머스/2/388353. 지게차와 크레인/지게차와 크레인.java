import java.util.*;

// 외부와 비어있는 경우 구분 필요 
// 비어있는 경우는 크레인을 사용하고 -> 상하좌우가 모두 박스인 경우 해당 
// 외부는 "0", 비어있는 경우는 "1"

class Solution {
    int max_y, max_x, max_arr_y, max_arr_x;
    int[] dy = {-1,1,0,0};
    int[] dx = {0,0,-1,1};
    int answer = 0;
    public int solution(String[] storage, String[] requests) {
        max_y = storage.length;
        max_x = storage[0].length();
        max_arr_y = max_y + 2;
        max_arr_x = max_x + 2;
        answer = max_y * max_x;
        String[][] arr = new String[max_arr_y][max_arr_x];
        for(int y=0; y<max_arr_y; y++){
            for(int x=0; x<max_arr_x; x++){
                // 외부
                if(y == 0 || y==max_arr_y-1 || x == 0 || x== max_arr_x-1){
                    arr[y][x] = "0";
                }else{
                    arr[y][x] = storage[y-1].substring(x-1,x);
                }
            }
        }
        for(String request: requests){
            String req = request.substring(0,1);
            if(request.length() == 2){
                // 크레인
                useCrane(req, arr);
            }else{
                // 지게차 
                useLift(req, arr);
            }
        }
        return answer;
    }
    
    // O(50 * 50 * 100 * 2) ~= 50만 
    public void useCrane(String s, String[][] arr){
        // 처리할 좌표 
        ArrayList<Integer> pos_y = new ArrayList<>();
        ArrayList<Integer> pos_x = new ArrayList<>();
        
        for(int y=0; y<arr.length; y++){
            for(int x=0; x<arr[0].length; x++){
                // 처리할 좌표 추가 
                if(arr[y][x].equals(s)){
                    pos_y.add(y);
                    pos_x.add(x);
                }
            }
        }
        
        // 출고, 기본적으로 내부에 존재하는 공간으로 출고 되었다고 가정 
        for(int i=0; i<pos_y.size(); i++){
            answer--;
            arr[pos_y.get(i)][pos_x.get(i)] = "1";
        }
        
        // 출고 이후 비어있는 공간들이 외부와 접촉하면 변경
        boolean[][] space_flag = new boolean[max_arr_y][max_arr_x];
        for(int y=1; y<max_arr_y; y++){
            for(int x=1; x<max_arr_x; x++){
                if(space_flag[y][x]) continue;
                if(arr[y][x].equals("1")){
                    modifySpace(y, x, arr, space_flag);
                }
            }
        }
        
    }
    
    public void useLift(String s, String[][] arr){
        // 출고할 좌표 
        ArrayList<Integer> pos_y = new ArrayList<>();
        ArrayList<Integer> pos_x = new ArrayList<>();
        
        // 하나라도 외부에 닿아 있으면 제거하고 외부가 된다
        for(int y=0; y<arr.length; y++){
            for(int x=0; x<arr[0].length; x++){
                if(arr[y][x].equals(s)){
                    boolean flag = false;
                    for(int dir=0; dir<4; dir++){
                        int ny = y + dy[dir];
                        int nx = x + dx[dir];
                        if(arr[ny][nx].equals("0")){
                            flag = true;
                            break;
                        }
                    }
                    if(flag){
                        pos_y.add(y);
                        pos_x.add(x);
                    }
                }
            }
        }
        
        // 출고 
        for(int i=0; i<pos_y.size(); i++){
            answer--;
            arr[pos_y.get(i)][pos_x.get(i)] = "0";
        }
        
        // 출고 이후 비어있는 공간들이 외부와 접촉하면 변경
        boolean[][] space_flag = new boolean[max_arr_y][max_arr_x];
        for(int y=1; y<max_arr_y; y++){
            for(int x=1; x<max_arr_x; x++){
                if(space_flag[y][x]) continue;
                if(arr[y][x].equals("1")){
                    modifySpace(y, x, arr, space_flag);
                }
            }
        }
        
    }
    
    // 빈공간 덩어리가 외부와 접촉하는지 반영 
    public void modifySpace(int y, int x, String[][] arr, boolean[][] flags){
        Stack<Integer> pos_y = new Stack<Integer>();
        Stack<Integer> pos_x = new Stack<Integer>();
        Stack<Integer> res_y = new Stack<Integer>();
        Stack<Integer> res_x = new Stack<Integer>();
        
        pos_y.add(y);
        pos_x.add(x);
        
        boolean check = false;
        while(!pos_y.isEmpty()){
            int cur_y = pos_y.pop();
            int cur_x = pos_x.pop();
            res_y.add(cur_y);
            res_x.add(cur_x);
            
            for(int dir=0; dir<4; dir++){
                int ny = cur_y + dy[dir];
                int nx = cur_x + dx[dir];
                if(ny < 0 || nx < 0 || ny >= max_arr_y || nx >= max_arr_x || flags[ny][nx]){
                    continue;
                }
                if(arr[ny][nx] == "0"){
                    check = true;
                }
                if(arr[ny][nx] == "1"){
                    pos_y.add(ny);
                    pos_x.add(nx);
                    flags[ny][nx] = true;
                }
            }
        }
        
        if(check){
            while(!res_y.isEmpty()){
                arr[res_y.pop()][res_x.pop()] = "0";
            } 
        }
    }    
    
}