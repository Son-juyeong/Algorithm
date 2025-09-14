import java.io.*;
import java.util.*;

public class Main {
	
	static class Pos{
		int x;
		int y;
		public Pos(int x, int y) {
			this.x=x;
			this.y=y;
		}
	}
	
	static Pos[] store;
	static boolean[] visited;
	static Pos start;
	static int n;
	
	static String answer;
	
	static void recur(int idx) {
		if(answer.equals("happy\n"))
			return;
		if(checkDistance(start, store[idx])) {
			answer = "happy\n";
			return;
		}
		if(visited[idx]) return;
		visited[idx]=true;
		for(int i = 0;i<n;i++) {
			if(!visited[i]&&checkDistance(store[idx], store[i])) {
				//visited[i]=true;
				recur(i);
			}
		}
	}
	
	static boolean checkDistance(Pos p1, Pos p2) {
		return Math.abs(p1.x-p2.x)+Math.abs(p1.y-p2.y)<=1000;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int t = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= t; tc++) {
			n = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			
			start = new Pos(x, y);
			store = new Pos[n];
			visited = new boolean[n];
			for(int i = 0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				x = Integer.parseInt(st.nextToken());
				y = Integer.parseInt(st.nextToken());
				store[i]=new Pos(x, y);
			}
			
			st = new StringTokenizer(br.readLine());
			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());
			answer = "sad\n";
			
			final Pos end = new Pos(x, y);
			
			Arrays.sort(store, new Comparator<Pos>() {

				@Override
				public int compare(Pos o1, Pos o2) {
					// TODO Auto-generated method stub
					int dis1 =Math.abs(o1.x-end.x)+Math.abs(o1.y-end.y);
					int dis2 = Math.abs(o2.x-end.x)+Math.abs(o2.y-end.y);
					return dis1-dis2;
				}
			});
			
			if(checkDistance(start, end)) {
				sb.append("happy\n");
				continue;
			}
			
			for(int i = 0;i<n;i++) {
				if(checkDistance(end, store[i])) {
					recur(i);
				}	
				else break;
			}
			sb.append(answer);
		}
		System.out.println(sb);
	}
}