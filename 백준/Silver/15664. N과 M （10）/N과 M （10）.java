import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	public static int N;
	public static int M;
	public static List<Integer> input;
	public static int[] numbers;
	public static List<Integer[]> preNumbers;

	public static void dfs(int depth, int start) {
		if (depth == M) {
			boolean b = true;
			if (preNumbers.size() != 0) {
				for (int i = 0; i < preNumbers.size(); i++) {
					int cnt = 0;
					for (int j = 0; j < M; j++) {
						if (numbers[j] == (preNumbers.get(i))[j])
							cnt++;
					}
					if (cnt == M) {
						b = false;
						break;
					}
				}
			}
			if (b) {
				preNumbers.add(new Integer[M]);
				int idx = preNumbers.size() - 1;
				for (int i = 0; i < M; i++) {
					System.out.print(numbers[i] + " ");
					preNumbers.get(idx)[i] = numbers[i];
				}
				System.out.println();
			}
			return;
		}
		for (int i = start; i < N; i++) {
			numbers[depth] = input.get(i);
			dfs(depth + 1, i + 1);
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		input = new LinkedList();
		numbers = new int[M];
		preNumbers = new LinkedList<>();
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			input.add(Integer.parseInt(st.nextToken()));
		}
		Collections.sort(input);
		dfs(0, 0);
	}
}