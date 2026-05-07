import java.util.*;

class Solution {
    public class Pair{
        int start,end;
        public Pair(int start, int end){
            this.start = start;
            this.end = end;
        }
    }
    public int solution(int n, int[] stations, int w) {
        int answer = 0;

        // 전파가 필요한 start~end 구간들의 집합 마다 설치 필요 // ex) 1~2 6~9
        // 이전에 설치를 안해 -> 다음 구간에 설치해서 커버 불가면 x 
        // 현재 상태: 이전에 설치 + 현재 설치 x vs 이전 설치 x + 현재 설치
        
        // stations: 오름차순 정렬 
        
        // Pair: ex)1~1 1~3 11~11
        // 구간을 구할 필요 없이 stations를 순회하면서 커버 안된 부분을 내 기존의 cnt연산 방식으로
//         ArrayList<Pair> list = new ArrayList<>();
        
//         int start = 1;
//         for(int station: stations){
//             int covered_s = station-w;
//             int covered_end = station+w;
//             if(start < covered_s){
//                 list.add(new Pair(start,covered_s-1));
//             }
//             start = covered_end+1;
//         }
//         // 마지막 구간 추가
//         if(start <= n){
//             list.add(new Pair(start, n));
//         }
                
//         answer = getCnt(list, w);
        int start = 1;
        for(int station: stations){
            // 커버 범위 
            int cover_start = station - w;
            int cover_end = station + w;
            
            if(start < cover_start){
                int dist = cover_start - start;
                // 필요 기지국 
                answer += dist / (2*w + 1);
                if(dist % (2*w + 1) != 0) answer++;
            }
            start = cover_end + 1;
        }
        
        // 마지막 범위 체크
        if(start <= n){
            int dist = n-start+1;
            answer += dist / (2*w + 1);
            if(dist % (2*w + 1) != 0) answer++;
        }
        return answer;
    }
    
    // list: 커버 필요 범위 집합 
    public int getCnt(ArrayList<Pair> list, int w){
        if(list.isEmpty()) return 0;
        // 해당 구간에 안하고 이후 커버 범위 지나면 되돌려
        // 누적 구간이 2w+1보다 크거나 같으면 추가
        int cnt = 0;
        
        // p.start + w 지점에 설치하는게 무조건 이득 
        int pos = -20000;
        for(Pair p: list){
            if(pos == 0){
                pos = p.start + w;
                cnt++;
                continue;
            }
            // p.start <= pos+w 여부
            // System.out.println("cover: " + p.start + " ~ " + p.end);
            int next = Math.max(p.start, pos + w + 1); // 커버 완료된 범위 
            while(next <= p.end){
                pos = next + w;
                cnt++; 
                // System.out.println(pos + " 설치");
                next = pos + w + 1;
            }
        }
        return cnt;
        
    }
}