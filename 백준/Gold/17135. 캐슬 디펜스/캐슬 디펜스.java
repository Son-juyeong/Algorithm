import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static int[][] arr;
	public static int n;
	public static int m;
	public static int d;
	public static int answer;
	public static int[] selectList = new int[3];
	public static int[] dr = { 0, -1, 0 };
	public static int[] dc = { -1, 0, 1 };

	static class Pair {
		int r;
		int c;

		public Pair(int r, int c) {
			this.r = r;
			this.c = c;
		}
	}

	public static void dfs(int depth, int start) {
		if (depth == 3) {
			game();
			return;
		}
		for (int i = start; i < m; i++) {
			selectList[depth] = i;
			dfs(depth + 1, i + 1);
		}
	}

	public static void game() {
		boolean[][] attacked = new boolean[n][m];
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			boolean[][] enemy = new boolean[n][m];
			List<Pair> list = new LinkedList<>();
			for (int j = 0; j < 3; j++) {
				int r = n - i;
				int c = selectList[j];
				boolean[][] visited = new boolean[n][m];
				Queue<Pair> q = new LinkedList();
				q.add(new Pair(r, c));
				while (!q.isEmpty()) {
					Pair p = q.remove();
					if (Math.abs(p.r - r) + Math.abs(p.c - c) > d)
						break;
					if (p.r >= 0 && p.r < r && p.c >= 0 && p.c < m && arr[p.r][p.c] == 1) {
						if (!attacked[p.r][p.c]) {
							if (!enemy[p.r][p.c]) {
								enemy[p.r][p.c] = true;
								list.add(new Pair(p.r, p.c));
								cnt++;
							}
							break;
						}
					}
					for (int k = 0; k < 3; k++) {
						int tr = p.r + dr[k];
						int tc = p.c + dc[k];
						if (tr >= 0 && tr < r && tc >= 0 && tc < m) {
							if (!visited[tr][tc]) {
								visited[tr][tc] = true;
								q.add(new Pair(tr, tc));
							}
						}
					}
				}
			}
			for (int j = 0; j < list.size(); j++) {
				attacked[list.get(j).r][list.get(j).c] = true;
			}
		}
		answer = Math.max(answer, cnt);
	}

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());

		arr = new int[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		dfs(0, 0);
		System.out.println(answer);
	}
}