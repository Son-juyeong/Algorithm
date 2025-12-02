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
            for (int j = i + 2; j < N; j++) {
                int left = i, right = j;
                while (left < right) {
                    int middle = (left + right) / 2;
                    if (middle == i || middle == j) break;
                    long temp = arr[i] + arr[middle] + arr[j];
                    if (Math.abs(temp) < Math.abs(best)) {
                        best = temp;
                        answer[0] = arr[i];
                        answer[1] = arr[middle];
                        answer[2] = arr[j];
                    }
                    if (temp < 0) left = middle + 1;
                    else if (temp > 0) right = middle;
                    else break;
                }
                if (best == 0) break;
            }
            if (best == 0) break;
        }
        for (int i = 0; i < 3; i++) {
            System.out.print(answer[i] + " ");
        }
    }
}