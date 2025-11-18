import java.util.*;

// size >= 2,  sum > imit 이면 새로운 방 생성과 동일 
// 최대한 무거운 사람을 붙이면 최소 
class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        // 사람을 무게가 높은 순으로 정렬해서 무게가 최대인 사람이 앞쪽에 오도록 구성 
        // 가장 가벼운사람, 무거운 사람을 투포인터로 갯수 연산
        // 
        Arrays.sort(people);
        int min_idx = 0;
        for(int i=people.length-1; i>=min_idx; i--){
            if(people[i] + people[min_idx] <= limit){
                answer++;
                min_idx++;
            }else{
                answer++;
            }
        }
        
        return answer;
    }
}