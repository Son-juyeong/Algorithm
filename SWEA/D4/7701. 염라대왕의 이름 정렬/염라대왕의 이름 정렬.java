import java.io.*;
import java.util.*;

public class Solution {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc<=T;tc++) {
			sb.append("#").append(tc).append("\n");
			int n = Integer.parseInt(br.readLine());
			Set<String> s = new TreeSet<>((a, b)->{
				if (a.length() == b.length()) return a.compareTo(b);
                return a.length() - b.length();
			}) ;
			for(int i = 0; i<n;i++) {
				String str = br.readLine();
				s.add(str);
			}
			Iterator<String> iter = s.iterator();
			while(iter.hasNext()) {
				sb.append(iter.next()).append("\n");
			}
		}
		System.out.println(sb);
	}
}