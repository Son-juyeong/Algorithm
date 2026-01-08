import java.io.*;
import java.util.*;

public class Main {

    static class Node implements Comparable<Node> {
        int v1;
        int v2;
        int weight;

        public Node(int v1, int v2, int weight) {
            this.v1 = v1;
            this.v2 = v2;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o) {
            return this.weight - o.weight;
        }
    }

    static int[] parent;
    static int[] level;

    static void init(int N) {
        parent = new int[N + 1];
        level = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }
    }

    static int findParent(int n) {
        if (parent[n] == n)
            return n;
        return parent[n] = findParent(parent[n]);
    }

    static boolean union(int x, int y) {
        int parentX = findParent(x);
        int parentY = findParent(y);
        if (parentX == parentY)
            return false;
        if (level[parentX] < level[parentY]) {
            parent[parentX] = parentY;
        } else {
            parent[parentY] = parentX;
        }
        if (level[parentX] == level[parentY])
            level[parentX]++;
        return true;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        init(N);

        Queue<Node> pq = new PriorityQueue<>();
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());
            pq.offer(new Node(A, B, C));
        }

        int cnt = 0;
        int answer = 0;

        while (!pq.isEmpty()) {
            Node cur = pq.poll();
            if (union(cur.v1, cur.v2)) {
                ++cnt;
                if (cnt == N - 1) break;
                answer += cur.weight;
            }
        }

        System.out.println(answer);
    }
}
