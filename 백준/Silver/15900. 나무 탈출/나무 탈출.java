import java.io.*;
import java.util.*;

public class Main {
    static List<Integer>[] tree;
    static boolean[] visited;
    static int totalDepth = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        tree = new ArrayList[n + 1];
        visited = new boolean[n + 1];

        for (int i = 1; i <= n; i++) {
            tree[i] = new ArrayList<>();
        }

        for (int i = 0; i < n - 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            tree[u].add(v);
            tree[v].add(u);
        }

        dfs(1, 0);

        if (totalDepth % 2 == 1)
            System.out.println("Yes");
        else
            System.out.println("No");
    }

    static void dfs(int node, int depth) {
        visited[node] = true;
        boolean isLeaf = true;

        for (int next : tree[node]) {
            if (!visited[next]) {
                isLeaf = false;
                dfs(next, depth + 1);
            }
        }

        if (isLeaf) {
            totalDepth += depth;
        }
    }
}