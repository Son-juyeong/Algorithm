import java.io.*;
import java.util.*;

public class Main {

    static class Node {
        int w;
        int child;

        public Node(int w, int child) {
            this.w = w;
            this.child = child;
        }
    }

    static List<Node>[] tree;

    static int answer;

    static int dfs(int v, int w) {
        if (tree[v].isEmpty()) {
            return w;
        }
        int result = 0;
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < tree[v].size(); i++) {
            Node cur = tree[v].get(i);
            int temp = dfs(cur.child, w + cur.w);
            result = Math.max(result, temp);
            list.add(temp);
        }

        Collections.sort(list);

        if (list.size() == 1)
            answer = Math.max(answer, list.get(0)-w);
        else
            answer = Math.max(answer, list.get(list.size() - 1) + list.get(list.size() - 2)-w-w);

        return result;
    }

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        tree = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            tree[i] = new ArrayList<Node>();
        }

        for (int i = 0; i < n - 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            tree[p].add(new Node(w, c));
        }

        dfs(1, 0);

        System.out.println(answer);
    }
}