import java.util.*;
import java.io.*;

// max 되게 보급 -> 이거 보통 max가 y가 되도록 이분탐색 활용했던 기억 

// 이벤트 Q <= 200,000
// 집 N <= 20,000
// 처음 비축량 <= 10억
// 영지 강화당 최대 100만 
// 최대 이주 1,000번 
// 겨울나기 제공 p 최대 1조 ?

// 200000 * 10^12 ~= 2* 10^15  가능한 최대 값  2천조 
// 이분탐색으로 최적 제공 구하는 복잡도 O(log10^9+ * N) ~= 36*N

// 보급을 받기때문에 -> 다음 겨울나기는 이전 겨울나기보다 값이 커짐 
// 새로 들어오는 경우 고려하면
// new + p <= 이전 max :  new + p가 최대 기록  

// 처음에 min, max 활용 

// map으로 비축량, 갯수 로 관리해야 할 듯 
// 겨울을 나게되는 누적된 reinforceVal을 기억하고 새로운 집 추가할때 -> (x - reinforceVal) 을 저장해야 할 듯?


// 결국 이분탐색하면 95만 -> 초과 , 누적합 이용해야 할 듯


public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
    static long[] prefixSum = new long[21005];
    static boolean isChanged = true; // 누적합 연산을 다시 수행해야 하는 경우 


    public static void main(String[] args) throws Exception {
        long reinforceVal = 0L;
        List<Long> houseList = new ArrayList<>();

        int Q = Integer.parseInt(br.readLine());
        for (int i = 0; i < Q; i++) {
            String line = br.readLine();
            StringTokenizer st = new StringTokenizer(line);
            int eventCode = Integer.parseInt(st.nextToken());

            if (eventCode == 100) {
                st.nextToken(); // 필요없음 N
                initEvent(houseList, st);
            }

            if (eventCode == 200) {
                doMigrateEvent(houseList, Long.parseLong(st.nextToken()), reinforceVal);
            }

            if (eventCode == 300) {
                reinforceVal = doReinforceEvent(reinforceVal, Long.parseLong(st.nextToken()));
            }

            if (eventCode == 400) {
                long ans = endureWinterEvent(houseList, Long.parseLong(st.nextToken()), reinforceVal);
                bw.write(ans + "\n");
            }
        }
        bw.flush();
    }

    // 100
    public static void initEvent(List<Long> houseList, StringTokenizer st) {
        while (st.hasMoreTokens()) {
            long key = Long.parseLong(st.nextToken());
            houseList.add(key);
        }
        Collections.sort(houseList);
        isChanged = true;
    }

    // 200
    public static void doMigrateEvent(List<Long> houseList, long x, long reinforceVal) {
        long key = x - reinforceVal;
        int pos = Collections.binarySearch(houseList, key);
        if (pos < 0) pos = -(pos + 1); // 삽입할 위치 계산
        
        houseList.add(pos, key);
        isChanged = true;
    }

    //  300
    public static long doReinforceEvent(long reinforceVal, long p) {
        return reinforceVal + p;
    }

    // 400: 누적합 + 이분 탐색으로 O(log N)만에 최솟값의 최댓값 계산
    public static long endureWinterEvent(List<Long> houseList, long p, long reinforceVal) {
        int size = houseList.size();

        // 집이 추가/초기화되었다면 누적합 배열 갱신 O(N)
        if (isChanged) {
            prefixSum[0] = 0L;
            for (int i = 0; i < size; i++) {
                prefixSum[i + 1] = prefixSum[i] + houseList.get(i);
            }
            isChanged = false;
        }

        // 앞에서부터 k개의 집을 처리할 수 있는지 이분 탐색 (1 <= k <= size)
        int left = 1;
        int right = size;
        int bestK = 1;

        while (left <= right) {
            int midK = (left + right) / 2;
            long sum = prefixSum[midK] + (reinforceVal * midK);
            long target = houseList.get(midK-1) + reinforceVal;
      
            if ( ((sum + p) / midK) >= target) {
                bestK = midK;
                left = midK + 1;
            } else {
                right = midK - 1;
            }
        }

        long maxMinBaseVal = (prefixSum[bestK] + (reinforceVal * bestK) );
        return (maxMinBaseVal + p) / bestK;
    }

/*
    // 처음 이분탐색 방식 

    public static void main(String[] args) throws Exception {
        // Please write your code here.
        long reinforceVal = 0L;
        TreeMap<Long,Integer> houseMap = new TreeMap<>(); // 식량 p인 집의 수 
        // list<long> (p)
        int Q = Integer.parseInt(br.readLine());
        for(int i=0; i < Q; i++){
            String line = br.readLine();
            StringTokenizer st = new StringTokenizer(line);
            int eventCode = Integer.parseInt(st.nextToken());
            
            if(eventCode == 100){
                st.nextToken(); // 필요없음 N
                initEvent(houseMap, st);
            }

            if(eventCode == 200){
                doMigrateEvent(houseMap, Long.parseLong(st.nextToken()), reinforceVal);
            }         

            if(eventCode == 300){
                reinforceVal = doReinforceEvent(reinforceVal, Long.parseLong(st.nextToken()));
            } 

            if(eventCode == 400){
                long ans = endureWinterEvent(houseMap, Long.parseLong(st.nextToken()), reinforceVal);
                bw.write(ans + "\n");
            }
            bw.flush();
        }
    }

    // 100: init 
    public static void initEvent(TreeMap<Long,Integer> houseMap, StringTokenizer st){
        while(st.hasMoreTokens()){
            long key = Long.parseLong(st.nextToken());
            houseMap.put(key, houseMap.getOrDefault(key, 0)+ 1);
        }

        // System.out.println(houseMap);
        return; 
    }

    // 200 :  add house & update [min,max] values
    // 누적된 강화가 20일때 새로운 이주자가 20 비축량 가지고 오는 경우 -> map에는 20-20이 key
    public static void doMigrateEvent(TreeMap<Long,Integer> houseMap, long x, long reinforceVal){
        // add 
        long key = x - reinforceVal;
        houseMap.put(key, houseMap.getOrDefault(key, 0) + 1);
        return;
    }

    // 300 : return [sum of 300 reinforce] val 
    // O(N+1000) * Q 직접 매번 더하면 -> 복잡도 터짐 
    public static long doReinforceEvent(long reinforceVal, long p){
        return reinforceVal + p;
    }

    // 400 : 누적 강화 반영한 min 값 return 
    // 모든 집에 대해서 순회는 초과 
    public static long endureWinterEvent(TreeMap<Long, Integer> houseMap, long p, long reinforceVal){
        long minVal = houseMap.firstKey() + reinforceVal;
        long maxVal = houseMap.lastKey() + reinforceVal + p;

        long answer = minVal;

        while(minVal <= maxVal){
            long sum = 0L;
            long midVal = (minVal + maxVal) / 2;

            // map에 저장되어있는 key값은 val - reinforceVal 
            for(Map.Entry<Long, Integer> entry: houseMap.entrySet()){
                long key = entry.getKey();
                if(key + reinforceVal >= midVal) break; // treemap 오름차순이라 이후는 추가 식량 배급 필요 x 
                sum += (midVal - (key + reinforceVal)) * entry.getValue();
                
                if(sum > p) break;
            }
            
            if(sum > p){
                maxVal = midVal -1;
            }else{
                answer = midVal;
                minVal = midVal + 1;
            }
        }

        return answer; 
    }
*/

}