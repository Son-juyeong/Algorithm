import java.io.*;
import java.util.*;

class Main {

    static int[][] arr;
    static int[] dr = {0, 1, 0, -1};
    static int[] dc = {1, 0, -1, 0};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(st.nextToken());

        arr = new int[r][c];

        int u = -1, d = -1;

        for (int i = 0; i < r; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < c; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == -1 && u == -1) {
                    u = i;
                    d = i + 1;
                }
            }
        }

        for (int time = 0; time < t; time++) {
            int[][] temp = new int[r][c];
            for (int i = 0; i < r; i++) {
                temp[i] = Arrays.copyOf(arr[i], c);
            }
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (arr[i][j] > 0) {
                        int dust = arr[i][j] / 5;
                        for (int k = 0; k < 4; k++) {
                            int row = i + dr[k];
                            int col = j + dc[k];
                            if (row >= 0 && row < r && col >= 0 && col < c && arr[row][col] != -1) {
                                temp[row][col] += dust;
                                temp[i][j] -= dust;
                            }
                        }
                    }
                }
            }
            int tr = u - 1, tc = 0;
            while (tr > 0) {
                temp[tr][tc] = temp[tr - 1][tc];
                --tr;
            }
            while (tc < c - 1) {
                temp[tr][tc] = temp[tr][tc + 1];
                ++tc;
            }
            while (tr < u) {
                temp[tr][tc] = temp[tr + 1][tc];
                ++tr;
            }
            while (tc > 0) {
                temp[tr][tc] = Math.max(0, temp[tr][tc - 1]);
                --tc;
            }
            tr = d + 1;
            while (tr < r - 1) {
                temp[tr][tc] = temp[tr + 1][tc];
                ++tr;
            }

            while (tc < c - 1) {
                temp[tr][tc] = temp[tr][tc + 1];
                ++tc;
            }

            while (tr > d) {
                temp[tr][tc] = temp[tr - 1][tc];
                --tr;
            }

            while (tc > 0) {
                temp[tr][tc] = Math.max(0, temp[tr][tc - 1]);
                --tc;
            }

            arr = temp;
        }

        int answer = 2;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                answer += arr[i][j];
            }
        }

        System.out.println(answer);
    }
}