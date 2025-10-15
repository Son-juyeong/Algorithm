import java.io.*;
import java.util.*;

public class Main {

    static int[] dr = {0, 1, 0, -1};
    static int[] dc = {1, 0, -1, 0};
    static int n, m;
    static int[][] arr;
    static long[][] memo;
    static boolean[][] visited;

    public static long dfs(int r, int c) {
        if (r == n - 1 && c == m - 1) {
            return 1;
        }
        long result = 0;
        int num = arr[r][c];
        for (int i = 0; i < 4; i++) {
            int nextR = r + dr[i];
            int nextC = c + dc[i];
            if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m && num > arr[nextR][nextC] && !visited[nextR][nextC]) {
                visited[nextR][nextC] = true;
                if (memo[nextR][nextC] == -1) {
                    result += dfs(nextR, nextC);
                } else if (memo[nextR][nextC] > 0) result += memo[nextR][nextC];
                visited[nextR][nextC] = false;
            }
        }
        memo[r][c] = result;
        return result;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        arr = new int[n][m];
        memo = new long[n][m];
        for (int i = 0; i < n; i++) {
            Arrays.fill(memo[i], -1);
        }
        visited = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        System.out.println(dfs(0, 0));
    }
}