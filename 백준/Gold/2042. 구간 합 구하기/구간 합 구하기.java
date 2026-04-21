import java.io.*;
import java.util.*;

public class Main {

    static long[] tree;
    static long[] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        arr = new long[N + 1];

        for (int i = 1; i <= N; i++) {
            arr[i] = Long.parseLong(br.readLine());
        }
        setTreeSize(N);
        init(1, 1, N);

        StringBuilder sb = new StringBuilder();

        int cnt = M + K;
        for (int i = 0; i < cnt; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            long c = Long.parseLong(st.nextToken());

            switch (a) {
                case 1:
                    long diff = c - arr[b];
                    arr[b] = c;
                    update(1, 1, N, b, diff);
                    break;
                case 2:
                    sb.append(sum(1, 1, N, b, c)).append("\n");
                    break;
            }
        }
        System.out.println(sb);
    }

    public static void setTreeSize(int N) {
        int height = (int) (Math.ceil(Math.log(N) / Math.log(2))) + 1;
        tree = new long[(int) Math.pow(2, height)];
    }

    public static long init(int node, int start, int end) {
        if (start == end) {
            return tree[node] = arr[start];
        }
        int mid = (start + end) / 2;
        return tree[node] = init(node * 2, start, mid)
                + init(node * 2 + 1, mid + 1, end);
    }

    public static void update(int node, int start, int end, int idx, long diff) {
        if (idx < start || end < idx) return;
        tree[node] += diff;
        int mid = (start + end) / 2;
        if (start != end) {
            update(node * 2, start, mid, idx, diff);
            update(node * 2 + 1, mid + 1, end, idx, diff);
        }
    }

    public static long sum(int node, int start, int end, int left, long right) {
        if (start > right || end < left) return 0;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
    }
}
