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

        setTreeSize(N);
        arr = new long[N + 1];

        StringBuilder sb = new StringBuilder();

        for (int tc = 0; tc < M; tc++) {
            st = new StringTokenizer(br.readLine());
            int cmd = Integer.parseInt(st.nextToken());
            int first = Integer.parseInt(st.nextToken());
            int second = Integer.parseInt(st.nextToken());
            switch (cmd) {
                case 0:
                    int i = Math.min(first, second);
                    int j = Math.max(first, second);
                    sb.append(sum(1, 1, N, i, j)).append("\n");
                    break;
                case 1:
                    long diff = second - arr[first];
                    arr[first] = second;
                    modifyArr(1, 1, N, first, diff);
                    break;
            }
        }

        System.out.println(sb);
    }

    public static void setTreeSize(int N) {
        int height = (int) Math.ceil(Math.log(N) / Math.log(2));
        tree = new long[(int) Math.pow(2, height + 1)];
    }

    public static void modifyArr(int node, int start, int end, int i, long diff) {
        if (i < start || i > end) return;
        tree[node] += diff;

        if (start != end) {
            modifyArr(node * 2, start, (start + end) / 2, i, diff);
            modifyArr(node * 2 + 1, (start + end) / 2 + 1, end, i, diff);
        }
    }

    public static long sum(int node, int start, int end, int i, int j) {
        if (start > j || end < i) return 0;
        else if (i <= start && end <= j) return tree[node];
        else {
            return sum(node * 2, start, (start + end) / 2, i, j)
                    + sum(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
        }
    }
}
