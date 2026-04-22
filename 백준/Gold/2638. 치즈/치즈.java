import java.io.*;
import java.util.*;

public class Main {

    static int[] dr = new int[]{-1, 1, 0, 0};
    static int[] dc = new int[]{0, 0, -1, 1};

    static int[][] arr;

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
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        arr = new int[n][m];

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == 1) {
                    arr[i][j] = 2;
                    ++cnt;
                }
            }
        }

        int answer = 0;

        while (cnt > 0) {
            ++answer;
            Queue<Node> q = new ArrayDeque<>();
            q.offer(new Node(0, 0));
            boolean[][] visited = new boolean[n][m];
            int[][] temp = new int[n][m];
            for (int i = 0; i < n; i++) {
                temp[i] = Arrays.copyOf(arr[i], arr[i].length);
            }
            visited[0][0] = true;
            while (!q.isEmpty()) {
                Node cur = q.poll();
                for (int i = 0; i < 4; i++) {
                    int r = cur.r + dr[i];
                    int c = cur.c + dc[i];
                    if (r >= 0 && r < n && c >= 0 && c < m && !visited[r][c]) {
                        if (temp[r][c] > 0) {
                            --temp[r][c];
                            if (temp[r][c] == 0) {
                                arr[r][c] = 0;
                                visited[r][c] = true;
                                --cnt;
                            }
                        } else if (temp[r][c] == 0) {
                            visited[r][c] = true;
                            q.offer(new Node(r, c));
                        }
                    }
                }
            }
        }

        System.out.println(answer);

    }
}