import java.io.*;
import java.util.*;

public class Solution {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc<=T;tc++) {
			sb.append("#").append(tc).append(" ");
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			
			Set<String> s = new HashSet<>();
			st = new StringTokenizer(br.readLine());
			for(int i = 0;i<N;i++) {
				s.add(st.nextToken());
			}
			
			int answer = 0;
			
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i<M;i++) {
				String str = st.nextToken();
				if(s.contains(str))
					answer++;
			}
			sb.append(answer).append("\n");
		}
		System.out.println(sb);
	}
}