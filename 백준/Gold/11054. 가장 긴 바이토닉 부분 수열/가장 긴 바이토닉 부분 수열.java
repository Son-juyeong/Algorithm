import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] dp1 = new int[n];
        int[] dp2 = new int[n];
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(arr[i]>arr[j])
                    dp1[i]=Math.max(dp1[i],dp1[j]+1);
            }
            if(dp1[i]==0) dp1[i]=1;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=i;j--){
                if(arr[i]>arr[j]){
                    dp2[i]=Math.max(dp2[i], dp2[j]+1);
                }
            }
            if(dp2[i]==0) dp2[i]=1;
        }
        int answer = 1;
        for(int i=0;i<n;i++){
            answer = Math.max(answer, dp1[i]+dp2[i]-1);
        }
        System.out.println(answer);
    }
}