import java.io.*;
import java.util.*;

public class Main {

    static char[][] arr;
    static int R;
    static int C;
    static int[] dirR = {-1, 0, 1};

    public static int dfs(int r, int c) {
        arr[r][c] = 'X';
        if (c == C - 1)
            return 1;
        int newC = c + 1;
        for (int i = 0; i < 3; i++) {
            int newR = r + dirR[i];
            if (newR >= 0 && newR < R && arr[newR][newC] == '.') {
                int result = dfs(newR, newC);
                if (result == 1) {
                    return result;
                }
            }
        }
        return 0;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        arr = new char[R][C];

        int answer = 0;

        for (int i = 0; i < R; i++) {
            String str = br.readLine();
            for (int j = 0; j < C; j++) {
                arr[i][j] = str.charAt(j);
            }
        }

        for (int i = 0; i < R; i++) {
            answer += dfs(i, 0);
        }

        System.out.println(answer);
    }
}