import java.io.*;
import java.util.*;

public class Main {

	static class Node {
		int r;
		int c;
		int k;
		int cnt;

		public Node(int r, int c, int k, int cnt) {
			this.r = r;
			this.c = c;
			this.k = k;
			this.cnt = cnt;
		}
	}

	static int K;
	static int W, H;

	static int[] dr = { -1, 0, 1, 0 };
	static int[] dc = { 0, 1, 0, -1 };

	static int[] horseDr = { -2, -1, 1, 2, 2, 1, -1, -2 };
	static int[] horseDc = { 1, 2, 2, 1, -1, -2, -2, -1 };

	static int[][] arr;

	static boolean[][][] visited;

	public static int bfs() {
		if(W==1&&H==1) return 0;
		int endR = H - 1, endC = W - 1;
		Queue<Node> q = new ArrayDeque<>();
		q.offer(new Node(0, 0, 0, 0));
		while (!q.isEmpty()) {
			Node cur = q.poll();
			int cnt = cur.cnt;
			int k = cur.k;
			if (cur.k < K) {
				for (int i = 0; i < 8; i++) {
					int r = cur.r + horseDr[i];
					int c = cur.c + horseDc[i];
					if (r >= 0 && r < H && c >= 0 && c < W && arr[r][c] == 0 && !visited[r][c][k + 1]) {
						if (r == endR && c == endC) {
							return cnt + 1;
						}
						visited[r][c][k + 1] = true;
						q.offer(new Node(r, c, k + 1, cnt + 1));
					}
				}
			}
			for (int i = 0; i < 4; i++) {
				int r = cur.r + dr[i];
				int c = cur.c + dc[i];
				if (r >= 0 && r < H && c >= 0 && c < W && arr[r][c] == 0 && !visited[r][c][k]) {
					if (r == endR && c == endC) {
						return cnt + 1;
					}
					visited[r][c][k] = true;
					q.offer(new Node(r, c, k, cnt + 1));
				}
			}
		}
		return -1;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		K = Integer.parseInt(br.readLine());

		StringTokenizer st = new StringTokenizer(br.readLine());

		W = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());

		arr = new int[H][W];
		visited = new boolean[H][W][K+1];
		for (int i = 0; i < H; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < W; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		System.out.println(bfs());
	}
}