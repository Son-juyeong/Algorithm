import java.io.*;
import java.util.*;

public class Main {

    static int[] weights;
    static int INF = 1000000000;
    static int[] pre;
    static List<Node>[] bus;

    static class Node implements Comparable<Node> {
        int v;
        int weight;

        public Node(int v, int weight) {
            this.v = v;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o) {
            return this.weight - o.weight;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        weights = new int[n + 1];
        pre = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            weights[i] = INF;
            pre[i] = i;
        }

        bus = new List[n + 1];
        for (int i = 1; i <= n; i++) {
            bus[i] = new ArrayList<>();
        }

        for (int i = 1; i <= m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            bus[from].add(new Node(to, weight));
        }

        StringTokenizer st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        weights[a] = 0;
        Queue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(a, 0));
        while (!pq.isEmpty()) {
            Node cur = pq.poll();
            if (cur.v == b)
                break;
            if (cur.weight > weights[cur.v])
                continue;
            for (int i = 0; i < bus[cur.v].size(); i++) {
                Node next = bus[cur.v].get(i);
                if (weights[next.v] > cur.weight + next.weight) {
                    weights[next.v] = cur.weight + next.weight;
                    pre[next.v] = cur.v;
                    pq.offer(new Node(next.v, weights[next.v]));
                }
            }
        }
        Stack<Integer> stack = new Stack<>();
        int idx = b;
        int cnt = 1;
        stack.add(idx);
        while (pre[idx] != idx) {
            ++cnt;
            idx = pre[idx];
            stack.add(idx);
        }
        StringBuilder sb = new StringBuilder();
        sb.append(weights[b]).append("\n");
        sb.append(cnt).append("\n");
        while (!stack.isEmpty()) {
            sb.append(stack.pop()).append(" ");
        }

        System.out.println(sb);
    }
}