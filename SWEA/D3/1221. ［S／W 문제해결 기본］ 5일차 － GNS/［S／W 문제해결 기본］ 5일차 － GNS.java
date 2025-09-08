import java.io.*;
import java.util.*;

public class Solution {

	static Map<String, Integer> stoi = new HashMap<String, Integer>() {
		{
			put("ZRO", 0);
			put("ONE", 1);
			put("TWO", 2);
			put("THR", 3);
			put("FOR", 4);
			put("FIV", 5);
			put("SIX", 6);
			put("SVN", 7);
			put("EGT", 8);
			put("NIN", 9);
		}

	};

	static Map<Integer, String> itos = new HashMap<Integer, String>() {
		{
			put(0, "ZRO");
			put(1, "ONE");
			put(2, "TWO");
			put(3, "THR");
			put(4, "FOR");
			put(5, "FIV");
			put(6, "SIX");
			put(7, "SVN");
			put(8, "EGT");
			put(9, "NIN");
		}

	};
	
	static int[] cnt;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= T; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String test_case = st.nextToken();
			int n = Integer.parseInt(st.nextToken());
			
			sb.append(test_case).append("\n");
			
			cnt = new int[10];
			
			st = new StringTokenizer(br.readLine());
			for(int i = 0;i<n;i++) {
				int idx = stoi.get(st.nextToken());
				cnt[idx]++;
			}
			
			for(int i = 0;i<10;i++) {
				for(int j = 0;j<cnt[i];j++) {
					sb.append(itos.get(i)).append(" ");
				}
			}
			sb.append("\n");
		}
		
		System.out.println(sb);
	}

}