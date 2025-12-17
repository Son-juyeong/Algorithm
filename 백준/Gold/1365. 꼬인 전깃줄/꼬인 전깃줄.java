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
            } else if (temp > target) {
                right = mid;
            } else {
                return mid;
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
            int target = arr[i];
            if (lis[len] < target) {
                lis[++len] = target;
            } else {
                int idx = binarySearch(0, len, target);
                lis[idx] = target;
            }
        }

        System.out.println(N - len);
    }
}