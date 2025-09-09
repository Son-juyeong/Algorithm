import java.io.*;
import java.util.*;

public class Main {

	static char[][] arr;
	static boolean[][][] visited;
	
	static int N, M;
	
	static int[] dr = {-1, 0, 1, 0};
	static int[] dc = {0, 1, 0, -1};
	
	static class Node{
		int r;
		int c;
		int d;
		int bool;
		
		public Node(int r, int c, int d, int bool) {
			this.r=r;
			this.c=c;
			this.d=d;
			this.bool=bool;
		}
	}
	
	public static int BFS() {
		if(N==1&&M==1)
			return 1;
		
		Queue<Node> q = new ArrayDeque<>();
		q.offer(new Node(0, 0, 1, 0));
		
		while(!q.isEmpty()) {
			Node cur = q.poll();
			
			for(int i = 0;i<4;i++) {
				int r = cur.r+dr[i];
				int c = cur.c+dc[i];
				if(r>=0&&r<N&&c>=0&&c<M&&!visited[r][c][cur.bool]) {
					if(r==N-1&&c==M-1)
						return cur.d+1;
					if(arr[r][c]=='0') {
						visited[r][c][cur.bool]=true;
						q.offer(new Node(r, c, cur.d+1, cur.bool));
					}
						
					else {
						if(cur.bool==0) {
							visited[r][c][1]=true;
							q.offer(new Node(r, c, cur.d+1, 1));
						}
					}
				}
			}
		}
		
		return -1;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		arr = new char[N][M];
		visited = new boolean[N][M][2];
		
		for(int i = 0;i<N;i++) {
			String str = br.readLine();
			for(int j = 0;j<M;j++) {
				arr[i][j] = str.charAt(j);
			}
		}
		
		System.out.println(BFS());
	}
}