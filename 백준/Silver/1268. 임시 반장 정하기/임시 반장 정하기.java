import java.io.*;
import java.util.*;

public class Main {

    static int[][] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        arr = new int[n + 1][6];

        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= 5; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int answer = 1;
        int max = 0;

        for (int student = 1; student <= n; student++) {
            int cnt = 0;
            boolean[] visited = new boolean[n + 1];
            visited[student] = true;
            for (int grade = 1; grade <= 5; grade++) {
                int temp = arr[student][grade];
                for (int i = 1; i <= n; i++) {
                    if (arr[i][grade] == temp && !visited[i]) {
                        visited[i] = true;
                        ++cnt;
                    }
                }
            }
            if (max < cnt) {
                max = cnt;
                answer = student;
            }
        }
        System.out.println(answer);
    }
}