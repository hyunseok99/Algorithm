import java.util.*;

// 근태, 동평 점수
// 서로 간의 비교가 필요 
// O(n^2) 불가
// 1.인센 못받는 경우 고려 -> 2.석차 계산 -> 3. 원호보다 앞에 있는 경우들만 고려하면 된다. 
// 느낌상 스택쓰는 옆에 건물들 보이는 갯수 새는 것과 유사해 보임 
// 근태를 내림차순으로 -> 동평을 오름차순으로 비교하면 문제 해결 될 듯
// 
// [0]의 값이 최대인 경우와, [1]의 값이 최대인 경우 모두 고려가 필요함 
class Pair {
    int x,y;
    public Pair(int x, int y){
        this.x = x;
        this.y = y;
    }
}


class Solution {
    int sum = 0; // 원호 점수
    public int solution(int[][] scores) {
        // answer = 인센 순위 
        int answer = 1;
        Pair wanho_score = new Pair(scores[0][0], scores[0][1]); 
        sum = wanho_score.x + wanho_score.y;
        ArrayList<Pair> arr = new ArrayList<>();
        for(int i=0; i<scores.length; i++){
            arr.add(new Pair(scores[i][0], scores[i][1]));
        }
        
        // a 내림차순, b 오름차순으로 정렬
        Collections.sort(arr, (a, b) -> {
            if(a.x == b.x){
                return Integer.compare(a.y, b.y);
            }else{
                return Integer.compare(b.x, a.x);
            }
        });
        
        // 순회하며 등수 연산 
        int max_y = -1;
        
        for(int i=0; i<arr.size(); i++){
            Pair cur = arr.get(i);
            if(cur.y < max_y){
                if(cur.x == wanho_score.x && cur.y == wanho_score.y){
                    answer = -1;
                    break;
                }
            }else{
                max_y = Math.max(max_y, cur.y);
                if(cur.y + cur.x > sum){
                    answer++;
                }
            }
        }
        
        return answer;
    }
    

}