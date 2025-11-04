import java.io.*;
import java.util.*;

public class Main {

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[] L = new int[n];
        int[] J = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0;i<n;i++){
            L[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for(int i = 0;i<n;i++){
            J[i] = Integer.parseInt(st.nextToken());
        }

        int[] dp = new int[100];

        for(int i = 0;i<n;i++){
            int l = L[i];
            for(int j =99;j>=l;j--){
                dp[j] = Math.max(dp[j], dp[j-l]+J[i]);
            }
        }

        System.out.println(dp[99]);
    }
}