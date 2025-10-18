import java.io.*;
import java.util.*;

public class Main {

    //노드
    static class Node implements Comparable<Node>{
        int v;
        int w;
        int state;

        public Node(int v, int w, int state) {
            this.v = v;
            this.w = w;
            this.state=state;
        }

        @Override
        public int compareTo(Node o) {
            return this.w-o.w;
        }
    }

    //간선 개수
    static int N, E;

    //인접리스트
    static List<Node>[] graph;

    public static int bfs(int v1, int v2){
        int[][] weights = new int[N+1][4];
        for(int i = 1;i<N+1;i++){
            Arrays.fill(weights[i], Integer.MAX_VALUE);
        }
        Queue<Node> pq = new PriorityQueue<Node>();

        int result = -1;

        if(v1==1){
            weights[1][1]=0;
            pq.offer(new Node(1, 0, 1));
        }
        else{
            weights[1][0]=0;
            pq.offer(new Node(1, 0, 0));
        }
        while(!pq.isEmpty()){
            Node cur = pq.poll();
            for(int i = 0;i<graph[cur.v].size();i++){
                Node next = graph[cur.v].get(i);
                int state = cur.state;
                if(next.v==v1){
                    state|=1;
                }
                else if(next.v==v2)
                    state|=2;
                if(cur.w+next.w<weights[next.v][state]){
                    if(state==3&&next.v==N)
                        if(result==-1) result=next.w+cur.w;
                        else result = Math.min(result, next.w+cur.w);
                    weights[next.v][state]=next.w+cur.w;
                    pq.offer(new Node(next.v, next.w+cur.w, state));
                }
            }
        }
        return result;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        graph = new ArrayList[N+1];

        for(int i = 1;i<=N;i++){
            graph[i] = new ArrayList<>();
        }

        for(int i = 0;i<E;i++){
            st = new StringTokenizer(br.readLine());
            int v1 = Integer.parseInt(st.nextToken());
            int v2 = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            graph[v1].add(new Node(v2, w, 0));
            graph[v2].add(new Node(v1, w, 0));
        }

        st = new StringTokenizer(br.readLine());

        int v1 = Integer.parseInt(st.nextToken());
        int v2 = Integer.parseInt(st.nextToken());

        System.out.println(bfs(v1, v2));
    }
}