import java.io.*;
import java.util.*;

public class Main {

    static int[] tree;
    static long[] prefixSum;

    public static int binarySearch(int x, int n) {
        int left = 0, right = n + 1;
        while (left < right) {
            int middle = (left + right) / 2;
            if (tree[middle] < x) {
                left = middle + 1;
            } else if (tree[middle] > x) {
                right = middle;
            } else return middle;
        }
        return right;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());

        tree = new int[n + 1];
        prefixSum = new long[n + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            int p = Integer.parseInt(st.nextToken());
            tree[i] = p;

        }

        Arrays.sort(tree);

        for (int i = 1; i <= n; i++) {
            int p = tree[i];
            prefixSum[i] = prefixSum[i - 1] + p;
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < q; i++) {
            int x = Integer.parseInt(br.readLine());
            int idx = binarySearch(x, n);
            long answer = Math.abs(prefixSum[idx - 1] - ((long) x * (idx - 1)));
            answer += Math.abs((long) x * (n - idx + 1) - (prefixSum[n] - prefixSum[idx - 1]));
            sb.append(answer).append("\n");
        }
        System.out.println(sb);
    }
}
