import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static int[][] arr;
	public static int[][] distance;
	public static int[] dr = { -1, 0, 1, 0 };
	public static int[] dc = { 0, 1, 0, -1 };
	public static List<Integer[]> list;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());

		int tc = 1;

		while (N != 0) {
			arr = new int[N][N];
			distance = new int[N][N];

			for (int i = 0; i < N; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
					distance[i][j] = Integer.MAX_VALUE;
				}
			}

			Queue<Integer[]> pq = new PriorityQueue<>((v1, v2) -> v1[2] - v2[2]);
			pq.offer(new Integer[] { 0, 0, arr[0][0] });

			while (!pq.isEmpty()) {
				Integer[] node = pq.poll();
				int currentR = node[0];
				int currentC = node[1];
				if (node[2] > distance[currentR][currentC])
					continue;

				for (int i = 0; i < 4; i++) {
					int newR = currentR + dr[i];
					int newC = currentC + dc[i];
					if (newR >= 0 && newR < N && newC >= 0 && newC < N
							&& distance[newR][newC] > node[2] + arr[newR][newC]) {
						int newDis = node[2] + arr[newR][newC];
						distance[newR][newC] = newDis;
						if (newR == N - 1 && newC == N - 1)
							break;
						pq.offer(new Integer[] { newR, newC, newDis });
					}
				}
				if (distance[N - 1][N - 1] != Integer.MAX_VALUE)
					break;
			}
			sb.append("Problem ").append(tc++).append(": ").append(distance[N - 1][N - 1]).append("\n");
			N = Integer.parseInt(br.readLine());
		}
		System.out.println(sb);
	}
}