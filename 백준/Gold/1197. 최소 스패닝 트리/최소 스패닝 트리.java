import java.io.*;
import java.util.*;

public class Main {

    static class Graph implements Comparable<Graph> {
        int vertex;
        int next;
        int weight;

        public Graph(int vertex, int next, int weight) {
            this.vertex = vertex;
            this.next = next;
            this.weight = weight;
        }

        @Override
        public int compareTo(Graph o) {
            return this.weight-o.weight;
        }
    }

    static int[] parent;
    static int[] level;

    public static void init(int n) {
        parent = new int[n + 1];
        level = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            level[i] = 1;
        }
    }

    public static int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    public static void union(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            if (level[px] > level[py]) {
                parent[py] = px;
            } else {
                parent[px] = py;
                if (level[px] == level[py])
                    level[py]++;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());

        init(v);

        Queue<Graph> pq = new PriorityQueue<>();

        for(int i = 0;i<e;i++){
            st = new StringTokenizer(br.readLine());
            int vertex = Integer.parseInt(st.nextToken());
            int next = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            pq.offer(new Graph(vertex, next, weight));
        }

        int cnt = 0;
        int answer = 0;

        while(!pq.isEmpty()){
            Graph cur = pq.poll();
            if(find(cur.vertex)==find(cur.next))
                continue;
            union(cur.vertex, cur.next);
            ++cnt;
            answer+=cur.weight;
            if(cnt==v-1)break;
        }

        System.out.println(answer);
    }
}