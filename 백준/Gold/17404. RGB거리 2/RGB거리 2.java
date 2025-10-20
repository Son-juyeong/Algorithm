import java.io.*;
import java.util.*;

public class Main {

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[][] arr = new int[N+1][3];
		for (int i = 1; i <= N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 3; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		int[] answer = new int[3];

		for (int i = 0; i < 3; i++) {
			int[][] dp = new int[N+1][3];
			dp[1][i]=arr[1][i];
			dp[2][(i+1)%3]=arr[2][(i+1)%3]+dp[1][i];
			dp[2][(i+2)%3]=arr[2][(i+2)%3]+dp[1][i];
			dp[2][i]=2001;
			for (int j = 3; j <= N; j++) {
				for(int k = 0;k<3;k++) {
					dp[j][k] = arr[j][k];
					dp[j][k] += Math.min(dp[j-1][(k+1)%3], dp[j-1][(k+2)%3]);
				}
			}
			answer[i]=Math.min(dp[N][(i+1)%3], dp[N][(i+2)%3]);
		}
		
		System.out.println(Math.min(Math.min(answer[0], answer[1]), answer[2]));
	}
}