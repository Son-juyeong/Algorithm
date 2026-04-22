import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());
		Queue<Integer> q = new PriorityQueue<>(new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				if (Math.abs(o1) == Math.abs(o2))
					return o1 - o2;
				return Math.abs(o1) - Math.abs(o2);
			}

		});
		for (int i = 0; i < N; i++) {
			int x = Integer.parseInt(br.readLine());
			switch (x) {
			case 0:
				if (q.isEmpty())
					sb.append(0).append("\n");
				else
					sb.append(q.poll()).append("\n");
				break;
			default:
				q.offer(x);
				break;
			}
		}
		System.out.println(sb);
	}
}