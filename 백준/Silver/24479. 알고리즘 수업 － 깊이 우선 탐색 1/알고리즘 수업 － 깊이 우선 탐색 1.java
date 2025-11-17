import java.io.*;
import java.util.*;

public class Main {

    static List<Integer>[] graph;

    static int[] answer;
    static boolean[] visited;
    static int order = 1;

    public static void dfs(int n){
        visited[n]=true;
        answer[n] = order++;
        for(int i = 0;i<graph[n].size();i++){
            int t = graph[n].get(i);
            if(!visited[t]){
                dfs(t);
            }
        }
    }

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());

        graph = new ArrayList[N + 1];
        for(int i = 1;i<=N;i++){
            graph[i] = new ArrayList<>();
        }

        visited = new boolean[N + 1];
        answer = new int[N + 1];

        for(int i = 0;i<M;i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            graph[u].add(v);
            graph[v].add(u);
        }

        for(int i = 1;i<=N;i++){
            Collections.sort(graph[i]);
        }

        dfs(R);

        StringBuilder sb = new StringBuilder();
        for(int i =1;i<=N;i++){
            sb.append(answer[i]).append("\n");
        }
        System.out.println(sb);
    }
}