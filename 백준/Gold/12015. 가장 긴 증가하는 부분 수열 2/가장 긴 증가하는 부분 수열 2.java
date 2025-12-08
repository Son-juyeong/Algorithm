import java.io.*;
import java.util.*;

public class Main {

    static int[] lis;

    public static int binarySearch(int left, int right, int target) {
        while (left < right) {
            int mid = (left + right) / 2;
            if (lis[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return right;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        lis = new int[N + 1];
        int[] arr = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int len = 0;

        for (int i = 0; i < N; i++) {
            int num = arr[i];
            if (lis[len] < num) {
                lis[++len] = num;
            } else {
                int idx = binarySearch(0, len, num);
                lis[idx] = num;
            }
        }

        System.out.println(len);
    }
}