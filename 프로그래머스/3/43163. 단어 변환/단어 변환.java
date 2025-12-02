import java.util.*;


class Solution {
    int answer = 0;
    public int solution(String begin, String target, String[] words) {
        ArrayList<String> cur = new ArrayList<>();
        cur.add(begin);
        dfs(words, cur, target);
        return answer;
    }
    
    // 멈추는 경우: target 완성, 모두 변경 후 target 변환 실패 or 더이상 변환 불가
    // ex) lot -> dot -> lot 고려 
    public void dfs(String[] words, ArrayList<String> cur, String target){
        String latest = cur.get(cur.size()-1);
        if(latest.equals(target)){
            answer = cur.size()-1;
            return;
        }
        
        
        
        for(int i=0; i<words.length; i++){
            boolean flag = false;
            for(int j=0; j<cur.size(); j++){
                if(words[i].equals(cur.get(j))){
                    flag = true;
                    break;
                }
            }
            if(flag) continue;
            int diff_cnt = 0;
            for(int j=0; j<latest.length(); j++){
                String a = words[i].substring(j,j+1);
                String b = latest.substring(j,j+1);
                if(!a.equals(b)){
                    diff_cnt++;
                }
            }
            if(diff_cnt == 1){
                ArrayList<String> next = new ArrayList<>(cur);
                next.add(words[i]);
                dfs(words, next, target);
            }
        }
        
    }
}