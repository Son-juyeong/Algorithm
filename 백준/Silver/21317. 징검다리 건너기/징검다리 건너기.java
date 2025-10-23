import java.io.*;
import java.util.*;

public class Main {

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		// dp 배열
		int[][] dp = new int[N + 1][2];
		// 작은 점프
		int[] s = new int[N];
		// 큰 점프
		int[] b = new int[N];

		for (int i = 1; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			s[i] = Integer.parseInt(st.nextToken());
			b[i] = Integer.parseInt(st.nextToken());
		}

		int K = Integer.parseInt(br.readLine());

		dp[1][0] = 0;
		dp[1][1] = 100001;
		for (int i = 2; i <= N; i++) {
			if (i == 2) {
				dp[i][0] = dp[i - 1][0] + s[i - 1];
				dp[i][1] = 100001;
			} else if (i == 3) {
				dp[i][0] = Math.min(dp[i - 1][0] + s[i - 1], dp[i - 2][0] + b[i - 2]);
				dp[i][1] = 100001;
			} else {
				dp[i][0] = Math.min(dp[i - 1][0] + s[i - 1], dp[i - 2][0] + b[i - 2]);
				dp[i][1] = Math.min(Math.min(dp[i - 1][1] + s[i - 1], dp[i - 2][1] + b[i - 2]), dp[i - 3][0] + K);
			}
		}
		
		int answer = Math.min(dp[N][0], dp[N][1]);
		System.out.println(answer);
	}
}