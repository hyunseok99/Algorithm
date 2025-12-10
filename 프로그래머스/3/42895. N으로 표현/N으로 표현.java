import java.util.*;

// 1을 만들 수 있기 때문에 무조건 number를 만드는게 보장된다.

// x개의 n을 사용패서 만드는 숫자들의 종류를 저장 -> set[x] = { a, b, c ...}
// 1~8개까지의 가능한 경우를 위해서
// 1 -> 2 = (2+0, 1+1) -> 3(3, 2 + 1, 1 + 2) -> ... -> 8   이 로직으로 해결 
// 여기서 답 안나오면 -1 
class Solution {
    Set<Integer>[] my_set;
    public int solution(int N, int number) {
        int answer = -1;
        my_set = new Set[9]; // 최대 8
        for(int i=0; i<9; i++){
            my_set[i] = new HashSet<Integer>();
        }
        // 기본 init  
        String init_n = "";
        for(int i=1; i<=8; i++){
            init_n += N;
            my_set[i].add(Integer.parseInt(init_n));
        }
        
        // 기존의 set을 순회하며 
        // 1 -> 2 = (2+0, 1+1) -> 3(3, 2 + 1, 1 + 2) -> ... -> 8   끝  
        for(int target=2; target<=8; target++){
            for(int sub_a = 1; sub_a < target; sub_a ++){
                int sub_b = target - sub_a;
                // set 순회하며 가능한 패턴 연산 
                for(int val_a: my_set[sub_a]){
                    for(int val_b: my_set[sub_b]){
                        doMethod(target, val_a, val_b);
                    }
                }
            }
        }
        
        for(int i=1; i<=8; i++){
            if(my_set[i].contains(number)){
                answer = i;
                break;
            }
        }
        return answer;
    }
    
    // 사칙연산 수행 
    public void doMethod(int target, int a, int b){
        // +,-,*,/
        int[] arr = new int[4];
        arr[0] = a + b;
        arr[1] = a - b;
        arr[2] = a * b;
        if(b != 0 ){
            arr[3] = a / b;
        }
        
        // set에 추가 
        for(int i=0; i<4; i++){
            my_set[target].add(arr[i]);
        }
    }
}