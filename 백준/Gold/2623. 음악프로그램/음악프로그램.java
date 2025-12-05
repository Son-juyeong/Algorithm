import java.io.*;
import java.util.*;

public class Main {

    static List<Integer>[] graph;
    static int[] in;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N, M;
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        graph = new ArrayList[N + 1];
        in = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int cnt = Integer.parseInt(st.nextToken());
            if (cnt > 0) {
                int pre = Integer.parseInt(st.nextToken());
                for (int j = 0; j < cnt - 1; j++) {
                    int t = Integer.parseInt(st.nextToken());
                    graph[pre].add(t);
                    ++in[t];
                    pre = t;
                }
            }
        }

        List<Integer> answer = new ArrayList<>();

        Queue<Integer> q = new ArrayDeque<>();
        for (int i = 1; i <= N; i++) {
            if (in[i] == 0) {
                q.offer(i);
                answer.add(i);
            }
        }

        while (!q.isEmpty()) {
            int temp = q.poll();
            for (int i = 0; i < graph[temp].size(); i++) {
                int cur = graph[temp].get(i);
                if (in[cur] != 0 && --in[cur] == 0) {
                    q.offer(cur);
                    answer.add(cur);
                }
            }
        }

        if(answer.size()<N){
            System.out.println(0);
        }else{
            StringBuilder sb = new StringBuilder();
            for(int i = 0;i<N;i++){
                sb.append(answer.get(i)).append("\n");
            }
            System.out.println(sb);
        }
    }
}