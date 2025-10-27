import java.util.*;

// 51 - 5 -> 8*5 + 9 - 5 =  8*5 + 4 = 8*5 + 4
// 2 ~ 9 진법  
// ex) 8 진법 -> 0~7 
// 각각의 자릿수 이하 + 합 자릿수 
// 자릿수로 진수 파악 필요함 
// 결과가 X인 경우 return 필요 
class Solution {
    public String[] solution(String[] expressions) {
        // 가능한 진법 여부 
        boolean[] flags = new boolean[10];
        Arrays.fill(flags, true);
        flags[0] = false;
        flags[1] = false;
        
        ArrayList<String> reqExpressions = new ArrayList<>();
        for(String express: expressions){
            
            String[] tokens = express.split(" ");
            if(tokens[4].equals("X")){
                // 나중에 정답 복구를 위해 추가
                reqExpressions.add(express);
            }
            for(int idx=2; idx<=9; idx++){
                if(flags[idx] == true){
                    judgeType(tokens, flags, idx);
                }                    
            }
        }
        

        
        // flag 이용해서 정답 갱신 
        ArrayList<String> res = new ArrayList<String>();
        for(String express: reqExpressions){
            String[] tokens = express.split(" ");
            String ans = getAnswer(tokens, flags);
            String newStr = express.substring(0, express.length()-1) + ans;
            res.add(newStr);
        }
        String[] answer = new String[res.size()];
        
        for(int i=0; i < res.size(); i++){
            answer[i] = res.get(i);
        }
        return answer;
    }
    
    // a + b = c에서 c != X 
    public void judgeType(String[] tokens, boolean[] flags, int flag_idx){
        Integer first_oper = Integer.parseInt(tokens[0]);
        String sign = tokens[1];
        Integer second_oper = Integer.parseInt(tokens[2]);
        // Integer res = Integer.parseInt(tokens[4]);
        // 조건 : 각 자릿수 보다 크거나 같아야 함 + 연산의 결과
        if(isCan(flag_idx, first_oper, second_oper, sign, tokens[4]) == false){
            // flag 갱신
            flags[flag_idx] = false;
        }


        
    }
    
    public boolean isCan(int type, int a, int b, String sign, String c){
        // 자릿수가 type보다 크거나 같다면 불가
        int a_quotient = a / 10;
        int a_remainder = a % 10;
        int b_quotient = b / 10;
        int b_remainder = b % 10;
        if(a_quotient >= type || a_remainder >= type || b_quotient >= type || b_remainder >= type){
            return false;
        }
        
        if(c.equals("X")){
            // 아직 미완 수식이면 좌변만 판단하고 return 
            return true;
        }
        Integer new_c = Integer.parseInt(c);
        
        int c_quotient1 = new_c / 100;
        int c_quotient2 = (new_c % 100) / 10;
        int c_remainder = (new_c % 100) % 10;
            
        if(sign.equals("+")){
            int add = (a_remainder + b_remainder) / type;
            int val = (a_remainder + b_remainder) % type;
            if(val == c_remainder){
                int next_add = (a_quotient + b_quotient + add) / type;
                int next_val = (a_quotient + b_quotient + add) % type;
                if(next_val == c_quotient2 && c_quotient1 == next_add){
                    return true;
                }
            }
            return false;
        }else{
            // "-"
            if(a_remainder < b_remainder){
                // 44 - 5
                if(c_remainder == (type + a_remainder - b_remainder)){
                    if(c_quotient2 == (a_quotient-1 - b_quotient)){
                        return true;
                    }
                }
                return false;
            }else{
                if(c_remainder == (a_remainder - b_remainder)){
                    if(c_quotient2 == (a_quotient - b_quotient)){
                        return true;
                    }
                }
                return false;
            }
        }
        
    }
    
    public String getAnswer(String[] tokens, boolean[] flags){
        Integer first_oper = Integer.parseInt(tokens[0]);
        String sign = tokens[1];
        Integer second_oper = Integer.parseInt(tokens[2]);
            
        HashMap<String, Integer> my_map = new HashMap<>();
        // flag에서 가능한 경우에 따른 결과값 -> 여러값 => ?
        
        String ans = "";
        
        int a_quotient = first_oper / 10;
        int a_remainder = first_oper % 10;
        int b_quotient = second_oper / 10;
        int b_remainder = second_oper % 10;
        
        for(int i = 2; i<=9; i++){
            if(flags[i] != true) continue;
            int type = i;
            if(sign.equals("+")){
                int add = (a_quotient + b_quotient + ((a_remainder + b_remainder) / type)) / type;
                int c_quotient = (a_quotient + b_quotient + ((a_remainder + b_remainder) / type)) % type;
                int c_remainder = (a_remainder + b_remainder) % type;
                String key = "" + add + c_quotient + c_remainder;
                if(add == 0){
                    key = "" + c_quotient + c_remainder;
                    if(c_quotient == 0){
                        key = "" + c_remainder;
                    }
                }
                if(!my_map.containsKey(key)){
                    my_map.put(key, 1);
                    ans = key;
                }
            }else{
                if(a_remainder >= b_remainder){
                    int c_quotient = a_quotient - b_quotient;
                    int c_remainder = a_remainder - b_remainder;
                    String key = "" + c_quotient + c_remainder;
                    if(c_quotient == 0){
                        key  = "" + c_remainder;
                    }
                    if(!my_map.containsKey(key)){
                        my_map.put(key, 1);
                        ans = key;
                    }
                }else{
                    int c_quotient = a_quotient-1 - b_quotient;
                    int c_remainder = type + a_remainder - b_remainder;
                    String key = "" + c_quotient + c_remainder;
                    if(c_quotient == 0){
                        key  = "" + c_remainder;
                    }
                    if(!my_map.containsKey(key)){
                        my_map.put(key, 1);
                        ans = key;
                    }
                }
            }
        }
        
        int key_cnt = my_map.size();
        
        if(key_cnt >= 2){
            return "?";
        }else{
            return ans;
        }
    }
}