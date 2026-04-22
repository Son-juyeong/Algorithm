import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n+1];
        for(int i=1;i<=n;i++){
            int m = Integer.parseInt(br.readLine());
            arr[m]=i;
        }
        int count = 0;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i+1])
                count++;
        }
        System.out.println(count);
    }
}