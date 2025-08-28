import java.util.*;
import java.io.*;

public class Main {

	static int[][][] arr;
	
	static int[] dx = {0, 1, 0, -1, 0, 0};
	static int[] dy = {-1, 0, 1, 0, 0, 0};
	static int[] dz = {0, 0, 0, 0, 1, -1};
	
	static class Node{
		int x;
		int y;
		int h;
		int d;
		public Node(int x, int y, int h, int d) {
			this.x=x;
			this.y=y;
			this.h=h;
			this.d=d;
		}
	}
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int M = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		int H = Integer.parseInt(st.nextToken());
		
		arr = new int[N][M][H];
		
		int cnt = 0;
		int answer = -1;
		
		Queue<Node> q = new ArrayDeque<>();
		
		for(int i=0;i<H;i++) {
			for(int j=0;j<N;j++) {
				st = new StringTokenizer(br.readLine());
				for(int k=0;k<M;k++) {
					int t = Integer.parseInt(st.nextToken());
					arr[j][k][i]=t;
					if(t==1) {
						q.offer(new Node(k, j, i, 0));
					}
					else if(t==0) {
						cnt++;
					}
				}
			}
		}
		if(cnt==0) {
			System.out.println(0);
			return;
		}
		while(!q.isEmpty()) {
			Node cur = q.poll();
			for(int i=0;i<6;i++) {
				int x = cur.x+dx[i];
				int y = cur.y+dy[i];
				int h = cur.h+dz[i];
				if(x>=0&&x<M&&y>=0&&y<N&&h>=0&&h<H&&arr[y][x][h]==0) {
					arr[y][x][h]=1;
					cnt--;
					if(cnt==0) {
						answer=cur.d+1;
						break;
					}
					q.offer(new Node(x, y, h, cur.d+1));
				}
			}
			if(answer!=-1) break;
		}
		System.out.println(answer);
	}
}