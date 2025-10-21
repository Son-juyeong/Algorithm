import java.io.*;
import java.util.*;

public class Main {

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		int w = Integer.parseInt(st.nextToken());

		int[][][] dp = new int[t + 1][3][w + 1];
		for (int i = 1; i <= t; i++) {
			int n = Integer.parseInt(br.readLine());
			int o = n == 1 ? 2 : 1;
			for (int j = 0; j <= (i < w ? i : w); j++) {
				if (j == 0) {{
					dp[i][n][j] = dp[i - 1][n][j] + n % 2;
				}
				} else {
					if (j % 2 == n) {
						dp[i][n][j] = 0;
					} else {
						dp[i][n][j] = Math.max(dp[i - 1][n][j] + 1, dp[i - 1][o][j - 1] + 1);
					}
				}
				dp[i][o][j] = dp[i - 1][o][j];
			}
		}

		int answer = 0;

		for (int i = 0; i <= w; i++) {
			answer = Math.max(answer, Math.max(dp[t][1][i], dp[t][2][i]));
		}
		System.out.println(answer);
	}
}