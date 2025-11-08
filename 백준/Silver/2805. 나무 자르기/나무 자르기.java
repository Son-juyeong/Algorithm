import java.io.*;
import java.util.*;

public class Main {

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] arr = new int[N];

        int right = 0;
        int left = 0;

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            if (arr[i] > right)
                right = arr[i];
        }

        right *= 2;

        int answer = 0;

        while (left < right) {
            int m = (left + right) / 2;
            long temp = 0;
            for (int i = 0; i < N; i++) {
                temp += Math.max(0, arr[i] - m);
            }
            if (temp >= M) {
                left = m + 1;
                answer = Math.max(answer, m);
            } else {
                right = m;
            }
        }

        System.out.println(answer);
    }
}