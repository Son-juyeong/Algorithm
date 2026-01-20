import java.io.*;
import java.util.*;

public class Main {

    static int[] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        arr = new int[N];

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int left = 0;
        int answer = 0;
        for (int i = 1; i < N; i++) {
            int n1 = arr[left];
            int n2 = arr[i];
            if (n1 > n2) {
                left = i;
            } else if (n1 < n2) {
                answer = Math.max(answer, n2 - n1);
            }
        }
        System.out.println(answer);
    }
}
