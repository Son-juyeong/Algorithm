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

            List<Edge> graph = new ArrayList<>();
            int[] dist = new int[N + 1];
            Arrays.fill(dist, INF);
            for(int i  = 0;i<M;i++){
                st = new StringTokenizer(br.readLine());
                int s = Integer.parseInt(st.nextToken());
                int e = Integer.parseInt(st.nextToken());
                int t = Integer.parseInt(st.nextToken());

                graph.add(new Edge(s, e, t));
                graph.add(new Edge(e, s, t));
            }

            for(int i = 0;i<W;i++){
                st = new StringTokenizer(br.readLine());
                int s = Integer.parseInt(st.nextToken());
                int e = Integer.parseInt(st.nextToken());
                int t = Integer.parseInt(st.nextToken());

                graph.add(new Edge(s, e, -t));
            }

            for(int i = 0;i<N-1;i++){
                for(int j = 0;j< graph.size();j++){
                    Edge edge = graph.get(j);
                    if(dist[edge.w]>dist[edge.v]+edge.t){
                        dist[edge.w] = dist[edge.v] + edge.t;
                    }
                }
            }
            boolean yes = false;
            for (int i = 0; i < graph.size(); i++) {
                Edge edge = graph.get(i);
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