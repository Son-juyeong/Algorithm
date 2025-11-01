import java.io.*;
import java.util.*;

public class Main {

    static int[] dr = {0, -1, -1, -1, 0, 1, 1, 1};
    static int[] dc = {-1, -1, 0, 1, 1, 1, 0, -1};
    static int n, m;

    static List<int[]> rain(int d, int s, int[][] arr, boolean[][] bool, List<int[]> list) {
        for (int i = 0; i < n; i++) Arrays.fill(bool[i], false);

        List<int[]> result = new ArrayList<>();
        for (int[] cloud : list) {
            int r = (n + cloud[0] + dr[d - 1] * (s % n)) % n;
            int c = (n + cloud[1] + dc[d - 1] * (s % n)) % n;
            arr[r][c]++;
            bool[r][c] = true;
            result.add(new int[]{r, c});
        }
        return result;
    }

    static void copy(int[][] arr, List<int[]> list) {
        for (int[] pos : list) {
            int r = pos[0], c = pos[1];
            int cnt = 0;
            for (int j = 1; j < 8; j += 2) {
                int nr = r + dr[j];
                int nc = c + dc[j];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && arr[nr][nc] > 0)
                    cnt++;
            }
            arr[r][c] += cnt;
        }
    }

    static List<int[]> getArea(int[][] arr, boolean[][] bool) {
        List<int[]> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!bool[i][j] && arr[i][j] >= 2) {
                    result.add(new int[]{i, j});
                    arr[i][j] -= 2;
                }
            }
        }
        return result;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int[][] arr = new int[n][n];
        boolean[][] bool = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        List<int[]> clouds = new ArrayList<>();
        clouds.add(new int[]{n - 1, 0});
        clouds.add(new int[]{n - 1, 1});
        clouds.add(new int[]{n - 2, 0});
        clouds.add(new int[]{n - 2, 1});

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int d = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());

            clouds = rain(d, s, arr, bool, clouds);
            copy(arr, clouds);
            clouds = getArea(arr, bool);
        }

        int answer = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                answer += arr[i][j];

        System.out.println(answer);
    }
}