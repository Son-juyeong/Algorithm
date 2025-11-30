import java.io.*;
import java.util.*;

public class Main {

    static class Edge{
        int v;
        int w;
        int t;
        public Edge(int v, int w, int t){
            this.v = v;
            this.w = w;
            this.t = t;
        }
    }

    static final int INF = 100000000;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int TC = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for(int tc = 1;tc<=TC;tc++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int W = Integer.parseInt(st.nextToken());

            Edge[] graph = new Edge[2 * M + W];
            int idx = 0;
            int[] dist = new int[N + 1];
            Arrays.fill(dist, 0);
            for(int i  = 0;i<M;i++){
                st = new StringTokenizer(br.readLine());
                int s = Integer.parseInt(st.nextToken());
                int e = Integer.parseInt(st.nextToken());
                int t = Integer.parseInt(st.nextToken());

                graph[idx++] = (new Edge(s, e, t));
                graph[idx++] = (new Edge(e, s, t));
            }

            for(int i = 0;i<W;i++){
                st = new StringTokenizer(br.readLine());
                int s = Integer.parseInt(st.nextToken());
                int e = Integer.parseInt(st.nextToken());
                int t = Integer.parseInt(st.nextToken());

                graph[idx++]=(new Edge(s, e, -t));
            }

            for(int i = 0;i<N-1;i++){
                boolean update = false;
                for(int j = 0;j< idx;j++){
                    Edge edge = graph[j];
                    if(dist[edge.w]>dist[edge.v]+edge.t){
                        update = true;
                        dist[edge.w] = dist[edge.v] + edge.t;
                    }
                }
                if(!update) break;
            }
            boolean yes = false;
            for (int i = 0; i < idx; i++) {
                Edge edge = graph[i];
                if(dist[edge.w]>dist[edge.v]+edge.t){
                    yes = true;
                    break;
                }
            }
            if(yes) sb.append("YES\n");
            else sb.append("NO\n");
        }
        System.out.println(sb);
    }
}