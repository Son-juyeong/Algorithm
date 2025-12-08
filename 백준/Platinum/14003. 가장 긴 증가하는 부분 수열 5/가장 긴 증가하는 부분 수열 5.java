import java.io.*;
import java.util.*;

public class Main {

    static int[] lis;

    public static int binarySearch(int left, int right, int target) {
        while (left < right) {
            int mid = (left + right) / 2;
            int temp = lis[mid];
            if (temp < target) {
                left = mid + 1;
            } else if (temp == target) {
                return mid;
            } else {
                right = mid;
            }
        }
        return right;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        lis = new int[n + 1];
        int[] arr = new int[n];
        int[] record = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            lis[i] = Integer.MIN_VALUE;
        }
        lis[n] = Integer.MIN_VALUE;

        int len = 0;

        for (int i = 0; i < n; i++) {
            int target = arr[i];
            if (lis[len] < target) {
                lis[++len] = target;
                record[i] = len;
            } else {
                int idx = binarySearch(0, len, target);
                lis[idx] = target;
                record[i] = idx;
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(len).append("\n");
        int[] answer = new int[len + 1];
        int idx = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (record[i] == len) {
                answer[idx++] = arr[i];
                --len;
            }
        }
        for (int i = answer.length - 1; i > 0; i--) {
            sb.append(answer[i]).append(" ");
        }
        System.out.println(sb);
    }
}