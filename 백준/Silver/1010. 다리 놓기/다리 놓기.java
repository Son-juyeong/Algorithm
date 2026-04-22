import java.io.*;
import java.util.*;

public class Main {

	static int[][] dp = new int[30][30];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i<30;i++) {
			for(int j = 0;j<=i;j++) {
				if(i==j||j==0)
					dp[i][j]=1;
				else
					dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
			}
		}
		
		int T = Integer.parseInt(br.readLine());
		for(int i = 0;i<T;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int K = Integer.parseInt(st.nextToken());
			sb.append(dp[K][N]).append("\n");
		}
		System.out.println(sb);
	}
}