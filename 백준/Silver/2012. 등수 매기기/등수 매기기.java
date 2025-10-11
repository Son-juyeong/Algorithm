import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[] arr = new long[n + 1];

        for(int i = 1;i<=n;i++){
            arr[i]=Long.parseLong(br.readLine());
        }

        Arrays.sort(arr);

        long answer = 0;
        for(int i = 1;i<=n;i++){
            answer += Math.abs(arr[i] - i);
        }
        System.out.println(answer);
    }
}