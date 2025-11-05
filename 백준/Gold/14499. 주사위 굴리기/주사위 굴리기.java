import java.io.*;
import java.util.*;

public class Main {

	static int[] dr = { 0, 0, 0, -1, 1 };
	static int[] dc = { 0, 1, -1, 0, 0 };

	static int[] dice = { 0, 0, 0, 0, 0, 0, 0 };
	static int[] newDir = { 0, 2, 1, 4, 3 };

	static int[][] dicePos = { { 0, 2, 0, 0 }, { 4, 1, 3, 6 }, { 0, 5, 0, 0 }, { 0, 6, 0, 0 } };

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		int[][] map = new int[N][M];

		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());

		int K = Integer.parseInt(st.nextToken());

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		for (int i = 0; i < K; i++) {
			int dir = Integer.parseInt(st.nextToken());
			x += dr[dir];
			y += dc[dir];
			int[][] temp = new int[4][4];
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					temp[j][k] = dicePos[j][k];
				}
			}
			if (x >= 0 && x < N && y >= 0 && y < M) {
				if (dir <= 2) {
					for (int j = 0; j < 4; j++) {
						dicePos[1][j] = temp[1][(4 + j - dc[dir]) % 4];
					}
					dicePos[3][1] = dicePos[1][3];
				} else {

					for (int j = 0; j < 4; j++) {
						dicePos[j][1] = temp[(4 + j - dr[dir]) % 4][1];
					}
					dicePos[1][3] = dicePos[3][1];
				}

				if (map[x][y] != 0) {
					dice[dicePos[3][1]] = map[x][y];
					map[x][y] = 0;
				} else {
					map[x][y] = dice[dicePos[3][1]];
				}

				sb.append(dice[dicePos[1][1]]).append("\n");

			} else {
				x -= dr[dir];
				y -= dc[dir];
			}
		}
		System.out.println(sb);
	}
}