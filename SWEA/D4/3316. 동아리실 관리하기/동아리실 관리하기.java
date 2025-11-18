import java.io.*;
import java.util.*;

class Solution {

    static final long MOD = 1000000007;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for(int tc=1;tc<=T;tc++){
            sb.append("#").append(tc).append(" ");
            String str = br.readLine();
            long[][] dp = new long[str.length()][16];
            for(int j = 0;j<str.length();j++){
                int key = 1 << (str.charAt(j) - 'A');
                if(j==0) key|=1;
                for(int k = 1;k<16;k++){
                    if(j==0){
                        if((k&key)==key){
                            dp[j][k] = 1;
                        }
                    }
                    else{
                        if (dp[j - 1][k] != 0) {
                            for (int i = 1; i < 16; i++) {
                                if ((i & k) != 0 && (i & key) != 0){
                                    dp[j][i] += (dp[j - 1][k]);
                                    dp[j][i]%=MOD;
                                }
                            }
                        }
                    }
                }
            }
            long sum = 0;
            for(int i = 1;i<16;i++){
                sum += dp[str.length() - 1][i];
                sum%=MOD;
            }
            sb.append(sum).append("\n");
        }
        System.out.println(sb);
    }
}