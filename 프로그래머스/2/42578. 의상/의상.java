import java.util.*;

// 다른 의상 종류에서: 입을지 안입을지 모든 의상에 2가지 가능 -> 모두 벗은 경우만 제외 
// 같은 종류에서: 입는 경우: n개 , 안입는 경우 추가 n+1
// 마지막 모두 안입는경우 -1 
class Solution {
    public int solution(String[][] clothes) {
        int answer = 0;
        
        HashMap<String ,Integer> myMap = new HashMap<>();
        
        for(String[] cloth: clothes){
            String key = cloth[1];
            if(myMap.get(key) == null){
                myMap.put(key, 1);
            }else{
                myMap.put(key, myMap.get(key)+1);
            }
        }
        
        answer = getAnswer(myMap);
        return answer;
    }
    
    static int getAnswer(HashMap<String ,Integer> myMap){
        int ans = 1;
        for(Integer val: myMap.values()){
            ans *= (val+1);
        }
        ans -= 1;
        return ans;
    }
}