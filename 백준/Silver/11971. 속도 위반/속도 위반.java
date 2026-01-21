import java.io.*;
import java.util.*;

public class Main {

    static int[] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] arr = new int[101];
        int end = 1;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int length = Integer.parseInt(st.nextToken());
            int speed = Integer.parseInt(st.nextToken());
            for (int j = end; j < end + length; j++) {
                arr[j] = speed;
            }
            end += length;
        }
        end = 1;
        int answer = 0;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int length = Integer.parseInt(st.nextToken());
            int speed = Integer.parseInt(st.nextToken());
            for (int j = end; j < end + length; j++) {
                if (arr[j] < speed) {
                    answer = Math.max(answer, speed - arr[j]);
                }
            }
            end += length;
        }

        System.out.println(answer);
    }
}
