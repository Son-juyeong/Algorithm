import java.io.*;
import java.util.*;

public class Main {

	public static int answer = Integer.MAX_VALUE;
	public static int arrSour[];
	public static int arrAcerbity[];
	public static int N;
	
	public static void dfs(int depth, int sour, int acerbity) {
		if(depth==N) {
			if(sour==0||acerbity==0) return;
			answer = Math.min(Math.abs(sour-acerbity), answer);
			return;
		}
		dfs(depth+1, sour*arrSour[depth], acerbity+arrAcerbity[depth]);
		dfs(depth+1, sour, acerbity);
	}
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		N = Integer.parseInt(br.readLine());
		arrSour = new int[N];
		arrAcerbity = new int[N];
		for(int i = 0;i<N;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			arrSour[i]=Integer.parseInt(st.nextToken());
			arrAcerbity[i]=Integer.parseInt(st.nextToken());
		}
		dfs(0, 1, 0);
		System.out.println(answer);
	}
}