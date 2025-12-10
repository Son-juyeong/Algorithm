import java.io.*;
import java.util.*;

public class Main {

    static int[][] palindrome;
    static int[] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        palindrome = new int[n + 1][n + 1];
        arr = new int[n + 1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i <= n; i++) {
            palindrome[i][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i + 1])
                palindrome[i][i + 1] = 1;
        }
        for (int cnt = 3; cnt <= n; cnt++) {
            for (int s = 1; s <= n - cnt + 1; s++) {
                if (arr[s] == arr[s + cnt - 1] && palindrome[s + 1][s + cnt - 2] == 1) {
                    palindrome[s][s + cnt - 1] = 1;
                }
            }
        }

        int m = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            sb.append(palindrome[start][end]).append("\n");
        }

        System.out.println(sb);
    }
}