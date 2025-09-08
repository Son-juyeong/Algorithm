import java.io.*;
import java.util.*;

public class Main {

	static char[][] arr;

	// 0: 가로 1: 세로 2: 대각선
	static int[][][] dp;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		arr = new char[N + 1][N + 1];
		dp = new int[N + 1][N + 1][3];

		for (int i = 1; i <= N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= N; j++) {
				arr[i][j] = st.nextToken().charAt(0);
			}
		}

		dp[1][2][0] = 1;

		for (int i = 1; i <= N; i++) {
			for (int j = i == 1 ? 3 : 1; j <= N; j++) {
				if (arr[i][j] == '0') {
					// 현 위치 파이프 모양이 가로일 때
					dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];

					// 현 위치 파이프 모양이 세로일 때
					dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];

					if(arr[i-1][j]=='1'||arr[i][j-1]=='1') continue;
					// 현 위치 파이프 모양이 대각선일 때
					dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
				}
			}
		}

		int answer = dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
		System.out.println(answer);
	}
}