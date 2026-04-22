import java.io.*;
import java.util.*;

public class Main{
    public static void main(String args[]) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int prize = Integer.parseInt(st.nextToken());
        
        int[] arr = new int[n];
        int total = 0;
        
        for(int i = 0;i<n;i++){
            arr[i]=Integer.parseInt(br.readLine());
            total+=arr[i];
        }
        
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<n;i++){
            sb.append(arr[i]*prize/total).append("\n");
        }
        System.out.println(sb);
    }
}