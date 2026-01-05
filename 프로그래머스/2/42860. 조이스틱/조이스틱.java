import java.util.*;

// 좌, 우가 핵심 -> 상,하는 더 적은 것 선택 
class Solution {
    public int solution(String name) {
        int answer = 0;
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<name.length(); i++){
            sb.append('A');
        }
        
        // O(n)
        // 상하 이동 최소 동선 
        for(int i=0; i<name.length(); i++){
            // 알파벳 변경에 필요한 최소 동선 
            int diff1 = name.charAt(i) - sb.charAt(i); 
            int diff2 = 26 - diff1;
            int min_diff = Math.min(diff1, diff2);
            answer += min_diff;
        }
        
        // 좌, 우 이동의 최소 동선으로 변경 필요 idx 모두 수정 
        int start = 0;
        int move = name.length()-1; // 전부 오른쪽 이동한 경우
        for(int i=0; i< name.length(); i++){
            int next = i+1;
            while(next < name.length() && name.charAt(next) == 'A' ){
                next++;
            }       
            // 왼쪽 이동 후 오른쪽 vs 오른쪽 이동 후 왼쪽
            int diff = Math.min((name.length()-next + start), Math.abs(next - start));
            move = Math.min(move, i + i + name.length() - next);
            move = Math.min(move , name.length() - next + name.length() - next + i );
        }
        answer += move;
        return answer;
        
        
    }
}