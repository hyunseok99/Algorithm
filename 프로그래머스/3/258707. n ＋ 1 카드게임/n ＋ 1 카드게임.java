import java.util.*;



class Solution {
    int n;
    int round = 1;
    public int solution(int coin, int[] cards) {
        int answer = 0;
        int coin_size = coin;
        n = cards.length;
        
        // ex) 1 12, 2 11, 3 10 ... 끝 -> 6의 배수라 예외 없음, 즉 만족하는 쌍은 1개만 존재  
        // 카드 뽑을 떄 가능 경우: 뽑는 2개의 합이 n+1, 가진 카드와의 합이 n+1, 남은 카드뭉치와 합 n+1 
        // 효율 : 내패 2개 합이 n+1 > 가진 카드와의 합이 n+1 -> 2개 같이 뽑아야 합이 n+1
        // 이전에 코인을 소모해서 카드를 얻은 경우 vs 안쓰고 안뽑
        // 결국 라운드 증가 못하면 이전에 뽑았던 카드들로 n+1 만들어야 함 
        Map<Integer, Boolean> my_map = new HashMap<>(); // 가지고 있는 카드 
        Map<Integer, Boolean> dummy = new HashMap<>(); // 코인으로 구매 안한 카드 목록 

        int draw_idx = n/3; // 뽑을 카드 idx = n/3 + 2*(round-1), + 1
        
        for(int i=0; i<n/3; i++){
            my_map.put(cards[i], true);
        }
        
        while(true){
            // 뽑을 카드 x 
            System.out.println("draw_idx: "+ draw_idx);
            if(draw_idx >= n) break;
            dummy.put(cards[draw_idx], true);
            dummy.put(cards[draw_idx+1], true);
            draw_idx += 2;
            
            boolean check = false;
            
            // 가지고 있는 카드 합이 n+1
            int pair_first = -1;
            int pair_second = -1;
            for(int i: my_map.keySet()){
                if(my_map.containsKey(n+1-i)){
                    pair_first = i;   
                    pair_second = n+1-i;
                    break;
                }
            }
            
            if(pair_first != -1){
                my_map.remove(pair_second);
                my_map.remove(pair_first);
                System.out.println("round: " + round + "my_map: " + pair_first + ", " + pair_second + "제거, 코인: " +coin_size);
                check = true;
            }else if(coin_size >= 1){
                int pair_hand = -1;
                int pair_draw = -1;
                for(int i: my_map.keySet()){
                    if(dummy.containsKey(n+1-i)){
                        pair_hand = i;   
                        pair_draw = n+1-i;
                        break;
                    }
                }
                if(pair_hand != -1){
                    my_map.remove(pair_hand);
                    dummy.remove(pair_draw);
                    coin_size -= 1;
                    check = true;
                    System.out.println("round: " + round + "my_map: "+pair_hand + ", dummy: " + pair_draw + "제거, 코인: " +coin_size);
                }
            }
            if(check == false && coin_size >= 2){
                int pair_draw_first = -1;
                int pair_draw_second = -1;

                for(int i: dummy.keySet()){
                    if(dummy.containsKey(n+1-i)){
                        pair_draw_first = i;
                        pair_draw_second = n+1-i;
                        break;
                    }
                }
                
                if(pair_draw_first != -1){
                    dummy.remove(pair_draw_second);
                    dummy.remove(pair_draw_first);
                    coin_size -= 2;
                    check = true;
                    System.out.println("round: " + round + "dummy: "+ pair_draw_first + ", " + pair_draw_second + "제거, 코인: " +coin_size);
                    
                }
            }
            
            
            if(check == true){
                System.out.println("round++");
                round++;
            }else{
                break;
            }
        }
        answer = round;
        return answer;
    }
    
}