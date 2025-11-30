import java.io.*;
import java.util.*;

public class Main {

    static class Edge {
        int a;
        int b;
        long c;

        public Edge(int a, int b, long c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }

    static final long INF = 30000000001L;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        long[] dist = new long[N + 1];
        Arrays.fill(dist, INF);
        dist[1] = 0;

        Edge[] graph = new Edge[M];

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a, b, c;
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            graph[i] = new Edge(a, b, c);
        }

        for (int i = 0; i < N - 1; i++) {
            boolean update = false;
            for (int j = 0; j < M; j++) {
                Edge edge = graph[j];
                if (dist[edge.a] != INF && dist[edge.b] > dist[edge.a] + edge.c) {
                    update = true;
                    dist[edge.b] = dist[edge.a] + edge.c;
                }
            }
            if (!update) break;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= N; i++) {
            if (dist[i] == INF) {
                sb.append("-1\n");
            }
            else if(i!=1)
                sb.append(dist[i]).append("\n");
        }
        for (int i = 0; i < M; i++) {
            Edge edge = graph[i];
            if (dist[edge.a] != INF && dist[edge.b] > dist[edge.a] + edge.c) {
                System.out.println(-1);
                return;
            }
        }
        System.out.println(sb);
    }
}