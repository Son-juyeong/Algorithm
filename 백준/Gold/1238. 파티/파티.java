import java.io.*;
import java.util.*;

public class Main {

    static class Node implements Comparable<Node> {
        int start;
        int cur;
        int t;

        public Node(int cur, int t) {
            this.cur = cur;
            this.t = t;
        }

        public Node(int start, int cur, int t) {
            this.start = start;
            this.cur = cur;
            this.t = t;
        }

        @Override
        public int compareTo(Node o) {
            return this.t - o.t;
        }
    }

    static int[] time;

    public static void bfs(int n, int x, List<Node>[] graph) {
        int[][] weight = new int[n + 1][n + 1];
        Queue<Node> q = new PriorityQueue<>();
        for (int i = 1; i <= n; i++) {
            q.offer(new Node(i, i, 0));
            Arrays.fill(weight[i], Integer.MAX_VALUE);
            weight[i][i] = 0;
        }

        while (!q.isEmpty()) {
            Node node = q.poll();
            if (weight[node.cur][node.start] < node.t)
                continue;
            for (int i = 0; i < graph[node.cur].size(); i++) {
                Node next = graph[node.cur].get(i);
                int t = node.t + next.t;
                if (weight[next.cur][node.start] > t) {
                    weight[next.cur][node.start] = t;
                    if (next.cur != x) {
                        q.offer(new Node(node.start, next.cur, t));
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            time[i] += weight[x][i];
        }
    }

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());

        List<Node>[] graph1 = new ArrayList[n + 1];
        List<Node>[] graph2 = new ArrayList[n + 1];
        time = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            graph1[i] = new ArrayList<>();
            graph2[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());

            graph1[s].add(new Node(e, t));
            graph2[e].add(new Node(s, t));
        }

        bfs(n, x, graph1);
        bfs(n, x, graph2);

        int answer = 0;
        for (int i = 1; i <= n; i++) {
            answer = Math.max(answer, time[i]);
        }

        System.out.println(answer);
    }
}