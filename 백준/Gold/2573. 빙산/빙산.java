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
                if (arr[i][j] != 0) {
                    ++cnt;
                }
            }
        }

        int answer = 0;
        while (cnt > 0) {
            boolean[][] visited = new boolean[n][m];
            Queue<int[]> q = new ArrayDeque<>();
            for (int row = 0; row < n; row++) {
                for (int col = 0; col < m; col++) {
                    if (!visited[row][col] && arr[row][col] == 0) {
                        q.offer(new int[]{row, col});
                        visited[row][col] = true;
                        while (!q.isEmpty()) {
                            int[] cur = q.poll();
                            for (int i = 0; i < 4; i++) {
                                int r = cur[0] + dr[i];
                                int c = cur[1] + dc[i];
                                if (r >= 0 && r < n && c >= 0 && c < m && !visited[r][c]) {
                                    if (arr[r][c] == 0) {
                                        visited[r][c] = true;
                                        q.offer(new int[]{r, c});
                                    } else {
                                        --arr[r][c];
                                        if (arr[r][c] == 0) {
                                            --cnt;
                                            visited[r][c] = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            ++answer;
            if (cnt == 0) break;
            int temp = 0;
            visited = new boolean[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (arr[i][j] != 0 && !visited[i][j]) {
                        ++temp;
                        q.offer(new int[]{i, j});
                        visited[i][j] = true;
                        while (!q.isEmpty()) {
                            int[] cur = q.poll();
                            for (int k = 0; k < 4; k++) {
                                int r = cur[0] + dr[k];
                                int c = cur[1] + dc[k];
                                if (r >= 0 && r < n && c >= 0 && c < m && !visited[r][c] && arr[r][c] != 0) {
                                    visited[r][c] = true;
                                    q.offer(new int[]{r, c});
                                }
                            }
                        }
                    }
                }
            }
            if (temp > 1) {
                System.out.println(answer);
                return;
            }
        }
        System.out.println(0);
    }
}