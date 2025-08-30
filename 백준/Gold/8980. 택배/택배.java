import java.io.*;
import java.util.*;


public class Main {
     // 문자열 입력
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int res = 0;
    static int n,c;

    public static class info{
        int end;
        int box;

        info(int end, int box){
            this.end = end;
            this.box = box;
        }
    }

    public static void main(String args[]) throws IOException {
        String[] str = br.readLine().split(" ");
        n = Integer.parseInt(str[0]);
        c = Integer.parseInt(str[1]);
        int m = Integer.parseInt(br.readLine());

        // 최대한 가까운거 먼저 처리하면 최대가 될 듯
        // 다음 마을껀 무조건 챙기고 나머지 먼쪽은 경우의 수가 있음 -> 너무 멀면 최대가 아닐 수도 있음
        // 다음 마을껀 무조건 실어놓고 나머지 부분은 넣은 경우 넣지 않은 경우로 최대를 계산해야 할 듯

        // 현재 실어놓은 택배 정보 [idx] -> idx마을에서 내려야 함 // a.end가 더크면 나옴
        PriorityQueue<info> pq = new PriorityQueue<>((info a, info b) -> b.end - a.end);

        // 특정 마을에 내려야 하는 누적 택배 양
        int[] conSum = new int[n+1];

        // 택배에 실어져 있는 무게의 현재 합
        int sum = 0;

        // 마을별 박스 정보
        ArrayList<info>[] adj = new ArrayList[n+1];
        for(int i=1; i<=n; i++){
            adj[i] = new ArrayList<info>();
        }

        for(int i=0; i<m; i++){
            str = br.readLine().split(" ");
            info tmp = new info(Integer.parseInt(str[1]), Integer.parseInt(str[2]));
            adj[Integer.parseInt(str[0])].add(tmp);
        }

        // 마을 박스 정보 정렬
        for(int i=1; i<=n; i++){
            adj[i].sort((info a, info b) -> a.end - b.end);
        }

        // 도달하는 마을 기준
        for(int cur = 1; cur <= n; cur++){
            // 2번 마을 이상이면 뺄 택배 있으면 일단 다 빼서 결과값 갱신 + 남은 택배들 중에서 이전에 가져온거 무효 처리하고 새로 추가하는 경우 고려
            if(cur >= 2){
                // 일단 이전 마을에서 싣고 온 짐들의 합이 c 이하가 되도록 작업
                while(sum > c){
                    if(pq.isEmpty()){
                        break;
                    }

                    info toDelete = pq.peek();
                    if(toDelete.end < cur){
                        pq.poll();
                        continue;
                    }

                    if(sum - toDelete.box > c){
                        pq.poll();
                        sum -= toDelete.box;
                        conSum[toDelete.end] -= toDelete.box;
                    }else{
                        pq.poll();
                        int len = sum - c;
                        int nBox = toDelete.box - len;
                        sum -= len;
                        conSum[toDelete.end] -= len;
                        info tmp = new info(toDelete.end, nBox);
                        pq.add(tmp);
                    }
                }
                // 해당 마을에서 제거 가능한 택배 제거 및 정답 갱신
                res += conSum[cur];
                sum -= conSum[cur];
//                System.out.println(cur + "번 마을 " + conSum[cur] + " 개 제거\n");

                conSum[cur] = 0;
                // 기존 택배 + 새로운 택배 이용해서 다시 우선순위큐에 삽입
                for(info box: adj[cur]){
                    // 일단 전부 실어
                    pq.add(box);
                    sum += box.box;
                    conSum[box.end] += box.box;
                } // -> 이게 다음 c이하가 되도록 하는 작업에서 자연스럽게 end 번호 큰놈 제거된다.

            }else{
                // 해당 마을에서 실을 택배들 선택 : 최대 무게까지 도달 하도록 -> 그냥 다 넣고 c 이하가 될때까지 pop하는 식으로
                for(info box: adj[cur]){
                    // 일단 전부 실어
                    pq.add(box);
                    sum += box.box;
                    conSum[box.end] += box.box;
                }
            }
        }


        bw.write(res + "");

        // 최종 출력
        bw.flush();
        bw.close();
    }
}