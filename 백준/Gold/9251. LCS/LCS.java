import java.io.*;

class Main {
        // 문자열 입력
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static int res = 0;

    public static void main(String args[]) throws IOException {
//        int len = Integer.parseInt(br.readLine());
        String str1 = br.readLine();
        String str2 = br.readLine();
        res = getLCS(str1, str2);

        // bufferwriter에 입력
        bw.write(res + "");

        // 최종 출력
        bw.flush();
        bw.close();
    }

    // 9251 최장 수열
    static int getLCS(String str1, String str2) throws IOException{
        // O(1000 * 1000) ~=100만  0.01초
        int[][] dp = new int[str1.length()+1][str2.length()+1];
        // dp[i][j] -> str1의 i번 인덱스까지, str2의 j번 인덱스까지 고려 했을 때 최대 공통 LCS

        // dp[i][j] = i-1번 문자와, j-1번 문자가 같으면 -> LCS 길이 증가
        // 다르면 -> dp[i][j] =  i-1 ~ j 까지의 LCS길이와, i ~ j-1 까지 LCS중 긴거 = max(dp[i-1][j], dp[i][j-1])
        for(int i=1; i<=str1.length(); i++){
            for(int j=1; j<=str2.length(); j++){
                if(str1.charAt(i-1) == str2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

//        // 추가로 복원
//        // dp[m][n] 에서 dp[0][0] 으로 거슬러 올라가면서 포함된 문자 찾기
//        // 두 문자가 같으면 포함, 다르다면 와 같은 경우 포함 x
//        // dp[i][j] == dp[i-1][j] 면 i--, 다른 경우 j--
//        StringBuilder sb = new StringBuilder();
//        int i = str1.length();
//        int j = str2.length();
//        while(i > 0 && j > 0){
//            if(str1.charAt(i-1) == str2.charAt(j-1)){
//                // lcs에 추가
//                sb.append(str1.charAt(i-1));
//                i--;
//                j--;
//            }else if(dp[i-1][j] >= dp[i][j-1]){
//                // i-1번까지 경로 확정이므로 i--;
//                i--;
//            }else{
//                // str2 버림
//                j--;
//            }
//        }
//
//        bw.write(sb.reverse().toString() + "\n");

        return dp[str1.length()][str2.length()];
    }
}