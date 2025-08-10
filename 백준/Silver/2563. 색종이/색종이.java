import java.io.*;
import java.util.*;

public class Main {

    public static int[][] arr = new int[101][101];
    public static int answer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int c = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            for (int j = r; j < r + 10; j++) {
                for (int k = c; k < c + 10; k++) {
                    arr[j][k]++;
                }
            }
        }
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                if (arr[i][j] > 0)
                    answer++;
            }
        }
        System.out.println(answer);
    }
}