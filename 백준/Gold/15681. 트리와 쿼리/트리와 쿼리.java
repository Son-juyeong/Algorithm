import java.io.*;
import java.util.*;

public class Main {

    static int N, R, Q;
    static int[] cnt;
    static List<Integer>[] graph;
    static boolean[] visited;

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        cnt = new int[N + 1];
        graph = new ArrayList[N + 1];
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<>();
        }
        visited = new boolean[N + 1];

        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int n1 = Integer.parseInt(st.nextToken());
            int n2 = Integer.parseInt(st.nextToken());

            graph[n1].add(n2);
            graph[n2].add(n1);
        }

        cnt[R] = dfs(R);

        for (int i = 0; i < Q; i++) {
            int t = Integer.parseInt(br.readLine());
            System.out.println(cnt[t]);
        }
    }

    public static int dfs(int n) {
        visited[n] = true;
        int result = 1;
        for (int i = 0; i < graph[n].size(); i++) {
            int t = graph[n].get(i);
            if (!visited[t]) {
                result += dfs(t);
            }
        }
        cnt[n] = result;
        return result;
    }
}