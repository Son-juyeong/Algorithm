import java.io.*;
import java.util.*;

public class Main {

    static int[] lis;

    public static int binarySearch(int left, int right, int target) {
        while (left < right) {
            int mid = (left + right) / 2;
            if (lis[mid] < target) {
                left = mid + 1;
            } else if (lis[mid] > target) {
                right = mid;
            } else {
                return mid;
            }
        }
        return right;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        lis = new int[n + 1];
        lis[0] = Integer.MIN_VALUE;
        int[] arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            lis[i + 1] = Integer.MIN_VALUE;
        }

        int len = 0;
        for (int i = 0; i < n; i++) {
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