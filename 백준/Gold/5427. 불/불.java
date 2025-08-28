import java.util.*;
import java.io.*;

public class Main {
	
	static class Node{
		char ch;
		int r;
		int c;
		int time;
		public Node(char ch, int r, int c, int time) {
			this.ch=ch;
			this.r=r;
			this.c=c;
			this.time=time;
		}
	}
	
	static int[] dr = {-1, 0, 1, 0};
	static int[] dc = {0, 1, 0, -1};
	
	static char[][] arr;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		
		for(int tc=1;tc<=T;tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int w = Integer.parseInt(st.nextToken());
			int h = Integer.parseInt(st.nextToken());
			
			arr = new char[h][w];
			
			Queue<Node> q = new ArrayDeque<>();
			int sr = -1, sc = -1;
			
			for(int i=0;i<h;i++) {
				String str = br.readLine();
				for(int j=0;j<w;j++) {
					arr[i][j]=str.charAt(j);
					if(arr[i][j]=='*') {
						q.offer(new Node(arr[i][j], i, j, 0));
					}
					else if(arr[i][j]=='@') {
						sr=i; sc=j;
					}
				}
			}
			
			int answer = Integer.MAX_VALUE;
			q.offer(new Node('@', sr, sc, 0));
			while(!q.isEmpty()) {
				Node cur = q.poll();
				for(int i=0;i<4;i++) {
					int r = cur.r+dr[i];
					int c = cur.c+dc[i];
					if(r>=0&&r<h&&c>=0&&c<w) {
						if(cur.ch=='*') {
							if(arr[r][c]=='.'||arr[r][c]=='@'||arr[r][c]=='!') {
								arr[r][c]='*';
								q.offer(new Node('*', r, c, cur.time+1));
							}
						}
						else {
							if(arr[r][c]=='.') {
								arr[r][c]='@';
								q.offer(new Node('@', r, c, cur.time+1));
								if(arr[cur.r][cur.c]=='@')
									arr[cur.r][cur.c]='!';
							}
						}
					}
					else {
						if(cur.ch=='@') {
							answer=cur.time+1;
							break;
						}
					}
				}
				if(answer!=Integer.MAX_VALUE) break;
			}
			sb.append(answer==Integer.MAX_VALUE?"IMPOSSIBLE":answer).append("\n");
		}
		System.out.println(sb);
	}
}