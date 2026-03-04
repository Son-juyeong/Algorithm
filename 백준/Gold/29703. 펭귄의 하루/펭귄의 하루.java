import java.io.*;
import java.util.*;

class Main {

    static class Node {
        int r;
        int c;
        int value;
        int fish;

        public Node(int r, int c, int value, int fish) {
            this.r = r;
            this.c = c;
            this.value = value;
            this.fish = fish;
        }
    }

    static boolean[][][] visited;
    static char[][] arr;

    static int[] dr = {0, 1, 0, -1};
    static int[] dc = {1, 0, -1, 0};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        visited = new boolean[2][N][M];
        arr = new char[N][M];

        Node s = new Node(-1, -1, 0, 0);

        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            for (int j = 0; j < M; j++) {
                arr[i][j] = str.charAt(j);
                if (arr[i][j] == 'S') {
                    s = new Node(i, j, 0, 0);
                    visited[0][i][j] = true;
                }
            }
        }

        Queue<Node> q = new ArrayDeque<>();
        q.offer(s);

        while (!q.isEmpty()) {
            Node cur = q.poll();
            for (int i = 0; i < 4; i++) {
                int r = cur.r + dr[i];
                int c = cur.c + dc[i];
                int value = cur.value + 1;
                if (r >= 0 && r < N && c >= 0 && c < M && arr[r][c] != 'D' && !visited[cur.fish][r][c]) {
                    visited[cur.fish][r][c] = true;
                    if (arr[r][c] == 'F') {
                        visited[1][r][c] = true;
                        q.offer(new Node(r, c, value, 1));
                        continue;
                    } else if (arr[r][c] == 'H' && cur.fish == 1) {
                        System.out.println(value);
                        return;
                    }
                    q.offer(new Node(r, c, value, cur.fish));
                }
            }
        }

        System.out.println(-1);

    }
}