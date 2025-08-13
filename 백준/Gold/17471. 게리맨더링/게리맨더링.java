import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

	public static int[] population;
	public static int totalPopulation;
	public static List<Integer>[] list;
	public static int N;
	public static int answer = Integer.MAX_VALUE;

	public static int dfs(int a, boolean[] visited) {
		visited[a] = true;
		int sum = population[a];
		for (int i = 0; i < list[a].size(); i++) {
			if (!visited[list[a].get(i)]) {
				sum += dfs(list[a].get(i), visited);
			}
		}
		return sum;
	}

	public static void dfs2(int a, boolean[] visited, boolean[] arr) {
		visited[a] = true;
		for (int i = 0; i < list[a].size(); i++) {
			if (!visited[list[a].get(i)] && arr[list[a].get(i)]) {
				dfs2(list[a].get(i), visited, arr);
			}
		}
	}

	public static void combi(int start, int depth, int cnt, boolean[] arr) {
		if (depth == cnt) {
			boolean[] visited1 = new boolean[N + 1];
			boolean[] visited2 = new boolean[N + 1];

			boolean[] arr2 = new boolean[N + 1];
			for (int i = 1; i <= N; i++) {
				if (!arr[i])
					arr2[i] = true;
			}

			boolean b1 = false, b2 = false;
			for (int i = 1; i <= N; i++) {
				if (arr[i] && !b1) {
					dfs2(i, visited1, arr);
					b1 = true;
				} else if (arr2[i] && !b2) {
					dfs2(i, visited2, arr2);
					b2 = true;
				}
				if (b1 && b2)
					break;
			}

			int sum = 0;
			for (int i = 1; i <= N; i++) {
				if (!arr[i] && !visited2[i])
					return;
				if (arr[i] && !visited1[i])
					return;
				if (arr[i] && visited1[i])
					sum += population[i];
			}

			answer = Math.min(answer, Math.abs(sum * 2 - totalPopulation));
			return;
		}
		for (int i = start; i <= N; i++) {
			arr[i] = true;
			combi(i + 1, depth + 1, cnt, arr);
			arr[i] = false;
		}
	}

	public static int[] parents;

	public static void makeSet() {

		parents = new int[N + 1];

		for (int i = 1; i <= N; i++) {
			parents[i] = i;
		}
	}

	public static int findSet(int a) {
		if (parents[a] == a) {
			return a;
		}
		return parents[a] = findSet(parents[a]);
	}

	public static void union(int a, int b) {
		int aRoot = findSet(a);
		int bRoot = findSet(b);
		if (aRoot == bRoot)
			return;
		if (aRoot < bRoot)
			parents[aRoot] = bRoot;
		else
			parents[bRoot] = aRoot;
	}

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		population = new int[N + 1];
		list = new ArrayList[N + 1];

		makeSet();

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; i++) {
			int p = Integer.parseInt(st.nextToken());
			population[i] = p;
			totalPopulation += p;
			list[i] = new ArrayList<>();
		}

		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			for (int j = 0; j < n; j++) {
				list[i].add(Integer.parseInt(st.nextToken()));
				union(i, list[i].get(j));
			}
		}

		Set<Integer> s = new HashSet<>();
		s.add(findSet(1));
		for (int i = 2; i <= N; i++) {
			if (!s.contains(findSet(i)))
				s.add(findSet(i));
		}

		if (s.size() > 2) {
			System.out.println(-1);
		} else if (s.size() == 2) {
			int p = dfs(1, new boolean[N + 1]);
			int p2 = totalPopulation - p;
			System.out.println(Math.abs(p - p2));

		} else {
			for (int i = 1; i < N; i++) {
				combi(1, 0, i, new boolean[N + 1]);
			}
			System.out.println(answer);
		}
	}
}