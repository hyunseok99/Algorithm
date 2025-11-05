import java.util.*;
// 조합 O(n^2) -> 가짓수 O(n^2)

// nC2 * 6^(n/2) * 6^(n/2) ~= 100 * 7000 *7000 ~= 50억
// 합들의 배열 정렬 -> 커지거나 같아지는 idx까지 계산 => 행성 크기 비교 문제 비슷
// ex) 1,4 -> 2,3 승패 반대 
class Solution {
    int dice_size;
    int dice_element_size;
    int win_cnt = -1;
    int[] answer;
    public int[] solution(int[][] dice) {
        dice_size = dice.length;
        dice_element_size = dice[0].length;
        answer = new int[dice_size/2];
        // 선택된 번호
        int[] selected = new int[dice_size];
        getComb(0,0, selected, dice);
        return answer;
    }
    
    // 선택된 주사위의 경우에 -> 최대가 되는 주사위 번호 갱신 
    public void getAns(int[][] dice, int[] selected){
        // selected , unSelected
        ArrayList<Integer> selected_sum = new ArrayList<>();
        ArrayList<Integer> unSelected_sum = new ArrayList<>();
        ArrayList<Integer> selected_idx =new ArrayList<>();
        ArrayList<Integer> unSelected_idx =new ArrayList<>();
        for(int i=0; i<selected.length; i++){
            if(selected[i] != 0){
                selected_idx.add(i);
            }else{
                // unSelected
                unSelected_idx.add(i);
            }
        }
        // sum 수행
        getSum(0, 0, selected_idx, selected_sum, dice);
        getSum(0, 0, unSelected_idx, unSelected_sum, dice);
        
        // selected, unselected를 비교해서 -> A > B 를 만족하는 가장 작은 idx를 찾으면 그게 승리 횟수
        // O(6^n) * O(log 6*n) -> nlogn 
        // Collections.sort(selected_sum);
        Collections.sort(unSelected_sum);
        // 4 5 5 5 5 6
        // 2 2 2 6 7 8
        int tot_cnt = 0; // 승리 가짓수 
        for(int i=0; i<selected_sum.size(); i++){
            int target = selected_sum.get(i);
            int start = 0;
            int end = unSelected_sum.size();
            while(start < end){
                int mid = (start+end)/2;
                if(target > unSelected_sum.get(mid)){
                    start = mid + 1;
                }else{
                    end = mid;
                }
            }
            // ex) 4 -> idx 3 -> 3개 가능 
            tot_cnt += start;
        }
        
        if(tot_cnt > win_cnt){
            win_cnt = tot_cnt;
            ArrayList<Integer> ans = new ArrayList<>();
            int[] arr_ans = new int[dice_size/2];
            for(int i=0; i<selected.length; i++){
                if(selected[i] != 0){
                    ans.add(i);
                }
            }
            for(int i=0; i<ans.size(); i++){
                arr_ans[i] = ans.get(i)+1; // 0~n-1
            }
            answer = arr_ans;
        }
    }
    
    // 선택된 주사위, 선택되지 않은 주사위들의 합 갱신
    public void getSum(int idx, int cur_sum, ArrayList<Integer> dice_indices, ArrayList<Integer> sum_list, int[][] dice){
        if(idx == dice_size/2){
            sum_list.add(cur_sum);
            return;
        }
        int dice_idx = dice_indices.get(idx);
        for(int val: dice[dice_idx]){
            getSum(idx+1, cur_sum +val, dice_indices, sum_list, dice);
        }
    }
    
    public void getComb(int start_idx, int lev, int[] selected, int[][] dice){
        if(lev >= (dice_size/2)){
            // 선택된 n/2 조합 
            getAns(dice, selected);
            return;
        }
        
        for(int i=start_idx; i<dice_size; i++){
            if(selected[i] != 0){
                continue;
            }else{
                selected[i] = 1;
                getComb(i+1, lev+1, selected, dice);
                selected[i] = 0;
            }
        }
    }
}


