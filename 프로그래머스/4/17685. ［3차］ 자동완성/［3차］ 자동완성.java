import java.util.*;

// depth를 관리하면 될 듯 
class Node{
    int cnt=0;
    Node[] arr = new Node[26];
}

class Solution {
    public int solution(String[] words) {
        int answer = 0;
        // O(L)
        Node root = new Node();
        for(String word: words){
            Node cur = root;
            for(int i=0; i<word.length(); i++){
                int val = word.charAt(i) - 'a';
                if(cur.arr[val] == null){
                    cur.arr[val] = new Node();
                }
                cur = cur.arr[val];
                cur.cnt++;
            }
        }        
        
        for(String word: words){
            Node cur = root;
            for(int i=0; i<word.length(); i++){
                int val = word.charAt(i)-'a';
                if(cur.arr[val].cnt <=1){
                    answer += i+1;
                    break;
                }
                cur = cur.arr[val];
                if(i == word.length()-1){
                    answer += i+1;
                }
            }
        }
        
        return answer;
    }
}