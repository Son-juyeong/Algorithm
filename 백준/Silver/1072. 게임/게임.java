import java.io.*;
import java.util.*;

public class Main {

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int X = Integer.parseInt(st.nextToken());
        int Y = Integer.parseInt(st.nextToken());

        if (X == Y) {
            System.out.println(-1);
            return;
        }

        long left = 0L, right = X * 2L;
        long answer = right;

        while (left < right) {
            long m = (left + right) / 2L;
            long z = 100L * Y / X;
            long newZ = 100L * (Y + m) / (X + m);

            if (newZ > z) {
                right = m;
                if (m < answer) {
                    answer = m;
                }
            } else {
                left = m + 1;
            }
        }

        System.out.println(answer == X * 2L ? -1 : answer);
    }
}