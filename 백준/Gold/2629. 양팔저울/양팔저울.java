import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        boolean[][] dp = new boolean[n+1][15001];
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for(int i = 0;i<n;i++){
            arr[i]=Integer.parseInt(st.nextToken());
        }
        for(int i =1;i<=n;i++){
            for(int j =15000;j>0;j--){
                if(dp[i-1][j]){
                    dp[i][j]=true;
                    if(j+arr[i-1]<=40000)
                        dp[i][j+arr[i-1]]=true;
                        dp[i][Math.abs(j-arr[i-1])]=true;
                }
            }
            dp[i][arr[i-1]]=true;
        }
        int m = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        st = new StringTokenizer(br.readLine());
        for(int i = 0;i<m;i++){
            int t = Integer.parseInt(st.nextToken());
            if(t<=15000&&dp[n][t])
                sb.append("Y ");
            else sb.append("N ");
        }
        System.out.println(sb);
        br.close();
    }
}