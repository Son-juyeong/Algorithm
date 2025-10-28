import java.io.*;
import java.util.*;

public class Main {

    static int n;
    static int[][] arr;
    static boolean[] select;
    static int answer = Integer.MAX_VALUE;

    public static void selectTeam(int start, int idx) {
        if (idx == n / 2) {
            answer = Math.min(answer, getAnswer());
        }
        for (int i = start; i < n; i++) {
            select[i] = true;
            selectTeam(i + 1, idx + 1);
            select[i] = false;
        }
    }

    public static int getAnswer() {
        int team1 = calculate(new int[2], 0, 0, true);
        int team2 = calculate(new int[2], 0, 0, false);
        return Math.abs(team1 - team2);
    }

    public static int calculate(int[] selected, int start, int idx, boolean b) {
        if (idx == 2) {
            return arr[selected[0]][selected[1]] + arr[selected[1]][selected[0]];
        }
        int result = 0;
        for (int i = start; i < n; i++) {
            if (select[i] == b) {
                selected[idx] = i;
                result += calculate(selected, i + 1, idx + 1, b);
            }
        }
        return result;
    }

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        arr = new int[n][n];
        select = new boolean[n];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        selectTeam(0,0);

        System.out.println(answer);
    }
}