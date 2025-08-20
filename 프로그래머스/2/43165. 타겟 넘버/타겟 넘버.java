class Solution {
    public static int res = 0;
    public int solution(int[] numbers, int target) {
        dfs(numbers, target, 0, 0);
        int answer = res;
        return answer;
    }
    
    public static void dfs(int[] numbers, int target, int sum, int idx){
        if(idx >= numbers.length){
            if(sum == target){
                res++;
            }
            return;
        }
        // +, -
        for(int i=0; i<=1; i++){
            int num = numbers[idx];
            if(i == 1){
                num = -1 * num;
            }
            dfs(numbers, target, sum + num, idx+1);
        }
        
    }
}