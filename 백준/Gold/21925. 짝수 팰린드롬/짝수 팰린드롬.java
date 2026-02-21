import java.io.*;
import java.util.*;

public class Main {

    static int[] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        arr = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int answer = 0;

        int start = 0, end = 1;

        while (start < N - 1 && end < N) {
            if (arr[start] == arr[end]) {
                int s = start;
                int e = end;
                boolean isPalindrome = true;
                while (s < e) {
                    if (arr[s] != arr[e]) {
                        isPalindrome = false;
                        break;
                    }
                    ++s;
                    --e;
                }
                if (isPalindrome) {
                    ++answer;
                    start = end + 1;
                    end += 2;
                } else {
                    end += 2;
                    if (end > N) answer = 0;
                }
            } else {
                end += 2;
                if (end > N) answer = 0;
            }
        }

        System.out.println(answer == 0 ? -1 : answer);
    }
}