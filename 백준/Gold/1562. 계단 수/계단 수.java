import java.io.*;
import java.util.*;

public class Main {

    static final long mod = 1000000000L;
    static long[][][] dp;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        dp = new long[N + 1][10][(1 << 10)];
        for (int i = 1; i < 10; i++) {
            dp[1][i][1 << i] = 1;
        }

        for (int i = 2; i <= N; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < (1 << 10); k++) {
                    if (j == 0) {
                        dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k];
                        dp[i][j][k | (1 << j)] %= mod;
                    } else if (j == 9) {
                        dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k];
                        dp[i][j][k | (1 << j)] %= mod;
                    } else {
                        dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k] + dp[i - 1][j - 1][k];
                        dp[i][j][k | (1 << j)] %= mod;
                    }
                }
            }
        }
        long answer = 0L;
        for (int i = 0; i < 10; i++) {
            answer += dp[N][i][(1 << 10) - 1];
            answer %= mod;
        }

        System.out.println(answer);
    }
}