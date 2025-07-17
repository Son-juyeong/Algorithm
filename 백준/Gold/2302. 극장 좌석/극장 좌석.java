import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        boolean[] arr = new boolean[n+1];
        int[] dp = new int[n+1];
        dp[0]=1;
        int m = Integer.parseInt(br.readLine());
        for(int i = 0;i<m;i++){
            int t = Integer.parseInt(br.readLine());
            arr[t]=true;
        }
        int idx = 0;
        int answer = 1;
        for(int i = 1;i<=n;i++){
            if(arr[i]){
                idx=i;
                answer*=dp[i-1];
                dp[i]=1;
            }
            else{
                if(i==idx+1){
                    dp[i]=1;
                }
                else if(i==idx+2){
                    dp[i]=2;
                }
                else{
                    dp[i]=dp[i-1]+dp[i-2];
                }
                if(i==n)
                    answer*=dp[i];
            }
        }
        System.out.println(answer);
    }
}
