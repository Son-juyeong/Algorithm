import java.io.*;
import java.util.*;

public class Main {

    static char[][] arr;
    static boolean[][] visited;
    static int[] dr = {0, 1, 0, -1};
    static int[] dc = {1, 0, -1, 0};

    static class Node {
        int r;
        int c;

        public Node(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= T; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int H = Integer.parseInt(st.nextToken());
            int W = Integer.parseInt(st.nextToken());

            arr = new char[H][W];
            visited = new boolean[H][W];

            for (int i = 0; i < H; i++) {
                String str = br.readLine();
                for (int j = 0; j < W; j++) {
                    arr[i][j] = str.charAt(j);
                }
            }

            int answer = 0;

            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (!visited[i][j] && arr[i][j] == '#') {
                        ++answer;
                        Queue<Node> q = new ArrayDeque<>();
                        q.offer(new Node(i, j));
                        visited[i][j] = true;
                        while (!q.isEmpty()) {
                            Node cur = q.poll();
                            for (int k = 0; k < 4; k++) {
                                int r = cur.r + dr[k];
                                int c = cur.c + dc[k];
                                if (r >= 0 && r < H && c >= 0 && c < W && arr[r][c] == '#' && !visited[r][c]) {
                                    visited[r][c] = true;
                                    q.offer(new Node(r, c));
                                }
                            }
                        }
                    }
                }
            }

            sb.append(answer).append("\n");
        }
        System.out.println(sb);
    }
}
