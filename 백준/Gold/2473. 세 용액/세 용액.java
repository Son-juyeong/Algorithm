import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long[] arr = new long[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }

        Arrays.sort(arr);

        long best = Long.MAX_VALUE;
        long[] answer = new long[3];

        for (int i = 0; i < N - 2; i++) {
            int left = i + 1, right = N - 1;
            while (left < right) {
                long temp = arr[i] + arr[left] + arr[right];
                if (Math.abs(temp) < Math.abs(best)) {
                    best = temp;
                    answer[0] = arr[i];
                    answer[1] = arr[left];
                    answer[2] = arr[right];
                }
                if (best == 0) break;
                if (temp < 0) ++left;
                else if (temp > 0) --right;
            }
            if (best == 0) break;
        }

        for (int i = 0; i < 3; i++) {
            System.out.print(answer[i] + " ");
        }
    }
}