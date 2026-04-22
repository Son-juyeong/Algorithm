import java.io.*;
import java.util.*;

public class Main {

    static long[] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        arr = new long[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }

        int answer = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                answer = 0;
                break;
            }
        }

        System.out.println(answer);
    }
}