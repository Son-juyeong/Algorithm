import java.io.*;
import java.util.*;

public class Main {

    static final int max = 100001;

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int c = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        int[] cost = new int[n];
        int[] person = new int[n];

        int[] dp = new int[max];

        for(int i =0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            cost[i] = Integer.parseInt(st.nextToken());
            person[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0;i<n;i++){
            for(int j =cost[i];j<max;j++){
                dp[j] = Math.max(person[i] + dp[j - cost[i]], dp[j]);
            }
        }

        for(int i =0;i<max;i++){
            if(dp[i]>=c){
                System.out.println(i);
                break;
            }
        }
    }
}