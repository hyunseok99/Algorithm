import java.util.*;

// 이전이 최소여도 -> 이후가 최소임을 보장 x 
// 이후까지 연산 후에 최소가 되는것을 찾아야 함 
// 무조건 다이아 곡괭이 > 철 곡괭이 > 돌 곡괭이 순으로 모두 사용하는게 베스트
class Solution {
    // 메모이제이션 -> 다,철,돌 곡괭이 x,y,z개 사용했을 때의 최소 피로도 
    int[][][] memo = new int[6][6][6];
    // 괭이별 피로도 소모 : 다,철,돌
    int[][] exhaust = {{1,1,1}, {5,1,1},{25,5,1}};
    String[] arr;
    int last_mineral;
    int[] picks_limit = new int[3]; // 곡괭이 갯수 제한 
    public int solution(int[] picks, String[] minerals) {
        int answer = Integer.MAX_VALUE;
        arr = minerals;
        last_mineral = minerals.length;
        picks_limit[0] = picks[0];
        picks_limit[1] = picks[1];
        picks_limit[2] = picks[2];
        
        for(int i=0; i<=5; i++){
            for(int j=0; j<=5; j++){
                for(int k=0; k<=5; k++){
                    memo[i][j][k] = -1;
                }
            }
        }
        
        answer = getDp(0, 0, 0);
        
        return answer;
    }
    
    public int getDp(int x, int y, int z){
        // 사용한 곡괭이 수
        int use = x + y + z;
        int mineral_idx = use * 5; // 0~4, 5~9, 10~14: 탐색 시작 idx
        // 더 캘 광물이 없거나, 곡괭이 없으면 종료
        int tot_picks = picks_limit[0] + picks_limit[1] + picks_limit[2]; 
        if(use == tot_picks || mineral_idx >= last_mineral){
            return 0;
        }
        
        // 만약 메모이제이션이 되어있으면 메모 리턴
        if(memo[x][y][z] != -1){
            return memo[x][y][z];
        }
        
        // 피로량
        int res = Integer.MAX_VALUE;
        
        // 각각의 곡괭이 사용 가능시 연산
        if(x < picks_limit[0]){
            res = Math.min(res, calcEffort(mineral_idx, 0) + getDp(x+1,y,z));
        }
        if(y < picks_limit[1]){
            res = Math.min(res, calcEffort(mineral_idx, 1) + getDp(x,y+1,z));
            
        }
        if(z < picks_limit[2]){
            res = Math.min(res, calcEffort(mineral_idx, 2) + getDp(x,y,z+1));
        }
        // 메모이제이션 저장
        memo[x][y][z] = res;
        return res;
    }
    
    public int calcEffort(int idx, int type){
        int sum = 0;
        for(int i = idx; i < idx+5 && i < last_mineral; i++){
            if(arr[i].equals("diamond")){
                sum += exhaust[type][0];
            }else if(arr[i].equals("iron")){
                sum += exhaust[type][1];
            }else{
                sum += exhaust[type][2];
            }
        }
        return sum;
    }
}