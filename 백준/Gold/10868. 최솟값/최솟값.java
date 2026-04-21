import java.io.*;
import java.util.*;

public class Main {

    static int[] tree;
    static int[] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        setTreeSize(N);
        arr = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        init(1, 1, N);

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            sb.append(getMinNum(1, 1, N, a, b)).append("\n");
        }

        System.out.println(sb);
    }

    public static void setTreeSize(int N) {
        int height = (int) Math.ceil(Math.log(N) / Math.log(2)) + 1;
        tree = new int[(int) Math.pow(2, height)];
        Arrays.fill(tree, Integer.MAX_VALUE);
    }

    public static int init(int node, int start, int end) {
        if (start == end)
            return tree[node] = arr[start];
        int mid = (start + end) / 2;
        int lNode = node * 2;
        int rNode = lNode + 1;
        return tree[node] = Math.min(init(lNode, start, mid), init(rNode, mid + 1, end));
    }

    public static void update(int node, int start, int end, int idx, int value) {
        if (idx < start || idx > end) return;
        tree[node] = Math.min(tree[node], value);
        int mid = (start + end) / 2;
        int lNode = node * 2;
        int rNode = lNode + 1;
        if (start != end) {
            update(lNode, start, mid, idx, value);
            update(rNode, mid + 1, end, idx, value);
        }
    }

    public static int getMinNum(int node, int start, int end, int left, int right) {
        if (left > end || right < start) return Integer.MAX_VALUE;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        int lNode = node * 2;
        int rNode = lNode + 1;
        return Math.min(getMinNum(lNode, start, mid, left, right), getMinNum(rNode, mid + 1, end, left, right));
    }
}
