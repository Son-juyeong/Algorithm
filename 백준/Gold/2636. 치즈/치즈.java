import java.io.*;
import java.util.*;

public class Main {

    static int[] dr = {0, 1, 0, -1};
    static int[] dc = {1, 0, -1, 0};

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int cnt = 0;

        int[][] arr = new int[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == 1) {
                    ++cnt;
                }
            }
        }

        int sec = 0;
        int remain = 0;

        while (cnt > 0) {
            remain = cnt;
            boolean[][] visited = new boolean[n][m];
            visited[0][0] = true;
            Queue<int[]> q = new ArrayDeque<>();
            q.offer(new int[]{0, 0});
            while (!q.isEmpty()) {
                int[] cur = q.poll();
                for (int i = 0; i < 4; i++) {
                    int r = cur[0] + dr[i];
                    int c = cur[1] + dc[i];
                    if (r >= 0 && r < n && c >= 0 && c < m && !visited[r][c]) {
                        visited[r][c] = true;
                        if (arr[r][c] == 0) {
                            q.offer(new int[]{r, c});
                        } else {
                            arr[r][c] = 0;
                            if (--cnt == 0) break;
                        }
                    }
                }
                if (cnt == 0) break;
            }
            ++sec;
        }
        System.out.println(sec);
        System.out.println(remain);
    }
}