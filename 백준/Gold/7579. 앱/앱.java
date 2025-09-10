import java.io.*;
import java.util.*;


public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		int sumMemory = 0;
		int sumC = 0;
		
		int[] memory = new int[N];
		int[] c = new int[N];
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0;i<N;i++) {
			memory[i] = Integer.parseInt(st.nextToken());
			sumMemory+=memory[i];
		}
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0;i<N;i++) {
			c[i] = Integer.parseInt(st.nextToken());
			sumC +=c[i];
		}
		
		int unMemory = sumMemory-M;
		
		int[] dp = new int[unMemory+1];
		
		for(int i = 0;i<N;i++) {
			int m = memory[i];
			for(int j = unMemory;j>=m;j--) {
				dp[j] = Math.max(dp[j], dp[j-m]+c[i]);
			}
		}
		
		System.out.println(sumC-dp[unMemory]);
	}
}