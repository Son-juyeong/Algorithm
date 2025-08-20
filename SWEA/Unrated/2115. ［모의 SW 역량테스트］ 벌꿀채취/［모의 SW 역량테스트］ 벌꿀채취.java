import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {

	public static int N;
	public static int[][] arr;
	public static int[][] income;
	public static int M;
	public static int C;
	public static int answer;

	public static int dfs(int depth, int start, int[] tempArr, int cnt, int sum, int quantity) {
		if (depth == cnt)
			return sum;
		int temp = sum;
		for (int i = start; i < tempArr.length; i++) {
			if (quantity + tempArr[i] > C)
				continue;
			temp = Math.max(temp,
					dfs(depth + 1, i + 1, tempArr, cnt, sum + tempArr[i] * tempArr[i], quantity + tempArr[i]));
		}
		return temp;
	}

	public static void getAnswer(int r, int c, int sum, int depth) {
		if (depth == 2) {
			answer = Math.max(answer, sum);
			return;
		}
		for (int i = r; i < N; i++) {
			for (int j = i == r ? c : 0; j <= N - M; j++) {
				getAnswer(i, j + M, sum + income[i][j], depth + 1);
			}
		}
	}

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= T; tc++) {

			answer = Integer.MIN_VALUE;

			sb.append("#").append(tc).append(" ");

			StringTokenizer st = new StringTokenizer(br.readLine());

			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			C = Integer.parseInt(st.nextToken());

			arr = new int[N][N];
			income = new int[N][N];

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
					income[i][j] = Integer.MIN_VALUE;
				}
			}

			// 벌통 수익 채우기
			for (int i = 0; i < N; i++) {
				for (int j = 0; j <= N - M; j++) {
					int[] tempArr = Arrays.copyOfRange(arr[i], j, j + M);
					for (int k = 1; k <= M; k++) {
						income[i][j] = dfs(0, 0, tempArr, k, 0, 0);
					}
				}
			}

			getAnswer(0, 0, 0, 0);

			sb.append(answer).append("\n");
		}
		System.out.println(sb);
	}
}