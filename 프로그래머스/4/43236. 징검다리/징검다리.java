import java.util.*;

// 조합 이용하면 O(n^2)
// 조건에 부합하는 distance 보다 큰 길이가 n+1개 이상 존재하면 불가 
// 바위를 제거 -> 길이를 합친다 -> 합친 길이가 여전히 작으면 다음것도 제거 해야 함 
class Solution {
    public int solution(int distance, int[] rocks, int n) {
        Arrays.sort(rocks);
        
        ArrayList<Integer> calced_dist_list = new ArrayList<>();
        
        int bef = 0;
        for(int pos: rocks){
            calced_dist_list.add(pos-bef);
            bef = pos;
        }
        calced_dist_list.add(distance - bef);
        
        int answer = 0;
        int start = 0;
        int end = distance;
        
        while(start <= end){
            int mid = (start + end)/2;
            if(isAvail(mid, calced_dist_list, n)){
                answer = mid;
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        
        return answer;
    }
    
    boolean isAvail(int target, ArrayList<Integer> calced_dist_list, int n){
        int cnt = 0;
        int sum = 0;
        // 2 11 14 17 21
        // 2 9 3 3 4 4 
        // 4: 2,3,3
        for(int dist: calced_dist_list){
            if((dist+sum) < target){
                sum += dist;
                cnt += 1;
            }else{
                sum = 0;
            }
            if(cnt > n) return false;
        }
        return true;
        
    }
}