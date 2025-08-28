import java.util.*;
import java.io.*;

public class Main {
	
	static class Node implements Comparable<Node>{
		int r;
		int c;
		int w;
		public Node(int r, int c, int w) {
			this.r=r;
			this.c=c;
			this.w=w;
		}
		@Override
		public int compareTo(Node o) {
			return this.w-o.w;
		}
	}
	
	static int[] dr = {-1, 0, 1, 0};
	static int[] dc = {0, 1, 0, -1};
	static int[][] arr;
	static int[][] weight;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st= new StringTokenizer(br.readLine());
		int M = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		
		if(M==1&&N==1) {
			System.out.println(0);
			return;
		}
		
		arr = new int[N][M];
		weight = new int[N][M];
		
		for(int i=0;i<N;i++) {
			Arrays.fill(weight[i], Integer.MAX_VALUE);
			String str = br.readLine();
			for(int j=0;j<M;j++) {
				arr[i][j]=str.charAt(j)-'0';
			}
		}
		
		Queue<Node> q = new PriorityQueue<>();
		
		weight[0][0]=0;
		q.offer(new Node(0,0,0));
		while(!q.isEmpty()) {
			Node cur = q.poll();
			if(cur.w>weight[cur.r][cur.c]) continue;
			for(int i=0;i<4;i++) {
				int r = cur.r+dr[i];
				int c = cur.c+dc[i];
				if(r>=0&&r<N&&c>=0&&c<M&&cur.w+arr[r][c]<weight[r][c]) {
					weight[r][c]=cur.w+arr[r][c];
					if(r==N-1&&c==M-1) {
						System.out.println(weight[r][c]);
						return;
					}
					q.offer(new Node(r, c, weight[r][c]));
				}
			}
		}
	}
}