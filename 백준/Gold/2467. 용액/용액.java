import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int start = 0, end = N-1;
        int s = start, e = end;
        int val = Integer.MAX_VALUE;

        while(s<e){
            int temp = arr[s] + arr[e];
            if(Math.abs(temp)<Math.abs(val)){
                val = temp;
                start = s;
                end = e;
                if(temp==0) break;
            }
            if(temp<0){
                ++s;
            }
            else if(temp>0){
                --e;
            }
        }
        System.out.println(arr[start]+" "+arr[end]);
    }
}