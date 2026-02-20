import java.util.*;
// O(n^2) 불가 

class Solution {
    
    // String , cnt 
    HashMap<String, Integer> my_map = new HashMap<>();
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        for(String str: phone_book){
            my_map.put(str, 1);
        }
        
        for(String str: phone_book){
            for(int i=1; i<str.length(); i++){
                String prefix = str.substring(0,i);
                if(my_map.containsKey(prefix)){
                    answer = false;
                    break;
                }
            }
        }
        
   
        return answer;
    }
}