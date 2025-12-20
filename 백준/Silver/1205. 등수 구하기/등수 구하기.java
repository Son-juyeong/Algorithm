import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int score = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());

        Integer[] arr = new Integer[N];

        if (N > 0)
            st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr, Collections.reverseOrder());

        if (N == P && score <= arr[P - 1]) {
            System.out.println(-1);
        } else {
            int rank = 1;
            for (int i = 0; i < N; i++) {
                if (i != 0) {
                    if (arr[i] < arr[i - 1])
                        rank = i + 1;
                }
                if (score >= arr[i]) {
                    break;
                }
                if (i == N - 1 && arr[i] > score) {
                    rank = N + 1;
                }
            }
            System.out.println(rank);
        }
    }
}